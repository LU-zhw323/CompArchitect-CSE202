.global fn1arg  # makes fn1arg visible to the linker (ld)
fn1arg:
  negl %edi
  movl %edi, %eax
  retq
