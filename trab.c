#include "trab.h"

bool validDataAdress(word memoryAdress) {
    // printf("Endereço: 0x%08x\n", memoryAdress);
    if(memoryAdress >= 0x2000 && memoryAdress <= 0x2fff) {
        return true;
    } else {
        return false;
    }
}

bool r_instru(word instruction, word registers[], word specialRegisters[]) {
    byte rs, rt, rd, shamt, funct;
    rs = ((instruction & (0x1f << 21)) >> 21) & 0x1f;
    rt = ((instruction & (0x1f << 16)) >> 16) & 0x1f;
    rd = ((instruction & (0x1f << 11)) >> 11) & 0x1f;
    shamt = ((instruction & (0x1f << 6)) >> 6) & 0x1f;
    funct = instruction & 0x3f;

    switch (funct)
    {
    case 0x00: // sll - shift left logical
        registers[rd] = registers[rs] << shamt;
        specialRegisters[0] += 4;
        return false;

    case 0x02: // srl - shift right logical
        registers[rd] = registers[rs] >> shamt;
        specialRegisters[0] += 4;
        return false;

    case 0x3: // sra - shift right arithmetic
        printf("sra(%d) %d, %d, %d, %d, \n", rs, rt, rd, shamt, funct);
        specialRegisters[0] += 4;
        return false;

    case 0x08: // jr - jump register
        specialRegisters[0] = registers[rs];
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

    case 0x22: // sub - substract
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

    case 0x2a: // slt - set less than
        if(registers[rs] <registers[rt]) {
            registers[rd] = 0x1;
        } else {
            registers[rd] = 0x0;
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
            specialRegisters[0] = fourPcBits + (address << 2);
            return false;
        case 0x3: // jal - jump and link
            registers[31] = specialRegisters[0] + 4;
            fourPcBits = ((specialRegisters[0] + 4) & (0xf << 28));
            specialRegisters[0] = fourPcBits + (address << 2);
            return false;
        default:
            return true;
    }
}

bool i_instru(word instruction, word registers[], word specialRegisters[], byte memory[]) {
    byte rs, rt, opcode;
    word branchAddr, signExtImm, zeroExtImm, loadLeft, storeLeft;
    immediate imm;
    opcode = ((instruction & (0x3f << 26)) >> 26) & 0x3f;
    rs = ((instruction & (0x1f << 21)) >> 21) & 0x1f;
    rt = ((instruction & (0x1f << 16)) >> 16) & 0x1f;
    imm = instruction & 0xffff;
    switch (opcode) {
        case 0x4: // beq - branch on equal
            if(registers[rs] == registers[rt]) {
                branchAddr = (((((imm & (0x1 << 15)) >> 15) & 0x1) * 0x3fff) << 18) + (imm << 2);
                specialRegisters[0] = specialRegisters[0] + 4 + branchAddr;
            } else {
                specialRegisters[0] = specialRegisters[0] + 4;
            }
            return false;
        case 0x5: // bnq - branch on not equal
            if(registers[rs] != registers[rt]) {
                branchAddr = (((((imm & (0x1 << 15)) >> 15) & 0x1) * 0x3fff) << 18) + (imm << 2);
                specialRegisters[0] = specialRegisters[0] + 4 + branchAddr;
            } else {
                specialRegisters[0] = specialRegisters[0] + 4;
            }
            return false;
        case 0x8: // addi - add immediate
            registers[rt] = registers[rs] + imm;
            specialRegisters[0] += 4;
            return false;
        case 0x9: // addiu - add immediate unsigned
            registers[rt] = registers[rs] + (unsigned)imm;
            specialRegisters[0] += 4;
            return false;
        case 0xa: // slti - set less than immediate
            signExtImm = ((((imm & (0x1 << 15)) >> 15) & 0x1) * 0xffff) + imm;
            registers[rt] = (registers[rs] < signExtImm);
            specialRegisters[0] += 4;
            return false;
        case 0xc: // andi - and immediate
            zeroExtImm = (word)imm;
            registers[rt] = registers[rs] & zeroExtImm;
            specialRegisters[0] += 4;
            return false;
        case 0xd: // ori - or immediate
            zeroExtImm = (word)imm;
            registers[rt] = registers[rs] | zeroExtImm;
            specialRegisters[0] += 4;
            return false;
        case 0xf: // lui - load upper immediate
            registers[rt] = (word)(imm << 16);
            specialRegisters[0] += 4;
            return false;
        case 0x20: // lb - load byte
            loadLeft = ((((imm & (0x1 << 15)) >> 15) & 0x1) * 0xffffff) << 8;
            signExtImm = ((((imm & (0x1 << 15)) >> 15) & 0x1) * 0xffff) + imm;
            if(validDataAdress(registers[rs] + signExtImm)) {
                registers[rt] = loadLeft + memory[registers[rs] + signExtImm];
                specialRegisters[0] += 4;
            } else {
                printf("\nERROR: Invalid adress for lb\n");
                exit(1);
            }
            return false;
        case 0x21: // lh - load halfword
            loadLeft = ((((imm & (0x1 << 15)) >> 15) & 0x1) * 0xffff) << 16;
            signExtImm = ((((imm & (0x1 << 15)) >> 15) * 0xffff) & 0x1) + imm;
            if(validDataAdress(registers[rs] + signExtImm)) {
                registers[rt] = loadLeft + *(immediate*)&memory[registers[rs] + signExtImm];
                specialRegisters[0] += 4;
            } else {
                printf("\nERROR: Invalid adress for lh\n");
                exit(1);
            }
            return false;
        case 0x23: // lw - load word
            signExtImm = ((((imm & (0x1 << 15)) >> 15) * 0xffff) & 0x1) + imm;
            if(validDataAdress(registers[rs] + signExtImm)){
                registers[rt] = *(word*)&memory[registers[rs] + signExtImm];
                specialRegisters[0] += 4;
            } else {
                printf("\nERROR: Invalid adress for lw\n");
                exit(1);
            }
            return false;
        case 0x28: // sb - store byte
            signExtImm = ((((imm & (0x1 << 15)) >> 15) * 0xffff) & 0x1) + imm;
            if(validDataAdress(registers[rs] + signExtImm)){
                memory[registers[rs] + signExtImm] = (byte)(registers[rt]);
                specialRegisters[0] += 4;
            } else {
                printf("\nERROR: Invalid adress for sb\n");
                exit(1);
            }
            return false;
        case 0x29: // sh - store halfword
            signExtImm = ((((imm & (0x1 << 15)) >> 15) * 0xffff) & 0x1) + imm;
            if(validDataAdress(registers[rs] + signExtImm)){
                *(immediate*)&memory[registers[rs] + signExtImm]= (immediate)registers[rt];
                specialRegisters[0] += 4;
            } else {
                printf("\nERROR: Invalid adress for sh\n");
                exit(1);
            }
            return false;
        case 0x2b: // sw - store word
            signExtImm = ((((imm & (0x1 << 15)) >> 15) * 0xffff) & 0x1) + imm;
            if(validDataAdress(registers[rs] + signExtImm)){
                *(word*)&memory[registers[rs] + signExtImm] = registers[rt];
                specialRegisters[0] += 4;
            } else {
                printf("\nERROR: Invalid adress for sw\n");
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

void printMemory(byte *memory) {
    for (int i = 0; i <= 0x3ff0; i += 16) {
        printf("Mem[0x%08x] ", i);
        printf("0x%08x\t", *(word*)&memory[i]); 
        printf("0x%08x\t", *(word*)&memory[i+4]); 
        printf("0x%08x\t", *(word*)&memory[i+8]); 
        printf("0x%08x\n", *(word*)&memory[i+12]); 
    }
}

void printRegisters(word registers[]){
    for (int i = 0; i < 32; i += 1) {
        printf("$%-2d\t0x%08x\n", i, registers[i]); 
    }
}

void print_binary(unsigned int n) {
    if (n > 1)
        print_binary(n >> 1);
    printf("%d", n & 1);
}

int main()
{
    FILE *fp = fopen("exemplo_text.bin", "rb");
    FILE *fp1 = fopen("exemplo_data.bin", "rb");
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
    registers[29] = 0x00003ffc;  // $sp 
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
            exit(1);
        }
        instrucao = *(word*)&memory[specialRegisters[0]];
        opcode = ((instrucao & (0x3f << 26)) >> 26) & 0x3f;
        // print_binary(opcode);
        // printf("\n");
        // print_binary(instrucao);
        // printf("\n");
        // printf("Opcode: %d\n", opcode);
        // printf("Instrução: \n0x%08x\n", instrucao);
        // printf("PC: \n0x%08x\n", specialRegisters[0]);
        // printf("========================================================\n");
        switch (opcode)
        {
        case 0x0: // R format
            param_r_instr = instrucao & 0x3ffffff;
            if(r_instru(param_r_instr, registers, specialRegisters)) {
                printf("\nERROR: R-Instruction - 0x%08x\n", instrucao);
                exit(1);
            }
            break;
        case 0x2: // jal - jump and link
        case 0x3: // j - jump
            if(j_instru(instrucao, registers, specialRegisters)){
                printf("\nERROR: J-Instruction - 0x%08x\n", instrucao);
                exit(1);
            }
            break;
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
        case 0x28: // sb - store byte
        case 0x29: // sh - store halfword
        case 0x2b: // sw - store word
            if(i_instru(instrucao, registers, specialRegisters, memory)){
                printf("\nERROR: I-Instruction - 0x%08x\n", instrucao);
                exit(1);
            }
            break;
        default:
            specialRegisters[0] += 4;
        }
    }
    printRegisters(registers);
    printMemory(memory);

    fclose(fp);

    //  OP     RS   RT    IMMEDIATE
    // ,--6-,,-5-,,-5-,,-------16-----, I
    // ,--6-,,-5-,,-5-,,-5-,,-5-,,--6-, R
    // ,--6-,,-----------26-----------, J
    // 11111100111111111011110100100011
    // 00000011111111111111111111111111

    

    return 0;
}

