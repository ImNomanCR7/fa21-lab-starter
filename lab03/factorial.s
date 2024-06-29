
#Author: Noman Rafiq
#Dated: 30 June, 2024
#Description: The program uses a variable n to calculate the factorial of that number.


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
    addi t0, x0, 1  #factorial = t0 = 1
loop:
    mul t0, t0, a0  #factorial = 1 * n
    addi a0, a0, -1 # n = n - 1
    bne a0, x0, loop
    mv a0, t0
    jr ra