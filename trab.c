#include "trab.h"

bool r_instru(word instruction, word *registers, word *specialRegisters) {
    registers[0] = 0x19;
    byte rs, rt, rd, shamt, funct;
    rs = (instruction & (0x1f << 21)) >> 21;
    rt = (instruction & (0x1f << 16)) >> 16;
    rd = (instruction & (0x1f << 11)) >> 11;
    shamt = (instruction & (0x1f << 6)) >> 6;
    funct = instruction & 0x3f;

    switch (funct)
    {
    case 0x00: // sll - shift left logical
        printf("sll(%d) %d, %d, %d, %d, \n", rs, rt, rd, shamt, funct);
        return false;

    case 0x02: // srl - shift right logical
        printf("srl(%d) %d, %d, %d, %d, \n", rs, rt, rd, shamt, funct);
        return false;

    case 0x3: // sra - shift right arithmetic
        printf("sra(%d) %d, %d, %d, %d, \n", rs, rt, rd, shamt, funct);
        return false;

    case 0x08: // jr - jump register
        printf("jr(%d) %d, %d, %d, %d, \n", rs, rt, rd, shamt, funct);
        return false;

    case 0x10: // mfohi - move from high
        printf("mfhi(%d) %d, %d, %d, %d, \n", rs, rt, rd, shamt, funct);
        return false;

    case 0x12: // mfolo - move from low
        printf("mflo(%d) %d, %d, %d, %d, \n", rs, rt, rd, shamt, funct);
        return false;

    case 0x18: // multi - multiply
        printf("multiply(%d) %d, %d, %d, , %d\n", rs, rt, rd, shamt, funct);
        return false;

    case 0x1a: // div - divide
        printf("divide(%d) %d, %d, %d, , %d\n", rs, rt, rd, shamt, funct);
        return false;

    case 0x20: // add - add
        printf("add(%d) %d, %d, %d, %d, \n", rs, rt, rd, shamt, funct);
        // registers[rd] = registers[rs];
        return false;

    case 0x22: // sub - substract
        printf("sub(%d) %d, %d, %d, %d, \n", rs, rt, rd, shamt, funct);
        return false;

    case 0x24: // and - and
        printf("and(%d) %d, %d, %d, %d, \n", rs, rt, rd, shamt, funct);
        return false;

    case 0x25: // or - or 
        printf("or(%d) %d, %d, %d, %d, \n", rs, rt, rd, shamt, funct);
        return false;

    case 0x2a: // slt - set less than
        printf("slt(%d) %d, %d, %d, %d, \n", rs, rt, rd, shamt, funct);
        return false;

    default:
        return true;
    }
}

bool j_instru(word instruction) {
    byte opcode;
    word address;
    opcode = (instruction & (0x3f << 26)) >> 26;
    address = instruction & 0x3ffffff;

    switch (opcode) {
        case 0x2: // j - jump
            printf("j(%d) %d\n", opcode, address);
            return false;
        case 0x3: // jal - jump and link
            printf("jal(%d) %d\n", opcode, address);
            return false;
        default:
            return true;
    }
}

bool i_instru(word instruction) {
    byte rs, rt, opcode;
    immediate imm;
    opcode = (instruction & (0x3f << 26)) >> 26;
    rs = (instruction & (0x1f << 21)) >> 21;
    rt = (instruction & (0x1f << 16)) >> 16;
    imm = instruction & 0xffff;

    switch (opcode) {
        case 0x4: // beq - branch on equal
            printf("beq(%d) %d %d %d\n", opcode, rs, rt, imm);
            return false;
        case 0x5: // bnq - branch on not equal
            printf("bnq(%d) %d %d %d\n", opcode, rs, rt, imm);
            return false;
        case 0x8: // addi - add immediate
            printf("addi(%d) %d %d %d\n", opcode, rs, rt, imm);
            return false;
        case 0x3: // addiu - add immediate unsigned
            printf("addiu(%d) %d %d %d\n", opcode, rs, rt, imm);
            return false;
        case 0xa: // slti - set less than immediate
            printf("slti(%d) %d %d %d\n", opcode, rs, rt, imm);
            return false;
        case 0xc: // andi - and immediate
            printf("andi(%d) %d %d %d\n", opcode, rs, rt, imm);
            return false;
        case 0xd: // ori - or immediate
            printf("ori(%d) %d %d %d\n", opcode, rs, rt, imm);
            return false;
        case 0xf: // liu - load upper immediate
            printf("liu(%d) %d %d %d\n", opcode, rs, rt, imm);
            return false;
        case 0x20: // lb - load byte
            printf("lb(%d) %d %d %d\n", opcode, rs, rt, imm);
            return false;
        case 0x21: // lh - load halfword
            printf("lh(%d) %d %d %d\n", opcode, rs, rt, imm);
            return false;
        case 0x23: // lw - load word
            printf("lw(%d) %d %d %d\n", opcode, rs, rt, imm);
            return false;
        case 0x28: // sb - store byte
            printf("sb(%d) %d %d %d\n", opcode, rs, rt, imm);
            return false;
        case 0x29: // sh - store halfword
            printf("sh(%d) %d %d %d\n", opcode, rs, rt, imm);
            return false;
        case 0x2b: // sw - store word
            printf("sw(%d) %d %d %d\n", opcode, rs, rt, imm);
            return false;
        default:
            return true;
    }
}

