main:
        addiu   $sp,$sp,-24
        sw      $31,20($sp)
        sw      $fp,16($sp)
        move    $fp,$sp
        beq	$zero, $4, sim
        nop

        move    $2,$0
        move    $sp,$fp
        lw      $31,20($sp)
        lw      $fp,16($sp)
        addiu   $sp,$sp,24
        jr      $31
        nop

sim:
        addiu   $sp,$sp,-8
        sw      $fp,4($sp)
        move    $fp,$sp
        nop
        move    $sp,$fp
        lw      $fp,4($sp)
        addiu   $sp,$sp,8
        jr      $31
        nop