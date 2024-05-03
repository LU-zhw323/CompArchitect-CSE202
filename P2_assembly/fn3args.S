.global fn3args
fn3args:
  testl %edi,%edi 
  jl .L2
  testl %esi,%esi
  jl .L3
  testl %edx,%edx
  jl .L4                  #check zero
  movl %edi, %eax
  addl %esi, %eax
  imul %edx, %eax
  movb $00000000, %bl     #check accuracy
  xorb %al, %bl
  testb $00000001, %bl
  jne .L5
  sarl $1, %eax
  ret
.L2:
  movl $0, %eax
  ret
.L3:
  movl $0, %eax
  ret
.L4:
  movl $0, %eax
  ret
.L5:
  movl $0, %eax
  ret