long calcFileSize(FILE *fp) {
    fseek(fp, 0L, SEEK_END);
    long fileSize = ftell(fp) / 4;
    fseek(fp, 0L, SEEK_SET);
    return fileSize;
}

void memoryAlocattion(FILE *fp, FILE *fp1, byte* memory, int sizeMemory){
    memset(memory, 0, sizeMemory);
    fread(memory, sizeof(byte), (sizeMemory / 4), fp);
    fread(&memory[0x2000], sizeof(byte), (sizeMemory / 4), fp1);
}

void printMemory(byte *memory) {
    for (int i = 0; i < 32; i += 1) {
        printf("$%-2d 0x%08x\n", i, *(word*)&memory[0x3fff - ((i + 1) * 4)]); 
    }

    for (int i = 0; i <= 0x3ff0; i += 16) {
        printf("Mem[0x%08x] ", i);
        printf("0x%08x ", *(word*)&memory[i]); 
        printf("0x%08x ", *(word*)&memory[i+4]); 
        printf("0x%08x ", *(word*)&memory[i+8]); 
        printf("0x%08x\n", *(word*)&memory[i+12]); 
    }
}

int main()
{
    FILE *fp = fopen("exemplo_text.bin", "rb");
    FILE *fp1 = fopen("exemplo_data.bin", "rb");
    word instrucao, opcode, param_r_instr;

    word *registers[32];
    word *specialRegisters[3];

    byte memory[4096 * 4];
    memoryAlocattion(fp, fp1, memory, sizeof(memory));
    

    registers[0] = (word *)&memory[0x3fff - 4]; // $zero 
    registers[1] = (word *)&memory[0x3fff - 8]; // $at  
    registers[2] = (word *)&memory[0x3fff - 12]; // $v0 
    registers[3] = (word *)&memory[0x3fff - 16]; // $v1 
    registers[4] = (word *)&memory[0x3fff - 20]; // $a0 
    registers[5] = (word *)&memory[0x3fff - 24]; // $a1 
    registers[6] = (word *)&memory[0x3fff - 28]; // $a2 
    registers[7] = (word *)&memory[0x3fff - 32]; // $a3 
    registers[8] = (word *)&memory[0x3fff - 36]; // $t0 
    registers[9] = (word *)&memory[0x3fff - 40]; // $t1 
    registers[10] = (word *)&memory[0x3fff - 44]; // $t2 
    registers[11] = (word *)&memory[0x3fff - 48]; // $t3 
    registers[12] = (word *)&memory[0x3fff - 52]; // $t4 
    registers[13] = (word *)&memory[0x3fff - 56]; // $t5 
    registers[14] = (word *)&memory[0x3fff - 60]; // $t6 
    registers[15] = (word *)&memory[0x3fff - 64]; // $t7 
    registers[16] = (word *)&memory[0x3fff - 68]; // $s0 
    registers[17] = (word *)&memory[0x3fff - 72]; // $s1 
    registers[18] = (word *)&memory[0x3fff - 76]; // $s2 
    registers[19] = (word *)&memory[0x3fff - 80]; // $s3 
    registers[20] = (word *)&memory[0x3fff - 84]; // $s4 
    registers[21] = (word *)&memory[0x3fff - 88]; // $s5 
    registers[22] = (word *)&memory[0x3fff - 92]; // $s6 
    registers[23] = (word *)&memory[0x3fff - 96]; // $s7 
    registers[24] = (word *)&memory[0x3fff - 100]; // $t8 
    registers[25] = (word *)&memory[0x3fff - 104]; // $s9 
    registers[26] = (word *)&memory[0x3fff - 108]; // $k0 
    registers[27] = (word *)&memory[0x3fff - 112]; // $k1 
    registers[28] = (word *)&memory[0x3fff - 116]; // $gp 
    registers[29] = (word *)&memory[0x3fff - 120]; // $sp 
    registers[30] = (word *)&memory[0x3fff - 124]; // $fp 
    registers[31] = (word *)&memory[0x3fff - 128]; // $ra 

    specialRegisters[0] = (word *)&memory[0x3fff - 132]; // pc
    specialRegisters[1] = (word *)&memory[0x3fff - 136]; // hi
    specialRegisters[2] = (word *)&memory[0x3fff - 140]; // lo

    *registers[29] = 0x00003ffc;
    *registers[28] = 0x1800;

    if (fp == NULL)
    {
        printf("Ihhh, deu erro.\n");
        return 1;
    }
    long fileSize = calcFileSize(fp);
    
    for(int i = 0; i < fileSize; i++) {
        fread(&instrucao, 4, 1, fp);
        printf("instrucao = %#x\n", instrucao);
        opcode = (instrucao & (0x3f << 26)) >> 26;
    
        switch (opcode)
        {
        case 0x0: // R format
            param_r_instr = instrucao & 0x3ffffff;
            if(r_instru(param_r_instr, *registers, *specialRegisters)) {
                raise(SIGFPE);
            }
            break;
        case 0x2: // jal - jump and link
        case 0x3: // j - jump
            if(j_instru(instrucao)){
                raise(SIGFPE);
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
            if(i_instru(instrucao)){
                raise(SIGFPE);
            }
            break;
        default:
            return false;
        }
    }
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

