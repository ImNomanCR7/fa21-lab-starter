.globl factorial

.text              
 # start code here
main:
    la t0, num      # t0 = address of num
    lw a0, 0(t0)    # a0 = num
    jal factorial
    j exit

factorial:
    addi sp, sp, -8
    sw ra, 0(sp)
    sw a0, 4(sp)
    li t1, 1
    bgt a0, t1, else
    li a0, 1
    lw ra, 0(sp)
    addi sp, sp, 8
    jr ra

else:
    addi a0, a0, -1
    jal factorial
    lw t2, 4(sp)
    lw ra, 0(sp)
    addi sp, sp, 8
    mul a0, t2, a0
    jr ra
exit:
    add a1, a0, x0
    li a0, 1
    ecall
    li a0, 10
    ecall
    
# end code here

write_tohost:

li x1, 1

sw x1, tohost, t5

j write_tohost

.data 

# start data section here
num: .word 8
result: .word 1
# end data section here

.align 12
.section ".tohost","aw",@progbits;                            
.align 4; .global tohost; tohost: .dword 0;                     
.align 4; .global fromhost; fromhost: .dword 0;
