password:
  .byte 0x73,0x65,0x63,0x72,0x65,0x74,0x0
.LC0:
  .byte 0x70,0x6c,0x65,0x61,0x73,0x65,0x20,0x65,0x6e,0x74
  .byte 0x65,0x72,0x20,0x79,0x6f,0x75,0x72,0x20,0x70,0x61
  .byte 0x73,0x73,0x77,0x6f,0x72,0x64,0xa,0x0
.LC1:
  .byte 0x25,0x73,0x0
main:
  pushl %ebp
  movl %esp,%ebp
  subl $12,%esp
  pushl %ebx
  pushl $.LC0
  call printf
  leal -8(%ebp),%eax
  pushl %eax
  pushl $.LC1
  call scanf
  movl $0,-12(%ebp)
  leal 12(%esp),%esp
.L2:
  cmpl $7,-12(%ebp)
  jg .L3
  movl %ebp,%eax
  addl -12(%ebp),%eax
  leal -8(%eax),%eax
  cmpb $64,(%eax)
  jle .L5
  movl %ebp,%eax
  addl -12(%ebp),%eax
  leal -8(%eax),%eax
  cmpb $90,(%eax)
  jg .L5
  movl %ebp,%eax
  addl -12(%ebp),%eax
  leal -8(%eax),%eax
  movl %ebp,%edx
  addl -12(%ebp),%edx
  leal -8(%edx),%edx
  movb (%edx),%cl
  addb $32,%cl
  movb %cl,(%eax)
.L5:
  incl -12(%ebp)
  jmp .L2
.L3:
  pushl $password
  leal -8(%ebp),%eax
  pushl %eax
  call strcmp
  movl %eax,%ebx
  leal 8(%esp),%esp
  cmpl $0,%ebx
  jne .L6
  xorl %eax,%eax
  jmp .L1
  jmp .L7
.L6:
  movl $-1,%eax
  jmp .L1
.L7:
.L1:
  leal -16(%ebp),%esp
  popl %ebx
  leave
  ret
