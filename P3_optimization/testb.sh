#!/bin/bash
  echo "Type Long"
  echo -e "Size\tijk\t\tjik\t\tjki\t\tkji\t\tkij\t\tikj"
  for n in {100..500..100}; do
     gcc -O0 -DN=$n -DLONG -oprog3b prog3b.c
     ./prog3b
  done

  echo "Type Double"
  echo -e "Size\tijk\t\tjik\t\tjki\t\tkji\t\tkij\t\tikj"
  for n in {100..500..100}; do
    gcc -O0 -DN=$n -DDOUBLE -oprog3b prog3b.c
    ./prog3b
  done
