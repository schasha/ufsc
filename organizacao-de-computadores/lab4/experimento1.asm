.data
# Arranjo inicializado com elementos N não nulos.
_array: .word 3:N		  # N elementos com o valor 3
_size: .word N  		  # tamanho do arranjo

.text
.globl main

main:
    la $a0 _array         # $a0 = &array
    lw $a1 _size          # $a1 = size
    jal clear1
    li  $v0,10
    syscall

clear1:
   add $t0, $zero, $zero  # i=0
loop1:
   slt $t3, $t0, $a1       # $t3 = (i < size)
   beq $t3, $zero Exit    # se (i >= size) desvia para Exit
   sll $t1, $t0, 2        # i = i * 4
   add $t2, $a0, $t1      # $t2 = &array[i]
   sw $zero, 0($t2)       # array[i] = 0
   addi $t0, $t0, 1       # i++
   j loop1
   
 Exit:
   jr $ra
