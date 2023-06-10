main:
        addiu   $sp,$sp,-24
        sw      $31,20($sp)
        sw      $fp,16($sp)
        move    $fp,$sp
        jal     printJogoDaVelha
        nop

        jal     jogoDaVelha
        nop

        move    $2,$0
        move    $sp,$fp
        lw      $31,20($sp)
        lw      $fp,16($sp)
        addiu   $sp,$sp,24
        jr      $31
        nop

jogoDaVelha:
        addiu   $sp,$sp,-136
        sw      $31,132($sp)
        sw      $fp,128($sp)
        move    $fp,$sp
        li      $2,32                 # 0x20
        sb      $2,24($fp)
        li      $2,32                 # 0x20
        sb      $2,25($fp)
        li      $2,58                 # 0x3a
        sb      $2,26($fp)
        li      $2,32                 # 0x20
        sb      $2,27($fp)
        li      $2,32                 # 0x20
        sb      $2,28($fp)
        li      $2,32                 # 0x20
        sb      $2,29($fp)
        li      $2,58                 # 0x3a
        sb      $2,30($fp)
        li      $2,32                 # 0x20
        sb      $2,31($fp)
        li      $2,32                 # 0x20
        sb      $2,32($fp)
        li      $2,10                 # 0xa
        sb      $2,33($fp)
        li      $2,32                 # 0x20
        sb      $2,34($fp)
        li      $2,32                 # 0x20
        sb      $2,35($fp)
        li      $2,58                 # 0x3a
        sb      $2,36($fp)
        li      $2,32                 # 0x20
        sb      $2,37($fp)
        li      $2,32                 # 0x20
        sb      $2,38($fp)
        li      $2,32                 # 0x20
        sb      $2,39($fp)
        li      $2,58                 # 0x3a
        sb      $2,40($fp)
        li      $2,32                 # 0x20
        sb      $2,41($fp)
        li      $2,32                 # 0x20
        sb      $2,42($fp)
        li      $2,10                 # 0xa
        sb      $2,43($fp)
        li      $2,32                 # 0x20
        sb      $2,44($fp)
        li      $2,32                 # 0x20
        sb      $2,45($fp)
        li      $2,58                 # 0x3a
        sb      $2,46($fp)
        li      $2,32                 # 0x20
        sb      $2,47($fp)
        li      $2,32                 # 0x20
        sb      $2,48($fp)
        li      $2,32                 # 0x20
        sb      $2,49($fp)
        li      $2,58                 # 0x3a
        sb      $2,50($fp)
        li      $2,32                 # 0x20
        sb      $2,51($fp)
        li      $2,32                 # 0x20
        sb      $2,52($fp)
        addiu   $2,$fp,24
        sw      $2,56($fp)
        addiu   $2,$fp,24
        addiu   $2,$2,4
        sw      $2,60($fp)
        addiu   $2,$fp,24
        addiu   $2,$2,8
        sw      $2,64($fp)
        addiu   $2,$fp,24
        addiu   $2,$2,10
        sw      $2,68($fp)
        addiu   $2,$fp,24
        addiu   $2,$2,14
        sw      $2,72($fp)
        addiu   $2,$fp,24
        addiu   $2,$2,18
        sw      $2,76($fp)
        addiu   $2,$fp,24
        addiu   $2,$2,20
        sw      $2,80($fp)
        addiu   $2,$fp,24
        addiu   $2,$2,24
        sw      $2,84($fp)
        addiu   $2,$fp,24
        addiu   $2,$2,28
        sw      $2,88($fp)
        li      $2,10                 # 0xa
        sb      $2,92($fp)
        li      $2,65                 # 0x41
        sb      $2,93($fp)
        li      $2,32                 # 0x20
        sb      $2,94($fp)
        li      $2,112                  # 0x70
        sb      $2,95($fp)
        li      $2,111                  # 0x6f
        sb      $2,96($fp)
        li      $2,115                  # 0x73
        sb      $2,97($fp)
        li      $2,105                  # 0x69
        sb      $2,98($fp)
        li      $2,99                 # 0x63
        sb      $2,99($fp)
        li      $2,97                 # 0x61
        sb      $2,100($fp)
        li      $2,111                  # 0x6f
        sb      $2,101($fp)
        li      $2,32                 # 0x20
        sb      $2,102($fp)
        li      $2,105                  # 0x69
        sb      $2,103($fp)
        li      $2,110                  # 0x6e
        sb      $2,104($fp)
        li      $2,118                  # 0x76
        sb      $2,105($fp)
        li      $2,97                 # 0x61
        sb      $2,106($fp)
        li      $2,108                  # 0x6c
        sb      $2,107($fp)
        li      $2,105                  # 0x69
        sb      $2,108($fp)
        li      $2,100                  # 0x64
        sb      $2,109($fp)
        li      $2,97                 # 0x61
        sb      $2,110($fp)
        li      $2,10                 # 0xa
        sb      $2,111($fp)
        li      $2,84                 # 0x54
        sb      $2,112($fp)
        li      $2,101                  # 0x65
        sb      $2,113($fp)
        li      $2,110                  # 0x6e
        sb      $2,114($fp)
        li      $2,116                  # 0x74
        sb      $2,115($fp)
        li      $2,101                  # 0x65
        sb      $2,116($fp)
        li      $2,32                 # 0x20
        sb      $2,117($fp)
        li      $2,78                 # 0x4e
        sb      $2,118($fp)
        li      $2,111                  # 0x6f
        sb      $2,119($fp)
        li      $2,118                  # 0x76
        sb      $2,120($fp)
        li      $2,97                 # 0x61
        sb      $2,121($fp)
        li      $2,109                  # 0x6d
        sb      $2,122($fp)
        li      $2,101                  # 0x65
        sb      $2,123($fp)
        li      $2,110                  # 0x6e
        sb      $2,124($fp)
        li      $2,116                  # 0x74
        sb      $2,125($fp)
        li      $2,101                  # 0x65
        sb      $2,126($fp)
        li      $2,10                 # 0xa
        sb      $2,127($fp)
        sw      $0,16($fp)
