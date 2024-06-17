uint32_t decay_help(uint16_t* values, uint16_t length, uint16_t decay, uint32_t sum){
    if (length < 0){
        return sum;
    }
    int val = values[length];
    for (int j = 0, j < length, j++){
        val = val / decay;
    }
    return decay_help(values, length-1, decay, sum + val);
}

uint32_t decaying_sum(uint16_t* values, uint16_t length, uint16_t decay) {
    length = length -1;
  return decay_help(&values, length, decay, 0);
}

decaying_sum:
    addi $a1, $a1, -1
    addi $a3, $zero, 0
    addi $sp, $sp, -4
    sw $ra, 0($sp)
    jal decay_help
    lw $ra, 0($sp)
    addi $sp, $sp 4
    jr $ra

decay_help:
    bltz $a1, end
    sll $t0, $a1, 2
    addu $t1, a0, $t0
    lw $t1, 0($t1)

    addi $t2, $zero, 0
loop:
    beq $t2, $a1, break
    div $t1, $a2
    mflo $t1
    addi $t2, $t2, 1
    j loop
break:
    addi $a1, $a1, -1
    add $a3, $a3, $t1
    j decay_help

end:
    addu $v0, $zero, $a3
    jr $ra



  