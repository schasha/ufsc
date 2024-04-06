.data
# Arranjo inicializado com elementos N não nulos. 
_array: .word 3:N	   # N elementos com o valor 3
_size: .word N  	   # tamanho do arranjo

.text
.globl main

main:
    la $a0 _array      # $a0 = &array
    lw $a1 _size       # $a1 = size
    jal clear2
    li  $v0,10
    syscall
    
clear2:     
   ori $t0, $a0, 0     # $t0 <- $a0
   sll $t1, $a1, 2     # $t1 <- size*4
   add $t2, $a0, $t1   # $t2 <- &array[size]
loop2:
   slt $t3, $t0, $zero # $t3 = (p < &array[size])
   beq $t3, $zero Exit # se (p >= &array[size]) desvia para Exit
   sw $zero, 0($t0)    # mem[p] = 0
   addi $t0, $t0, 4    # p = p + ?
   j loop2
   
Exit:
   jr $ra
