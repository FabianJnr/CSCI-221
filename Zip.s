zip_with:
    addi $t0, $zero, 0
loop:
    addi $sp, $sp, -4
    sw $t0, 0($sp)
    beq $t0, $a3, end
    sll $t1, $t0, 2
    addi $t1, $a0, $t1
    lw $t1, 0($t1)
    sll $t2, $t0, 2
    addi $t2, $a1, $t2
    lw $t2, 0($t2)
    addi $sp, $sp, -12
    sw $ra, 8($sp)
    sw $a0, 4($sp)
    sw $a1, 0($sp)
    add $a0, $zero, $t1
    add $a1, $zero, $t2
    jal foo
    lw $a1, 0($sp)
    lw $a0, 4($sp)
    lw $ra, 8($sp)
    lw $t0, 12($sp)
    sll $t3, $t0, 2
    add $t3, $t3, $a2
    sw $v0, 0($t3)
    addi $t0, $t0, 1
    addi $sp, $sp, 16
    j loop

end:
    jr $ra