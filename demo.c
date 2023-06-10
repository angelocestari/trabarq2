void exit1();
int readInt();
void printChar(char cha);
void printString(char string[], int stringSize);
void printJogoDaVelha();
void printInsertPosition();
void printWinner(char winner);
void printDraw();
void jogoDaVelha();


int main() {
    printJogoDaVelha();
    jogoDaVelha();
    return 0;
}

void jogoDaVelha() {
    char table[29];
    table[0] = ' ';
    table[1] = ' ';
    table[2] = ':';
    table[3] = ' ';
    table[4] = ' ';
    table[5] = ' ';
    table[6] = ':';
    table[7] = ' ';
    table[8] = ' ';
    
    table[9] = '\n';

    table[10] = ' ';
    table[11] = ' ';
    table[12] = ':';
    table[13] = ' ';
    table[14] = ' ';
    table[15] = ' ';
    table[16] = ':';
    table[17] = ' ';
    table[18] = ' ';

    table[19] = '\n';

    table[20] = ' ';
    table[21] = ' ';
    table[22] = ':';
    table[23] = ' ';
    table[24] = ' ';
    table[25] = ' ';
    table[26] = ':';
    table[27] = ' ';
    table[28] = ' ';

    char *numbers[9];
    numbers[0] = &table[0];
    numbers[1] = &table[4];
    numbers[2] = &table[8];
    numbers[3] = &table[10];
    numbers[4] = &table[14];
    numbers[5] = &table[18];
    numbers[6] = &table[20];
    numbers[7] = &table[24];
    numbers[8] = &table[28];

    char stringError[36];
    stringError[0] = '\n';
    stringError[1] = 'A';
    stringError[2] = ' ';
    stringError[3] = 'p';
    stringError[4] = 'o';
    stringError[5] = 's';
    stringError[6] = 'i';
    stringError[7] = 'c';
    stringError[8] = 'a';
    stringError[9] = 'o';
    stringError[10] = ' ';
    stringError[11] = 'i';
    stringError[12] = 'n';
    stringError[13] = 'v';
    stringError[14] = 'a';
    stringError[15] = 'l';
    stringError[16] = 'i';
    stringError[17] = 'd';
    stringError[18] = 'a';
    stringError[19] = '\n';
    stringError[20] = 'T';
    stringError[21] = 'e';
    stringError[22] = 'n';
    stringError[23] = 't';
    stringError[24] = 'e';
    stringError[25] = ' ';
    stringError[26] = 'N';
    stringError[27] = 'o';
    stringError[28] = 'v';
    stringError[29] = 'a';
    stringError[30] = 'm';
    stringError[31] = 'e';
    stringError[32] = 'n';
    stringError[33] = 't';
    stringError[34] = 'e';
    stringError[35] = '\n';

    int i = 0, position;
    while(1) {
        if(
            (*numbers[0] == 'O' && *numbers[1] == 'O' && *numbers[2] == 'O') ||
            (*numbers[3] == 'O' && *numbers[4] == 'O' && *numbers[5] == 'O') ||
            (*numbers[6] == 'O' && *numbers[7] == 'O' && *numbers[8] == 'O') ||

            (*numbers[0] == 'O' && *numbers[4] == 'O' && *numbers[8] == 'O') ||

            (*numbers[0] == 'O' && *numbers[3] == 'O' && *numbers[6] == 'O') ||
            (*numbers[1] == 'O' && *numbers[4] == 'O' && *numbers[7] == 'O') ||
            (*numbers[2] == 'O' && *numbers[5] == 'O' && *numbers[8] == 'O')) 
        {
            printString(table, sizeof(table));
            printChar('\n');
            printWinner('O');
            exit1();
        } else if(
            (*numbers[0] == 'X' && *numbers[1] == 'X' && *numbers[2] == 'X') ||
            (*numbers[3] == 'X' && *numbers[4] == 'X' && *numbers[5] == 'X') ||
            (*numbers[6] == 'X' && *numbers[7] == 'X' && *numbers[8] == 'X') ||

            (*numbers[0] == 'X' && *numbers[4] == 'X' && *numbers[8] == 'X') ||

            (*numbers[0] == 'X' && *numbers[3] == 'X' && *numbers[6] == 'X') ||
            (*numbers[1] == 'X' && *numbers[4] == 'X' && *numbers[7] == 'X') ||
            (*numbers[2] == 'X' && *numbers[5] == 'X' && *numbers[8] == 'X')) 
        {
            printString(table, sizeof(table));
            printWinner('X');
            printChar('\n');
            exit1();
        } else if(
            (*numbers[0] != ' ' && *numbers[1] != ' ' && *numbers[2] != ' ') &&
            (*numbers[3] != ' ' && *numbers[4] != ' ' && *numbers[5] != ' ') &&
            (*numbers[6] != ' ' && *numbers[7] != ' ' && *numbers[8] != ' ')) 
        {
            printString(table, sizeof(table));
            printDraw();
            printChar('\n');
            exit1();
        }
        while(1) {
            printString(table, sizeof(table));
            printInsertPosition();
            position = readInt();
            if(position != 1 && position != 2 && position != 3 && 
                position != 4 && position != 5 && position != 6 && 
                position != 7 && position != 8 && position != 9) {
                printString(stringError, sizeof(stringError));
            } else if(*numbers[position - 1] != ' '){
                printString(stringError, sizeof(stringError));
            }
            else {
                if(i % 2 == 0) {
                    *numbers[position - 1] = 'X';
                    i = 1;
                    break;
                } else {
                    *numbers[position - 1] = 'O';
                    i = 0;
                    break;
                }
            }
        }
        
    }

    printString(table, 29);
}

