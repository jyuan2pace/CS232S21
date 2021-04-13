main:
  pushl %ebp
  movl %esp,%ebp
  subl $12,%esp
  movl $13,-4(%ebp)
  movl $5,-8(%ebp)
  movl $0,-12(%ebp)
  cmpl $6,-4(%ebp)
  jle .L2
  movl $15,-8(%ebp)
.L2:
.L3:
  cmpl $14,-12(%ebp)
  jg .L4
  movl -12(%ebp),%eax
  addl %eax,-4(%ebp)
  incl -12(%ebp)
  jmp .L3
.L4:
  leave
  ret
