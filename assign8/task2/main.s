main:
  pushl %ebp
  movl %esp,%ebp
  subl $12,%esp
  pushl %ebx
  pushl %esi
  movl $13,-4(%ebp)
  movl $5,-8(%ebp)
  movl -4(%ebp),%eax
  cltd
  idivl -8(%ebp)
  movl %edx,%esi
  movl %eax,%ebx
  movl -8(%ebp),%ebx
  subl %esi,%ebx
  movl -4(%ebp),%eax
  imull %ebx,%eax
  movl %eax,-12(%ebp)
  leal -20(%ebp),%esp
  popl %esi
  popl %ebx
  leave
  ret
