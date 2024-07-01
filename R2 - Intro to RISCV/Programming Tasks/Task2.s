
.data
    #initialize array
array: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

.text
main:
    # call function
    jal ra, dataArray
end:
    li a0, 10
    ecall
    
dataArray:
    addi sp, sp, -8
    sw s0, 0(sp)
    sw ra, 4(sp)
    # set s0 = i = 0
    li s0, 0

for:
    #set count = 10
    addi t0, x0, 10
    # if ( i < = 10 ); then return the value
    bge s0, t0, return
    # set argument registers, a0 should hold num, now set a2 = i
    add a1, x0, s0
    li a0, 3
    
    #Compare function call
    jal ra, compare
    # t1 = &array
    la t1, array
    #calculate offset for array[i]
    slli t2, s0, 2
    #add the offset to base address of array ( &array + &ith integer)
    add t1, t1, t2
    #dereference value array[i] = a0 = return value of compare(num, i)
    sw a0, 0(t1)
    
    mv a1, a0
    addi a0, x0, 1
    ecall
    
    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall
    
    #increment the counter i = i + 1
    addi s0, s0, 1
    j for

compare:
    addi sp, sp, -4
    sw ra, 0(sp)
    jal ra, subtract
    blt a0, x0, else
    addi a0, x0, 1
    lw ra, 0(sp)
    addi sp, sp, 4
    jr ra
else:
    addi a0, x0, 0
    lw ra, 0(sp)
    addi sp, sp, 4
    jr ra

subtract:
    sub a0, a0, a1
    jr ra
    
return:
    lw s0, 0(sp)
    lw ra, 4(sp)
    jr ra