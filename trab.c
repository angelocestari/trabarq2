#include "trab.h"

void printMemory(byte *memory) {
    for (int i = 0; i <= 0x3ff0; i += 16) {
        printf("Mem[0x%08x]\t", i);
        printf("0x%08x\t", *(word*)&memory[i]); 
        printf("0x%08x\t", *(word*)&memory[i+4]); 
        printf("0x%08x\t", *(word*)&memory[i+8]); 
        printf("0x%08x\t\n", *(word*)&memory[i+12]); 
    }
}

void printBinary(int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        if (((unsigned int)num >> i) & 1)
            printf("1");
        else
            printf("0");
    }
}

void printRegisters(word registers[]){
    for (int i = 0; i < 32; i += 1) {
        printf("$%d\t0x%08x\n", i, registers[i]); 
    }
}

bool validDataAdress(word memoryAdress) {
    if(memoryAdress >= 0x2000) {
        return true;
    } else {
        return false;
    }
}

void syscall(word instruction, word registers[], word specialRegisters[], byte memory[]){
    byte rs, rt, rd, shamt, funct;
    word address;
    char str[registers[5]]; // $a1
    char character;

    rs = ((instruction & (0x1f << 21)) >> 21) & 0x1f;
    rt = ((instruction & (0x1f << 16)) >> 16) & 0x1f;
    rd = ((instruction & (0x1f << 11)) >> 11) & 0x1f;
    shamt = ((instruction & (0x1f << 6)) >> 6) & 0x1f;
    funct = instruction & 0x3f;
    
    switch(registers[2]) // $v0
    {
        case 1: // print integer
            printf("%d", registers[4]);
            break;
        case 4: // print string
            address = registers[4];
            printf("%s", (char*)&memory[address]);
            break;
        case 5: // read integer
            scanf("%d", &registers[2]);
            break;
        case 8: // read string
            fgets((char*)&memory[registers[4]], sizeof(str), stdin);
            break;
        case 10: // exit
            printf("\n");
            printRegisters(registers);
            printMemory(memory);
            exit(0);
            break;
        case 11: // print character
            printf("%c", registers[4]);
            break;
        case 12: // read character
            character = getchar();
            registers[2] = (word)character;
            break;
        case 34: // print integer in hexadecimal
            printf("0x%08x", registers[4]);
            break;
        case 35: // print integer in binary
            printBinary(registers[4]);
            break;
        case 36: // print as unsigned
            printf("%u", (unsigned int)registers[4]);
            break;
        default:
            printf("\nERROR: Invalid syscall\n");
            printf("Line: %d\n", specialRegisters[0] / 4);
            exit(1);
    }
}

