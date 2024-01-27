.data
    prompt1: .asciiz "Input A: "
    prompt2: .asciiz "Input B: "
    result1: .asciiz "a + b = "
    result2: .asciiz "\na - b = "
    result3: .asciiz "\na * b = "
    result4: .asciiz "\na / b = "
    result5: .asciiz "\na % b = "
    result6: .asciiz "\nError when divide by 0\n"
.text
.globl main

main:
    # Prompt for input A
    li $v0, 4
    la $a0, prompt1
    syscall
    # Read input A
    li $v0, 5
    syscall
    move $s0, $v0
    
    # Prompt for input B
    li $v0, 4
    la $a0, prompt2
    syscall
    # Read input B
    li $v0, 5
    syscall
    move $s1, $v0
 
    # Print A + B
    li $v0, 4
    la $a0, result1
    syscall
    # Calculate a + b
    add $t0, $s0, $s1
    li $v0, 1
    move $a0, $t0
    syscall
    
    # Print a - b
    li $v0, 4
    la $a0, result2
    syscall
    # Calculate a - b
    sub $t0, $s0, $s1
    li $v0, 1
    move $a0, $t0
    syscall
    
    # Print a * b
    li $v0, 4
    la $a0, result3
    syscall
    # Calculate a * b
    mul $t0, $s0, $s1
    li $v0, 1
    move $a0, $t0
    syscall
    
    # Check if b is zero
    beq $s1, $0, exitError
    # Calculate a / b and a % b
    div $s0, $s1
    mflo $t1
    mfhi $t2
    # Get the quotient
    li $v0, 4
    la $a0, result4
    syscall
    li $v0, 1
    move $a0, $t1
    syscall

    # Print modulo
    li $v0, 4
    la $a0, result5
    syscall
    li $v0, 1
    move $a0, $t2
    syscall
    # Exit program
    li $v0, 10
    syscall

exitError:
    # Prompt Error
    li $v0, 4
    la $a0, result6
    syscall
    # Exit program
    li $v0, 10
    syscall