void printDraw() {
    char string[12];
    string[0] = '\n';
    string[1] = 'D';
    string[2] = 'e';
    string[3] = 'u';
    string[4] = ' ';
    string[5] = 'E';
    string[6] = 'm';
    string[7] = 'p';
    string[8] = 'a';
    string[9] = 't';
    string[10] = 'e';
    string[11] = '!';
    string[12] = '\n';
    printString(string, sizeof(string));
}

void printWinner(char winner) {
    char string[14];
    string[0] = '\n';
    string[1] = 'G';
    string[2] = 'a';
    string[3] = 'n';
    string[4] = 'h';
    string[5] = 'a';
    string[6] = 'd';
    string[7] = 'o';
    string[8] = 'r';
    string[9] = ':';
    string[10] = ' ';
    if(winner == 'X') {
        string[11] = 'X';
    } else {
        string[11] = 'O';
    }
    string[12] = '!';
    string[13] = '!';
    printString(string, sizeof(string));
}



void printJogoDaVelha() {
    char string[14];
    string[0] = 'J';
    string[1] = 'o';
    string[2] = 'g';
    string[3] = 'o';
    string[4] = ' ';
    string[5] = 'd';
    string[6] = 'a';
    string[7] = ' ';
    string[8] = 'V';
    string[9] = 'e';
    string[10] = 'l';
    string[11] = 'h';
    string[12] = 'a';
    string[13] = '\n';
    printString(string, sizeof(string));
}

void printInsertPosition() {
    char string[28];
    string[0] = '\n';
    string[1] = 'I';
    string[2] = 'n';
    string[3] = 's';
    string[4] = 'i';
    string[5] = 'r';
    string[6] = 'a';
    string[7] = ' ';
    string[8] = 'u';
    string[9] = 'm';
    string[10] = 'a';
    string[11] = ' ';
    string[12] = 'p';
    string[13] = 'o';
    string[14] = 's';
    string[15] = 'i';
    string[16] = 'c';
    string[17] = 'a';
    string[18] = 'o';
    string[19] = '(';
    string[20] = '1';
    string[21] = ' ';
    string[22] = 'a';
    string[23] = ' ';
    string[24] = '9';
    string[25] = ')';
    string[26] = ':';
    string[27] = ' ';
    printString(string, sizeof(string));
}

void exit1(){
    __asm__(
        "addi $v0, $zero, 10\n"
        "syscall"
    );
}

int readInt() {
    int readedInt;
    __asm__(
        "add $3,$zero,%0\n"
        "ori $v0, $zero, 5\n\t"
        "add $a0, $3, $zero\n"
        "syscall\n"
        "move %0, $v0\n"
        : "=r" (readedInt)
        :
        : "$v0"
    );
    return readedInt;
}

void printChar(char cha) {
        __asm__(
            "sw $2, 0($sp)\n"
            "sw $3, -4($sp)\n"
            "add $3,$zero,%0\n"
            "ori $v0, $zero, 11\n\t"
            "add $a0, $3, $zero\n"
            "syscall\n"
            "lw $3, 0($sp)\n"
            "lw $2, -4($sp)\n"   
            :
            : "r" (cha)
        );
}


void printString(char string[], int stringSize){
    for(int i = 0; i < stringSize; i++) {
        printChar(string[i]);
    }
}