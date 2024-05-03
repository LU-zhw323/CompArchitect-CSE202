#!/bin/bash

echo -e "\nRunning make clean"
make -f makefile clean
echo -e "\nRunning make a.out"
make a.out
rc=$?
points=0
if [[ $rc == 0 ]]; then
  points=$((points + 27)) 
  tests=( 15213
          -15213
          "100 99"
          "1 100"
          "3 6 4"
          "17 -13 5"
          "39 318 115"
          "0 0 0 0 0 0"
          "1 1 1 2 2 2"
          "3 3 3 6 6 6"
          "9 8 0 7 5 3 1 4"
          "9 8 2 9 5 3 1 4"
          "9 8 2 7 5 3 1 4"
          "9 8a 2 7 5b kindOfALongArgument 1 4"
        )
  scores=( 0 0 4 4 4 4 4 4 4 4 4 4 4 4 )
  passed=0
  total=0
  for test in "${tests[@]}"; do
    total=$((total + 1))
    echo -e "\nTest $total with args: $test"
    rm -f /tmp/$$.tmp 2>&1 1>/dev/null
    ./a.out $test 2>/dev/null | tee /tmp/$$.tmp
    diff -w ${total}.out /tmp/$$.tmp
    rc=$?
    if [[ $rc == 0 ]]; then
      echo -e "Test $total passed"
      passed=$((passed + 1))
      tmp=${scores[$total-1]}
      points=$((points + tmp))
    else
      echo -e "Test $total failed"
    fi
  done
  
  if [[ $passed == $total ]]; then
    echo -e "\nAll tests passed"
    rc=0
  else
    failed=$((total-passed))
    echo -e "\n$passed tests passed, $failed tests failed"
    rc=$failed
  fi
else
  echo -e "\nCompilation failed"
fi
echo -e "Score $points/75\n"

exit $rc