bool r_instru(word instruction, word registers[], word specialRegisters[], byte memory[]) {
    byte rs, rt, rd, shamt, funct;
    word address;

    rs = ((instruction & (0x1f << 21)) >> 21) & 0x1f;
    rt = ((instruction & (0x1f << 16)) >> 16) & 0x1f;
    rd = ((instruction & (0x1f << 11)) >> 11) & 0x1f;
    shamt = ((instruction & (0x1f << 6)) >> 6) & 0x1f;
    funct = instruction & 0x3f;


    switch (funct)
    {
    case 0x00: // sll - shift left logical
        if(instruction != 0x0) {
            registers[rd] = registers[rt] << shamt;
        }
        specialRegisters[0] += 4;
        return false;
    case 0x02: // srl - shift right logical
        registers[rd] = (unsigned int)registers[rt] >> shamt;
        specialRegisters[0] += 4;
        return false;

    case 0x3: // sra - shift right arithmetic
        registers[rd] = registers[rt] >> shamt;
        specialRegisters[0] += 4;
        return false;

    case 0x08: // jr - jump register
        specialRegisters[0] = registers[rs];
        return false;
    case 0xc: // syscall
        syscall(instruction, registers, specialRegisters, memory);
        specialRegisters[0] += 4;
        return false;
    case 0x10: // mfohi - move from high
        registers[rd] = specialRegisters[1];
        specialRegisters[0] += 4;
        return false;

    case 0x12: // mfolo - move from low
        registers[rd] = specialRegisters[2];
        specialRegisters[0] += 4;
        return false;

    case 0x18: // multi - multiply
        specialRegisters[1] = ((int64_t)(registers[rs] * registers[rs]) & ((int64_t)0xffffffff << 32)) >> 32;
        specialRegisters[2] = (int64_t)(registers[rs] * registers[rs]) & 0xffffffff;
        specialRegisters[0] += 4;
        return false;

    case 0x1a: // div - divide
        specialRegisters[1] = registers[rs] % registers[rt];
        specialRegisters[2] = registers[rs] / registers[rt];
        specialRegisters[0] += 4;
        return false;

    case 0x20: // add - add
        registers[rd] = registers[rs] + registers[rt];
        specialRegisters[0] += 4;
        return false;

    case 0x21: // addu - add unsigned
        registers[rd] = registers[rs] + registers[rt];
        specialRegisters[0] += 4;
        return false;

    case 0x22: // sub - substract
        registers[rd] = registers[rs] - registers[rt];
        specialRegisters[0] += 4;
        return false;

    case 0x23: // sub - substract unsigned
        registers[rd] = registers[rs] - registers[rt];
        specialRegisters[0] += 4;
        return false;

    case 0x24: // and - and
        registers[rd] = registers[rs] & registers[rt];
        specialRegisters[0] += 4;
        return false;

    case 0x25: // or - or 
        registers[rd] = registers[rs] | registers[rt];
        specialRegisters[0] += 4;
        return false;
    
    case 0x26: // xor - xor
        registers[rd] = registers[rs] ^ registers[rt];
        specialRegisters[0] += 4;
        return false;

    case 0x2a: // slt - set less than
        if(registers[rs] < registers[rt]) {
            registers[rd] = 1;
        } else {
            registers[rd] = 0;
        }
        specialRegisters[0] += 4;
        return false;

    default:
        return true;
    }
}

bool j_instru(word instruction, word registers[], word specialRegisters[]) {
    byte opcode;
    word address, fourPcBits;

    opcode = ((instruction & (0x3f << 26)) >> 26) & 0x3f;
    address = instruction & 0x3ffffff;

    switch (opcode) {
        case 0x2: // j - jump
            fourPcBits = ((specialRegisters[0] + 4) & (0xf << 28));
            specialRegisters[0] = fourPcBits | (address << 2);
            return false;
        case 0x3: // jal - jump and link
            registers[31] = specialRegisters[0] + 4;
            fourPcBits = ((specialRegisters[0] + 4) & (0xf << 28));
            specialRegisters[0] = fourPcBits | (address << 2);
            return false;
        default:
            return true;
    }
}

