.global fn8args
fn8args:
  movq $0, %r9
  movq $0, %r8

  movq $0, %rax
  leaq 16(%rsi), %r10
  movq (%r10), %r10
  movb (%r10), %al
  movq $0, %r10
  leaq 24(%rsi), %r10
  movq (%r10), %r10
  addb (%r10), %al

  movb (%r10), %r9b          #r9 = 4th
  cmpb $49, %r9b      #check 4th argument
  js .L2

  movq $0, %r10
  leaq 32(%rsi), %r10
  movq (%r10), %r10
  addb (%r10), %al

  movb (%r10), %r8b  #r8 = 5th
  cmpb $56, %r8b     #check 5th argument
  jg .L2
  cmpb %r9b, %r8b    #check 4,5th argument
  js .L2
  

  movq $0, %r10
  leaq 40(%rsi), %r10
  movq (%r10), %r10
  addb (%r10), %al
  movq $0, %r10
  leaq 48(%rsi), %r10
  movq (%r10), %r10
  addw (%r10), %ax
  movq $0, %r10
  leaq 56(%rsi), %r10
  movq (%r10), %r10
  addw (%r10), %ax
  



 ret

.L2:
  movq $0, %rax
  ret