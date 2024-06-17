        .text
        .globl main
main:

        #Minimum
        lw $t0, 0($a0)
        lw $t1, 0($a1)
        beq $t0, $t1, equal
        slt $t2, $t0, $t1
        bne $t2, $zero, a0_less
        sw $t1, 0($a2)
        j end_code
        a0_less:
            sw $t0, 0($a2)
            j end_code
        equal:
            sw $t0, 0($a2)
            j end_code
        end_code:
    
        #Parity
        addi $t0, $zero, 2
        addi $t1, $zero, 0
        addi $t4, $zero, 1
        loop_par:
            div $a0, $t0
            mfhi $t2
            beq $t2, $t4, add_1
            srl $a0, $a0, 1
            beq $a0, $zero, end_loop
            j loop_par
        add_1:
            addi $t1, $t1, 1
            srl $a0, $a0, 1
            beq $a0, $zero, end_loop
            j loop_par
        end_loop:
            div $t1, $t0
            mfhi $t3
            beq $t3, $zero, even
            addi $v0, $zero, 1
        even:
            addi $v0, $zero, 0

        #Array Maximum 
        addi $t0, $zero, 0
        lw $t1, 0($a0)
        loop_arr:
            beq $t0, $a1, end
            mul $t2, $t0, 4
            add $t3, $a0, $t2
            lw $t4, 0($t3)
            slt $t5, $t1, $t4
            beq $t5, $zero, no_change
            add $t1, $zero, $t4
            addi $t0, $t0, 1
            j loop_arr
        no_change:
            addi $t0, $t0, 1
            j loop_arr
        end:
            add $v0, $zero, $t1

        #Permutation
        addiu $t0, $zero, 0
        loop:
            beq $t0, $a2, stop  

            sll $t1, $t0, 2

            add $t2, $a0, $t1
            lw $t3, 0($t2)

            addu $t4, $zero, $t3

            add $t5, $a1, $t1
            lw $t6, 0($t5)

            sll $t7, $t6, 2
            add $t8, $a0, $t7
            lw $t9, 0($t8)

            sw $t9, 0($t2)

            sw $t4, 0($t8)
            
            addiu $t0, $t0, 1
        stop:
        
        addi $a0, $zero, 0
        jr $ra