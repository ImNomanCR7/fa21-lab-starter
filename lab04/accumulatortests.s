.import lotsofaccumulators.s

.data
inputarray: .word 1,2,3,4,5,6,7,0
inputarray1: .word 0,1,2,3,4,5,6,7,0


TestPassed: .asciiz "Test Passed!"
TestFailed: .asciiz "Test Failed!"

.text
# Tests if the given implementation of accumulate is correct.
#Input: a0 contains a pointer to the version of accumulate in question. See lotsofaccumulators.s for more details
#
#
#
#The main function currently runs a simple test that checks if accumulator works on the given input array. All versions of accumulate should pass this.
#Modify the test so that you can catch the bugs in four of the five solutions!
main:
    
    la a0, inputarray    # for accumulators 1 to 4
    
    # ****** Uncomment below statement for Accumulator 5 only ******* #
    la a0 inputarray1   # fail accumulatorfive
    
    li s0, 3    #fail accumulatorone
    li t2, 12    #fail accumulatortwo
    addi sp, sp, -4
    sw t2, 0(sp)
    
    jal accumulatorfive
    
    lw t1, 0(sp)
    addi sp, sp, 4
    li t3, 3
    bne t3, s0, Fail    #fail accumulatorone
    bne t2, t1, Fail    #fail accumulatortwo & accumulatorfour
    beq a0 x0 Fail
    
    li t0, 28
    li t0, 0           # fail accumulatorfive (please uncomment for accumulator 5)
    bne a0, t0, Fail
    j Pass
    
Fail:
    la a0 TestFailed
    jal print_string
    j End
Pass:
    la a0 TestPassed
    jal print_string
End:
    jal exit

print_int:
	mv a1 a0
    li a0 1
    ecall
    jr ra
    
print_string:
	mv a1 a0
    li a0 4
    ecall
    jr ra
    
exit:
    li a0 10
    ecall
