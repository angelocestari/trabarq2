

# Program File: Program2-3.asm
# Author: Charles Kann
# Program to read a string from a user, and # print that string back to the console. 
.text
main:
    addi $a0, $zero, 100
    addi $v0, $zero, 1
    syscall
    
    la $a0, separator
    addi $v0, $zero, 4
    syscall
    
    la $a0, readInt
    addi $v0, $zero, 4
    syscall
    
    addi $v0, $zero, 5
    syscall
    
    la $a0, separator
    addi $v0, $zero, 4
    syscall
    
    la $a0, prompt
    addi $v0, $zero, 4
    syscall
    
    la $a0, input
    addi $v0, $zero, 8
    lw $a1, inputSize
    syscall
    
    la $a0, separator
    addi $v0, $zero, 4
    syscall
    
    addi $a0, $zero, 67
    addi $v0, $zero, 11
    syscall
    
    la $a0, separator
    addi $v0, $zero, 4
    syscall
    
    la $a0, readChar
    addi $v0, $zero, 4
    syscall
    
    addi $v0, $zero, 12
    syscall
    
    la $a0, separator
    addi $v0, $zero, 4
    syscall
    
    addi $a0, $zero, 100
    addi $v0, $zero, 34
    syscall
    
    la $a0, separator
    addi $v0, $zero, 4
    syscall
    
    addi $a0, $zero, 100
    addi $v0, $zero, 35
    syscall
    
    la $a0, separator
    addi $v0, $zero, 4
    syscall
    
    addi $a0, $zero, -100
    addi $v0, $zero, 36
    syscall
    
    

.data
input:        .space 80
inputSize:    .word 80
prompt:       .asciiz "Please enter an string:"
separator:    .asciiz "\n========================\n"
output:       .asciiz "\nYou typed the string: "
character:    .asciiz "C"
readInt:     .asciiz "Enter integer: \n"
readChar:     .asciiz "Enter character: \n"
