#!/bin/bash
  echo "Type Long"
  echo -e "Size\tNo-opt\t\tNo-mem\t\t2x1\t\t2x2\t\t4x1\t\t4x4\t\t8x1\t\t8x8"
  for n in {100..500..100}; do
     gcc -O0 -DN=$n -DLONG -oprog3 prog3.c
     ./prog3
  done
  echo "Type Double"
  echo -e "Size\tNo-opt\t\tNo-mem\t\t2x1\t\t2x2\t\t4x1\t\t4x4\t\t8x1\t\t8x8"
  for n in {100..500..100}; do
     gcc -O0 -DN=$n -DDOUBLE -oprog3 prog3.c
     ./prog3
  done
