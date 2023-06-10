# Mips Emulator

Esse trabalho foi realizado por:
- Pedro dos Santos Zanelato
- Angelo Henrique Peres Cestari Junior

O nosso emulador funciona da seguinte maneira:
1. Os arquivos de data e texto são lidos. Se caso o programa não conseguir fazer isso uma mensagem de erro é exibida e a execução é encerrada;
2. Os dados dos arquivos são passados para sua respectiva partição de uma memória enderaçada por bytes;
3. A partir de um pc iniciado em 0, as intruções são executadas de acordo com seu formato (R, I ou J) por funções correspondentes;
4. Ao fim da execução de todas as instruções, todos as impressões feitas pelo programa, o conteúdo de seus registradores e de sua memória são impressos no terminal;

Observações: 
1. Existe uma verificação de endereços válidos;
2. Existe uma verificação de stack overflow;

Funcionalidades Implementadas:
- Syscalls: 
1. print integer
4. print string
5. read integer
6. read string
10. exit
12. read character
34. print integer in hexadecimal
35. print integer in binary
36. print as unsigned
- R-format: 
1. sll - shift left logical
2. srl - shift right logical
3. sra - shift right arithmetic
4. jr - jump register
5. mfohi - move from high
6. mfolo - move from low
7. multi - multiply 
8. div - divide
9. add - add
10. addu - add unsigned
11. sub - substract
12. sub - substract unsigned
13. and - and
14. or - or 
15. xor - xor
16. slt - set less than
- J-format:
1. j - jump
2. jal - jump and link
- I-format:
1. bgez - branch on greater than or equal to zero
2. beq - branch on equal
3. bnq - branch on not equal
4. addi - add immediate
5. addiu - add immediate unsigned
6. slti - set less than immediate
7. andi - and immediate
8. ori - or immediate
9. lui - load upper immediate
10. lb - load byte
11. lh - load halfword
12. lw - load word
13. lbu - load byte unsigned
14. lhu - load half word unsigned
15. sb - store byte
16. sh - store halfword
17. sw - store word

O trabalho é composto de 2 arquivos:
- trab.c
- trab.h

Funcionalidades não implementadas: Nenhuma

Para compilar o emulador:

`gcc -o emulador trab.c`

Para rodar a demo ou outro programa:

1. Salve o binário nos respectivos: program_text.bin e program_data.bin
2. ./emulador program_text.bin program_data.bin > program_out.txt
3. Para ver o resultado acesse program_out.txt

OBS: Os binários da demo já estão em program_text.bin e program_data.bin.
