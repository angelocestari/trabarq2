#include <stdio.h>
#include <stdint.h>

int main()
{
    FILE *fp = fopen("exemplo_text.bin", "rb");
    int32_t instrucao = 0;
    int32_t opcode, rs, rt, rd, shamt, funct = 0;
    int16_t imm = 0;

    if (fp == NULL)
    {
        printf("Ihhh, deu erro.\n");
        return 1;
    }

    fread(&instrucao, 4, 1, fp);

    printf("instrucao = %#x\n", instrucao);

    fclose(fp);

    //  OP     RS   RT    IMMEDIATE
    // ,--6-,,-5-,,-5-,,-------16-----, I
    // ,--6-,,-5-,,-5-,,-5-,,-5-,,--6-, R
    // ,--6-,,-----------26-----------, J
    // 11111100111111111011110100100011
    // 11111100000000000000000000000000 = 0x3f << 26
    // 00000011111000000000000000000000 = 0x1f << 21
    // 00000000000111110000000000000000 = 0x1f << 16
    // 00000000000000001111111111111111 = 0xffff

    opcode = (instrucao & (0x3f << 26)) >> 26;
    
    switch (opcode)
    {
    case 0:
        rs     = (instrucao & (0x1f << 21)) >> 21;
        rt     = (instrucao & (0x1f << 16)) >> 16;
        rd    = (instrucao & (0x1f << 11)) >> 11;
        shamt    = (instrucao & (0x1f << 6)) >> 6;
        funct    = instrucao & 0x1f;
        printf("%d, %d, %d, %d, %d, %d\n", opcode, rs, rt, rd, shamt, funct);
        switch (funct)
        {
        case 0x20:
            printf("add(%d) %d, %d, %d, %d, %d\n", opcode, rs, rt, rd, shamt, funct);
            break;
        
        default:
            break;
        }
        break;
    
    default:
        break;
    }

    if (opcode == 8)
    {
        printf("addi(%d) %d, %d, %d\n", opcode, rs, rt, imm);
    }

    return 0;
}