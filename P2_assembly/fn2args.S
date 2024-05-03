.global fn2args
fn2args:

  movl %edi, %eax
  cmpl %esi, %eax
  js .L2         #find out which one is greater
  subl %esi, %eax
  ret

.L2:
  subl %esi, %eax
  negl %eax
  ret
  