bool i_instru(word instruction, word registers[], word specialRegisters[], byte memory[]) {
    byte rs, rt, opcode;
    word branchAddr, zeroExtImm, signImm;
    immediate imm;

    opcode = ((instruction & (0x3f << 26)) >> 26) & 0x3f;
    rs = ((instruction & (0x1f << 21)) >> 21) & 0x1f;
    rt = ((instruction & (0x1f << 16)) >> 16) & 0x1f;
    imm = instruction & 0xffff;

    switch (opcode) {
        case 0x1: // bgez - branch on greater than or equal to zero
            if(rt == 1) {
                if(registers[rs] >= 0) {
                    branchAddr = imm << 2;
                    specialRegisters[0] = specialRegisters[0] + 4 + branchAddr;
                } else {
                    specialRegisters[0] = specialRegisters[0] + 4;
                }
                return false;
            } else {
                printf("\nERROR: Instruction - 0x%08x not found\n", instruction);
                printf("Line: %d\n", specialRegisters[0] / 4);
                exit(1);
            }
        case 0x4: // beq - branch on equal
            if(registers[rs] == registers[rt]) {
                branchAddr = imm << 2;
                specialRegisters[0] = specialRegisters[0] + 4 + branchAddr;
            } else {
                specialRegisters[0] = specialRegisters[0] + 4;
            }
            return false;
        case 0x5: // bnq - branch on not equal
            if(registers[rs] != registers[rt]) {
                branchAddr = imm << 2;
                specialRegisters[0] = specialRegisters[0] + 4 + branchAddr;
            } else {
                specialRegisters[0] = specialRegisters[0] + 4;
            }
            return false;
        case 0x8: // addi - add immediate
            registers[rt] = registers[rs] + (word)imm;
            specialRegisters[0] += 4;
            return false;
        case 0x9: // addiu - add immediate unsigned
            registers[rt] = registers[rs] + (word)imm;
            specialRegisters[0] += 4;
            return false;
        case 0xa: // slti - set less than immediate
            registers[rt] = (registers[rs] < (word)imm);
            specialRegisters[0] += 4;
            return false;
        case 0xc: // andi - and immediate
            zeroExtImm = (word)imm & 0xffff;
            registers[rt] = registers[rs] & zeroExtImm;
            specialRegisters[0] += 4;
            return false;
        case 0xd: // ori - or immediate
            zeroExtImm = (word)imm & 0xffff;
            registers[rt] = registers[rs] | zeroExtImm;
            specialRegisters[0] += 4;
            return false;
        case 0xf: // lui - load upper immediate
            registers[rt] = (word)(imm << 16);
            specialRegisters[0] += 4;
            return false;
        case 0x20: // lb - load byte
            signImm = imm;
            registers[rt] = memory[registers[rs] + signImm];
            specialRegisters[0] += 4;
            return false;
        case 0x21: // lh - load halfword
            signImm = imm;
            registers[rt] = *(immediate*)&memory[registers[rs] + signImm];
            specialRegisters[0] += 4;
            return false;
        case 0x23: // lw - load word
            signImm = imm;
            registers[rt] = *(word*)&memory[registers[rs] + signImm];
            specialRegisters[0] += 4;
            return false;
        case 0x24: // lbu - load byte unsigned
            signImm = imm;
            registers[rt] = 0x000000ff & memory[registers[rs] + signImm];
            specialRegisters[0] += 4;
            return false;
        case 0x25: // lhu - load half word unsigned
            signImm = imm;
            registers[rt] = 0x0000ffff & memory[registers[rs] + signImm];
            specialRegisters[0] += 4;
            return false;
        case 0x28: // sb - store byte
            if(validDataAdress(registers[rs] + imm)){
                memory[registers[rs] + imm] = registers[rt] & 0xff;
                specialRegisters[0] += 4;
            } else {
                printf("\nERROR: Invalid adress for sb\n");
                printf("Line: %d\n", specialRegisters[0] / 4);
                exit(1);
            }
            return false;
        case 0x29: // sh - store halfword         
            if(validDataAdress(registers[rs] + imm)){
                *(immediate*)&memory[registers[rs] + imm]= (immediate)(registers[rt] & 0xffff);
                specialRegisters[0] += 4;
            } else {
                printf("\nERROR: Invalid adress for sh\n");
                printf("Line: %d\n", specialRegisters[0] / 4);
                exit(1);
            }
            return false;
        case 0x2b: // sw - store word
            if(validDataAdress(registers[rs] + imm)){
                *(word*)&memory[registers[rs] + imm] = registers[rt];
                specialRegisters[0] += 4;
            } else {
                printf("\nERROR: Invalid adress for sw\n");
                printf("Line: %d\n", specialRegisters[0] / 4);
                exit(1);
            }
            return false;
        default:
            return true;
    }
}

