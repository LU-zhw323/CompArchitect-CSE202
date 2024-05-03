.global fn6args
fn6args:
  subl %edi, %ecx
  imul %ecx, %ecx
  
  subl %esi, %r8d
  imul %r8d, %r8d
  addl %r8d, %ecx
  subl %edx, %r9d
  imul %r9d, %r9d
  addl %r9d, %ecx      #end of calcuation before square root
  movl $0, %eax

.squareRoot:
  
  incl %eax
  movl %eax, %r10d
  imul %r10d, %r10d
  cmp %ecx, %r10d
  jle .squareRoot      #incrementing %rax til me find square root
  decl %eax
  
  ret