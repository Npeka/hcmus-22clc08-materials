.data
    
    inputSize:  .asciiz "Enter size of array (0 < N < 100): "
    inputArray: .asciiz "Input Array:\n"
    outputArray:.asciiz "Output Array: "
    array:      .space 400  # Allocate space for 100 integers
    lArr: 	.asciiz "a["
    rArr: 	.asciiz "] =  "
    space: 	.asciiz " "
    enld:    	.asciiz "\n"
    sumOdd:     .asciiz "Sum of odds: "
.text
.globl main

main:
# Input size N of array
    # Prompt inputSize
    li $v0, 4		
    la $a0, inputSize
    syscall
    # Read input N
    li $v0, 5
    syscall
    move $s0, $v0
    # Check 0 < N < 100
    blt $s0, 1, main
    bgt $s0, 99, main
    
# Input array
    li, $v0, 4
    la, $a0, inputArray
    syscall

    li $t0, 0 # Init Index i = 0
    li $t1, 0 # Init offset i * 4
InputArray:
    # Check i == n
    beq $t0, $s0, InputEnd

    # Promt lArr
    li $v0, 4
    la $a0, lArr
    syscall
    # Print Index
    li $v0, 1
    move $a0, $t0
    syscall
    # Promt rArr
    li $v0, 4
    la $a0, rArr
    syscall

    # Read input a[i]
    li $v0, 5
    syscall
    sw $v0, array($t1) 

    # i++
    add $t0, $t0, 1
    add $t1, $t1, 4
    j InputArray

InputEnd:
# Output Array
    # Promt outputArray
    li, $v0, 4
    la, $a0, outputArray
    syscall
    
    li $t0, 0 # Init Index i = 0
    li $t1, 0 # Init offset i * 4
OutputArray:
    # Check i == n
    beq $t0, $s0, OutputEnd
    
    # Print Array[i]
    li $v0, 1
    lw $a0, array($t1)
    syscall
    # Prompt space
    li, $v0, 4
    la, $a0, space
    syscall

    # i++
    add $t0, $t0, 1
    add $t1, $t1, 4
    j OutputArray

OutputEnd:
# Sum odds number
    la $a1, array   # Load array
    move $a2, $s0   # Load N
    li $a3, 0       # Init Sum = 0
    jal SumOdd      # Goto SumOdd function

    # Prompt enld
    li $v0, 4
    la $a0, enld
    syscall
    # Prompt sumOdd
    li $v0, 4
    la $a0, sumOdd
    syscall
    # Print sum
    li $v0, 1
    move $a0, $a3
    syscall

    # Exit program
    li $v0, 10
    syscall

# Procedure to sum of all the odd elements of the above array
SumOdd:
    addi $sp, $sp, -4
    sw $ra, 0 ($sp)
    li $t0, 0       # Init i = 0
loop:
    # i == n
    beq $t0, $a2, end

    jal Odd		# Call Procedure Odd
    beq $v0, $0, next   # If a[i] is even -> continue

    lw $t1, ($a1)
    add $a3, $a3, $t1   # Sum odd element
next:
    # i++
    add $t0, $t0, 1
    add $a1, $a1, 4
    j loop
end: 
   lw $ra, 0($sp)
   addi $sp, $sp, 4
   jr $ra

# Procedure Odd
Odd:
    lw $t2, ($a1)
    andi $v0, $t2, 1
    jr $ra