long calcAddrLastInstr(FILE *fp) {
    fseek(fp, 0L, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    return fileSize;
}

void memoryAlocattion(FILE *fp, FILE *fp1, byte* memory, int sizeMemory){
    memset(memory, 0, sizeMemory);
    fread(memory, sizeof(byte), (sizeMemory / 4), fp);
    fread(&memory[0x2000], sizeof(byte), (sizeMemory / 4), fp1);
}

int main()
{
    FILE *fp = fopen("program_text.bin", "rb");
    FILE *fp1 = fopen("program_data.bin", "rb");
    word instrucao, opcode, param_r_instr;

    word registers[32] = {0};
    word specialRegisters[3] = {0};

    byte memory[4096 * 4];
    memoryAlocattion(fp, fp1, memory, sizeof(memory));
    
    registers[0];  // $zero 
    registers[1];  // $at  
    registers[2];  // $v0 
    registers[3];  // $v1 
    registers[4];  // $a0 
    registers[5];  // $a1 
    registers[6];  // $a2 
    registers[7];  // $a3 
    registers[8];  // $t0 
    registers[9];  // $t1 
    registers[10];  // $t2 
    registers[11];  // $t3 
    registers[12];  // $t4 
    registers[13];  // $t5 
    registers[14];  // $t6 
    registers[15];  // $t7 
    registers[16];  // $s0 
    registers[17];  // $s1 
    registers[18];  // $s2 
    registers[19];  // $s3 
    registers[20];  // $s4 
    registers[21];  // $s5 
    registers[22];  // $s6 
    registers[23];  // $s7 
    registers[24];  // $t8 
    registers[25];  // $s9 
    registers[26];  // $k0 
    registers[27];  // $k1 
    registers[28] = 0x1800;  // $gp 
    registers[29] = 0x3ffc;  // $sp 
    registers[30];  // $fp 
    registers[31];  // $ra 

    specialRegisters[0] =  0; // pc
    specialRegisters[1] =  0; // hi
    specialRegisters[2] =  0; // lo

    if (fp == NULL)
    {
        printf("\nERROR: It was not possible to read the text file\n");
        exit(1);
    } else if(fp1 == NULL)
    {
        printf("\nERROR: It was not possible to read the data file\n");
        exit(1);
    }
    
    long lastFileAdrr = calcAddrLastInstr(fp);

    for(;specialRegisters[0] <= 0x0fff && specialRegisters[0] < lastFileAdrr;) {

        if(registers[29] < 0x3000) {
            printf("\nERROR: Stack overflow\n");
            printf("Line: %d\n", specialRegisters[0] / 4);
            exit(1);
        }

        instrucao = *(word*)&memory[specialRegisters[0]];
        opcode = ((instrucao & (0x3f << 26)) >> 26) & 0x3f;
        switch (opcode)
        {
        case 0x0: // R format
            param_r_instr = instrucao & 0x3ffffff;
            if(r_instru(param_r_instr, registers, specialRegisters, memory)) {
                printf("\nERROR: R-Instruction - 0x%08x not found\n", instrucao);
                printf("Line: %d\n", specialRegisters[0] / 4);
                exit(1);
            }
            break;
        case 0x2: // jal - jump and link
        case 0x3: // j - jump
            if(j_instru(instrucao, registers, specialRegisters)){
                printf("\nERROR: J-Instruction - 0x%08x not found\n", instrucao);
                printf("Line: %d\n", specialRegisters[0] / 4);
                exit(1);
            }
            break;
        case 0x1: // bgez - branch on greater than or equal to zero
        case 0x4: // beq - branch on equal
        case 0x5: // bnq - branch on not equal
        case 0x8: // addi - add imemediate
        case 0x9: // addiu - add imm. unsigned
        case 0xa: // slti - set less than imm.
        case 0xc: // andi - and immediate
        case 0xd: // ori - or immediate
        case 0xf: // lui - load upper imm.
        case 0x20: // lb - load byte
        case 0x21: // lh - load halfword
        case 0x23: // lw - load word
        case 0x24: // lbu - load byte unsigned
        case 0x25: // lhu - load half word unsigned
        case 0x28: // sb - store byte
        case 0x29: // sh - store halfword
        case 0x2b: // sw - store word
            if(i_instru(instrucao, registers, specialRegisters, memory)){
                printf("\nERROR: I-Instruction - 0x%08x not found\n", instrucao);
                printf("Line: %d\n", specialRegisters[0] / 4);
                exit(1);
            }
            break;
        default:
            printf("\nERROR: Instruction - 0x%08x not found\n", instrucao);
            printf("Line: %d\n", specialRegisters[0] / 4);
            printf("PC: 0x%08x\n", specialRegisters[0]);
            exit(1);
        }
    }
    printf("\n");
    printRegisters(registers);
    printMemory(memory);

    fclose(fp);

    return 0;
}

