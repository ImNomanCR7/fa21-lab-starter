# Author: Noman Rafiq
# Date: July 1, 2024
# Description: This RISC-V assembly code stores multiples of 7 in an array b.

.data
a:  .word 7
b:  .word   0, 0, 0

.text
main:
    
    # Save preserved registers
    addi sp, sp, -12
    sw s0, 0(sp)  
    sw s1, 4(sp)
    sw s2, 8(sp)
    
    # Initialize i (s0) to 0
    addi s0, x0, 0

    # Load a (7) into s1
    la s1, a
    lw s1, 0(s1)
    
    # Set t1 to 3 (for termination condition)
    addi t1, x0, 3

    # Load the address of array b into s2
    la s2, b

for:
    # Check if i equals t1 (termination condition)
    beq s0, t1, exit

    # Calculate b[i] = a + (i * a)
    mul t2, s0, s1  # t2 = i * a
    add t2, t2, s1  # t2 = a + (i * a)
    slli t3, s0, 2  # t3 = i * 4 (shift left by 2 for word offset)
    add s2, s2, t3  # s2 = address of particular integer in b
    sw t2, 0(s2)    # Store t2 in b[i]

    # Print b[i]
    addi a0, x0, 1
    add a1, x0, t2
    ecall

    # Print newline
    addi a0, x0, 11
    addi a1, x0, '\n'
    ecall

    # Increment i
    addi s0, s0, 1
    j for

exit:
    # Restore preserved registers
    lw s0, 0(sp)
    lw s1, 4(sp)
    addi sp, sp, 8

    # Exit program
    addi a0, x0, 10
    addi a1, x0, 1
    ecall