.L27:
        lw      $2,56($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        bne     $3,$2,.L4
        nop

        lw      $2,60($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        bne     $3,$2,.L4
        nop

        lw      $2,64($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        beq     $3,$2,.L5
        nop

.L4:
        lw      $2,68($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        bne     $3,$2,.L6
        nop

        lw      $2,72($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        bne     $3,$2,.L6
        nop

        lw      $2,76($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        beq     $3,$2,.L5
        nop

.L6:
        lw      $2,80($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        bne     $3,$2,.L7
        nop

        lw      $2,84($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        bne     $3,$2,.L7
        nop

        lw      $2,88($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        beq     $3,$2,.L5
        nop

.L7:
        lw      $2,56($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        bne     $3,$2,.L8
        nop

        lw      $2,72($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        bne     $3,$2,.L8
        nop

        lw      $2,88($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        beq     $3,$2,.L5
        nop

.L8:
        lw      $2,56($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        bne     $3,$2,.L9
        nop

        lw      $2,68($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        bne     $3,$2,.L9
        nop

        lw      $2,80($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        beq     $3,$2,.L5
        nop

.L9:
        lw      $2,60($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        bne     $3,$2,.L10
        nop

        lw      $2,72($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        bne     $3,$2,.L10
        nop

        lw      $2,84($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        beq     $3,$2,.L5
        nop

.L10:
        lw      $2,64($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        bne     $3,$2,.L11
        nop

        lw      $2,76($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        bne     $3,$2,.L11
        nop

        lw      $2,88($fp)
        lbu     $3,0($2)
        li      $2,79                 # 0x4f
        bne     $3,$2,.L11
        nop

.L5:
        addiu   $2,$fp,24
        li      $5,29                 # 0x1d
        move    $4,$2
        jal     printString
        nop

        li      $4,10                 # 0xa
        jal     printChar
        nop

        li      $4,79                 # 0x4f
        jal     printWinner
        nop

        jal     exit1
        nop

        b       .L26
        nop

.L11:
        lw      $2,56($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        bne     $3,$2,.L13
        nop

        lw      $2,60($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        bne     $3,$2,.L13
        nop

        lw      $2,64($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        beq     $3,$2,.L14
        nop

.L13:
        lw      $2,68($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        bne     $3,$2,.L15
        nop

        lw      $2,72($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        bne     $3,$2,.L15
        nop

        lw      $2,76($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        beq     $3,$2,.L14
        nop

.L15:
        lw      $2,80($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        bne     $3,$2,.L16
        nop

        lw      $2,84($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        bne     $3,$2,.L16
        nop

        lw      $2,88($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        beq     $3,$2,.L14
        nop

.L16:
        lw      $2,56($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        bne     $3,$2,.L17
        nop

        lw      $2,72($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        bne     $3,$2,.L17
        nop

        lw      $2,88($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        beq     $3,$2,.L14
        nop

.L17:
        lw      $2,56($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        bne     $3,$2,.L18
        nop

        lw      $2,68($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        bne     $3,$2,.L18
        nop

        lw      $2,80($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        beq     $3,$2,.L14
        nop

.L18:
        lw      $2,60($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        bne     $3,$2,.L19
        nop

        lw      $2,72($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        bne     $3,$2,.L19
        nop

        lw      $2,84($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        beq     $3,$2,.L14
        nop

.L19:
        lw      $2,64($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        bne     $3,$2,.L20
        nop

        lw      $2,76($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        bne     $3,$2,.L20
        nop

        lw      $2,88($fp)
        lbu     $3,0($2)
        li      $2,88                 # 0x58
        bne     $3,$2,.L20
        nop

.L14:
        addiu   $2,$fp,24
        li      $5,29                 # 0x1d
        move    $4,$2
        jal     printString
        nop

        li      $4,88                 # 0x58
        jal     printWinner
        nop

        li      $4,10                 # 0xa
        jal     printChar
        nop

        jal     exit1
        nop

        b       .L26
        nop

.L20:
        lw      $2,56($fp)
        lbu     $3,0($2)
        li      $2,32                 # 0x20
        beq     $3,$2,.L26
        nop

        lw      $2,60($fp)
        lbu     $3,0($2)
        li      $2,32                 # 0x20
        beq     $3,$2,.L26
        nop

        lw      $2,64($fp)
        lbu     $3,0($2)
        li      $2,32                 # 0x20
        beq     $3,$2,.L26
        nop

        lw      $2,68($fp)
        lbu     $3,0($2)
        li      $2,32                 # 0x20
        beq     $3,$2,.L26
        nop

        lw      $2,72($fp)
        lbu     $3,0($2)
        li      $2,32                 # 0x20
        beq     $3,$2,.L26
        nop

        lw      $2,76($fp)
        lbu     $3,0($2)
        li      $2,32                 # 0x20
        beq     $3,$2,.L26
        nop

        lw      $2,80($fp)
        lbu     $3,0($2)
        li      $2,32                 # 0x20
        beq     $3,$2,.L26
        nop

        lw      $2,84($fp)
        lbu     $3,0($2)
        li      $2,32                 # 0x20
        beq     $3,$2,.L26
        nop

        lw      $2,88($fp)
        lbu     $3,0($2)
        li      $2,32                 # 0x20
        beq     $3,$2,.L26
        nop

        addiu   $2,$fp,24
        li      $5,29                 # 0x1d
        move    $4,$2
        jal     printString
        nop

        jal     printDraw
        nop

        li      $4,10                 # 0xa
        jal     printChar
        nop

        jal     exit1
        nop

.L26:
        addiu   $2,$fp,24
        li      $5,29                 # 0x1d
        move    $4,$2
        jal     printString
        nop

        jal     printInsertPosition
        nop

        jal     readInt
        nop

        sw      $2,20($fp)
        lw      $3,20($fp)
        li      $2,1                        # 0x1
        beq     $3,$2,.L21
        nop

        lw      $3,20($fp)
        li      $2,2                        # 0x2
        beq     $3,$2,.L21
        nop

        lw      $3,20($fp)
        li      $2,3                        # 0x3
        beq     $3,$2,.L21
        nop

        lw      $3,20($fp)
        li      $2,4                        # 0x4
        beq     $3,$2,.L21
        nop

        lw      $3,20($fp)
        li      $2,5                        # 0x5
        beq     $3,$2,.L21
        nop

        lw      $3,20($fp)
        li      $2,6                        # 0x6
        beq     $3,$2,.L21
        nop

        lw      $3,20($fp)
        li      $2,7                        # 0x7
        beq     $3,$2,.L21
        nop

        lw      $3,20($fp)
        li      $2,8                        # 0x8
        beq     $3,$2,.L21
        nop

        lw      $3,20($fp)
        li      $2,9                        # 0x9
        beq     $3,$2,.L21
        nop

        addiu   $2,$fp,92
        li      $5,36                 # 0x24
        move    $4,$2
        jal     printString
        nop

        b       .L22
        nop

.L21:
        lw      $2,20($fp)
        addiu   $2,$2,-1
        sll     $2,$2,2
        addiu   $3,$fp,16
        addu    $2,$3,$2
        lw      $2,40($2)
        lbu     $3,0($2)
        li      $2,32                 # 0x20
        beq     $3,$2,.L23
        nop

        addiu   $2,$fp,92
        li      $5,36                 # 0x24
        move    $4,$2
        jal     printString
        nop

        b       .L26
        nop

.L23:
        lw      $2,16($fp)
        andi    $2,$2,0x1
        bne     $2,$0,.L24
        nop

        lw      $2,20($fp)
        addiu   $2,$2,-1
        sll     $2,$2,2
        addiu   $3,$fp,16
        addu    $2,$3,$2
        lw      $2,40($2)
        li      $3,88                 # 0x58
        sb      $3,0($2)
        li      $2,1                        # 0x1
        sw      $2,16($fp)
        b       .L25
        nop

.L24:
        lw      $2,20($fp)
        addiu   $2,$2,-1
        sll     $2,$2,2
        addiu   $3,$fp,16
        addu    $2,$3,$2
        lw      $2,40($2)
        li      $3,79                 # 0x4f
        sb      $3,0($2)
        sw      $0,16($fp)
        b       .L25
        nop

.L22:
        b       .L26
        nop

.L25:
        b       .L27
        nop

printDraw:
        addiu   $sp,$sp,-40
        sw      $31,36($sp)
        sw      $fp,32($sp)
        move    $fp,$sp
        li      $2,10                 # 0xa
        sb      $2,16($fp)
        li      $2,68                 # 0x44
        sb      $2,17($fp)
        li      $2,101                  # 0x65
        sb      $2,18($fp)
        li      $2,117                  # 0x75
        sb      $2,19($fp)
        li      $2,32                 # 0x20
        sb      $2,20($fp)
        li      $2,69                 # 0x45
        sb      $2,21($fp)
        li      $2,109                  # 0x6d
        sb      $2,22($fp)
        li      $2,112                  # 0x70
        sb      $2,23($fp)
        li      $2,97                 # 0x61
        sb      $2,24($fp)
        li      $2,116                  # 0x74
        sb      $2,25($fp)
        li      $2,101                  # 0x65
        sb      $2,26($fp)
        li      $2,33                 # 0x21
        sb      $2,27($fp)
        li      $2,10                 # 0xa
        sb      $2,28($fp)
        li      $5,12                 # 0xc
        addiu   $2,$fp,16
        move    $4,$2
        jal     printString
        nop

        nop
        move    $sp,$fp
        lw      $31,36($sp)
        lw      $fp,32($sp)
        addiu   $sp,$sp,40
        jr      $31
        nop

printWinner:
        addiu   $sp,$sp,-40
        sw      $31,36($sp)
        sw      $fp,32($sp)
        move    $fp,$sp
        move    $2,$4
        sb      $2,40($fp)
        li      $2,10                 # 0xa
        sb      $2,16($fp)
        li      $2,71                 # 0x47
        sb      $2,17($fp)
        li      $2,97                 # 0x61
        sb      $2,18($fp)
        li      $2,110                  # 0x6e
        sb      $2,19($fp)
        li      $2,104                  # 0x68
        sb      $2,20($fp)
        li      $2,97                 # 0x61
        sb      $2,21($fp)
        li      $2,100                  # 0x64
        sb      $2,22($fp)
        li      $2,111                  # 0x6f
        sb      $2,23($fp)
        li      $2,114                  # 0x72
        sb      $2,24($fp)
        li      $2,58                 # 0x3a
        sb      $2,25($fp)
        li      $2,32                 # 0x20
        sb      $2,26($fp)
        lbu     $3,40($fp)
        li      $2,88                 # 0x58
        bne     $3,$2,.L30
        nop

        li      $2,88                 # 0x58
        sb      $2,27($fp)
        b       .L31
        nop

.L30:
        li      $2,79                 # 0x4f
        sb      $2,27($fp)
.L31:
        li      $2,33                 # 0x21
        sb      $2,28($fp)
        li      $2,33                 # 0x21
        sb      $2,29($fp)
        li      $5,14                 # 0xe
        addiu   $2,$fp,16
        move    $4,$2
        jal     printString
        nop

        nop
        move    $sp,$fp
        lw      $31,36($sp)
        lw      $fp,32($sp)
        addiu   $sp,$sp,40
        jr      $31
        nop

printJogoDaVelha:
        addiu   $sp,$sp,-40
        sw      $31,36($sp)
        sw      $fp,32($sp)
        move    $fp,$sp
        li      $2,74                 # 0x4a
        sb      $2,16($fp)
        li      $2,111                  # 0x6f
        sb      $2,17($fp)
        li      $2,103                  # 0x67
        sb      $2,18($fp)
        li      $2,111                  # 0x6f
        sb      $2,19($fp)
        li      $2,32                 # 0x20
        sb      $2,20($fp)
        li      $2,100                  # 0x64
        sb      $2,21($fp)
        li      $2,97                 # 0x61
        sb      $2,22($fp)
        li      $2,32                 # 0x20
        sb      $2,23($fp)
        li      $2,86                 # 0x56
        sb      $2,24($fp)
        li      $2,101                  # 0x65
        sb      $2,25($fp)
        li      $2,108                  # 0x6c
        sb      $2,26($fp)
        li      $2,104                  # 0x68
        sb      $2,27($fp)
        li      $2,97                 # 0x61
        sb      $2,28($fp)
        li      $2,10                 # 0xa
        sb      $2,29($fp)
        li      $5,14                 # 0xe
        addiu   $2,$fp,16
        move    $4,$2
        jal     printString
        nop

        nop
        move    $sp,$fp
        lw      $31,36($sp)
        lw      $fp,32($sp)
        addiu   $sp,$sp,40
        jr      $31
        nop

printInsertPosition:
        addiu   $sp,$sp,-56
        sw      $31,52($sp)
        sw      $fp,48($sp)
        move    $fp,$sp
        li      $2,10                 # 0xa
        sb      $2,16($fp)
        li      $2,73                 # 0x49
        sb      $2,17($fp)
        li      $2,110                  # 0x6e
        sb      $2,18($fp)
        li      $2,115                  # 0x73
        sb      $2,19($fp)
        li      $2,105                  # 0x69
        sb      $2,20($fp)
        li      $2,114                  # 0x72
        sb      $2,21($fp)
        li      $2,97                 # 0x61
        sb      $2,22($fp)
        li      $2,32                 # 0x20
        sb      $2,23($fp)
        li      $2,117                  # 0x75
        sb      $2,24($fp)
        li      $2,109                  # 0x6d
        sb      $2,25($fp)
        li      $2,97                 # 0x61
        sb      $2,26($fp)
        li      $2,32                 # 0x20
        sb      $2,27($fp)
        li      $2,112                  # 0x70
        sb      $2,28($fp)
        li      $2,111                  # 0x6f
        sb      $2,29($fp)
        li      $2,115                  # 0x73
        sb      $2,30($fp)
        li      $2,105                  # 0x69
        sb      $2,31($fp)
        li      $2,99                 # 0x63
        sb      $2,32($fp)
        li      $2,97                 # 0x61
        sb      $2,33($fp)
        li      $2,111                  # 0x6f
        sb      $2,34($fp)
        li      $2,40                 # 0x28
        sb      $2,35($fp)
        li      $2,49                 # 0x31
        sb      $2,36($fp)
        li      $2,32                 # 0x20
        sb      $2,37($fp)
        li      $2,97                 # 0x61
        sb      $2,38($fp)
        li      $2,32                 # 0x20
        sb      $2,39($fp)
        li      $2,57                 # 0x39
        sb      $2,40($fp)
        li      $2,41                 # 0x29
        sb      $2,41($fp)
        li      $2,58                 # 0x3a
        sb      $2,42($fp)
        li      $2,32                 # 0x20
        sb      $2,43($fp)
        li      $5,28                 # 0x1c
        addiu   $2,$fp,16
        move    $4,$2
        jal     printString
        nop

        nop
        move    $sp,$fp
        lw      $31,52($sp)
        lw      $fp,48($sp)
        addiu   $sp,$sp,56
        jr      $31
        nop

exit1:
        addiu   $sp,$sp,-8
        sw      $fp,4($sp)
        move    $fp,$sp
        addi $v0, $zero, 10
syscall
        nop
        move    $sp,$fp
        lw      $fp,4($sp)
        addiu   $sp,$sp,8
        jr      $31
readInt:
        addiu   $sp,$sp,-16
        sw      $fp,12($sp)
        move    $fp,$sp
        add $3,$zero,$3
ori $v0, $zero, 5
        add $a0, $3, $zero
syscall
move $3, $v0

        sw      $3,0($fp)
        lw      $2,0($fp)
        move    $sp,$fp
        lw      $fp,12($sp)
        addiu   $sp,$sp,16
        jr      $31
printChar:
        addiu   $sp,$sp,-8
        sw      $fp,4($sp)
        move    $fp,$sp
        move    $2,$4
        sb      $2,8($fp)
        lbu     $2,8($fp)
        sw $2, 0($sp)
sw $3, -4($sp)
add $3,$zero,$2
ori $v0, $zero, 11
        add $a0, $3, $zero
syscall
lw $3, 0($sp)
lw $2, -4($sp)

        nop
        move    $sp,$fp
        lw      $fp,4($sp)
        addiu   $sp,$sp,8
        jr      $31
printString:
        addiu   $sp,$sp,-32
        sw      $31,28($sp)
        sw      $fp,24($sp)
        move    $fp,$sp
        sw      $4,32($fp)
        sw      $5,36($fp)
        sw      $0,16($fp)
        b       .L39
        nop

.L40:
        lw      $2,16($fp)
        lw      $3,32($fp)
        addu    $2,$3,$2
        lbu     $2,0($2)
        move    $4,$2
        jal     printChar
        nop

        lw      $2,16($fp)
        addiu   $2,$2,1
        sw      $2,16($fp)
.L39:
        lw      $3,16($fp)
        lw      $2,36($fp)
        slt     $2,$3,$2
        bne     $2,$0,.L40
        nop

        nop
        nop
        move    $sp,$fp
        lw      $31,28($sp)
        lw      $fp,24($sp)
        addiu   $sp,$sp,32
        jr      $31
        nop