#include "trab.h"

bool r_instru(word instruction) {
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

void memoryAlocattion(FILE *fp, FILE *fp1, byte* memory){
    byte* memory_start = memory;
    memset(memory, 0, sizeof(memory));
    fread(memory_start, 1, sizeof(memory), fp);
    fread(memory_start + 0x2000, 1, sizeof(memory), fp1);
}

int main()
{
    FILE *fp = fopen("exemplo_text.bin", "rb");
    FILE *fp1 = fopen("exemplo_data.bin", "rb");
    word instrucao, opcode, param_r_instr;
    
    byte memory[4096 * 4];
    byte* memory_start = memory;
    memset(memory, 0, sizeof(memory));
    fread(memory_start, 1, sizeof(memory), fp);
    fread(memory_start + 0x2000, 1, sizeof(memory), fp1);

    uint32_t *wordPtr = (uint32_t *)&memory[20];
    *wordPtr = 0x12345678;
    uint32_t myWord = *wordPtr;

    for (int i = 0; i < sizeof(memory); i += 16) {
        printf("Mem[0x%08x] ", i);
        printf("%02x%02x%02x%02x ", memory[i], memory[i+1], memory[i+2], memory[i+3]); 
        printf("%02x%02x%02x%02x ", memory[i+4], memory[i+5], memory[i+6], memory[i+7]); 
        printf("%02x%02x%02x%02x ", memory[i+8], memory[i+9], memory[i+10], memory[i+11]); 
        printf("%02x%02x%02x%02x\n", memory[i+12], memory[i+13], memory[i+14], memory[i+15]); 
    }

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
            if(r_instru(param_r_instr)) {
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

    fclose(fp);

    //  OP     RS   RT    IMMEDIATE
    // ,--6-,,-5-,,-5-,,-------16-----, I
    // ,--6-,,-5-,,-5-,,-5-,,-5-,,--6-, R
    // ,--6-,,-----------26-----------, J
    // 11111100111111111011110100100011
    // 00000011111111111111111111111111

    

    return 0;
}

