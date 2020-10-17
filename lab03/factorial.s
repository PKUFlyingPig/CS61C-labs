.globl factorial

.data
n: .word 8

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    # YOUR CODE HERE
li t0, 1
	beq a0, t0, finish # if (n==1) return 1
    addi sp, sp, -8
    sw ra, 4(sp)       # push ra
    sw a0, 0(sp)       # push a0
    addi a0, a0, -1
    jal ra, factorial  # call factorial(n-1)
    lw t0, 0(sp)       # pop a0
    mul a0, a0, t0     
    lw ra, 4(sp)       # pop ra
    addi sp, sp, 8
finish:
    ret
