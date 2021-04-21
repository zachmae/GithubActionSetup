#!/usr/bin/env bash

## Variables
SCORE=0
TOTAL=0

function test()
{
  TOTAL=$((TOTAL+1))

  echo "Test $TOTAL $1 [$2 $3 $4]"
  ./do-op $2 $3 $4

  if [[ $? -eq 84 ]]; then
    SCORE=$((SCORE+1))
    echo "./do-op $1 $2 $3 success"
  else
    echo "./do-op $1 $2 $3 failed"
  fi
}

test "Missing member2" "1" "+" ""
test "Missing member1" "" "+" "1"
test "Missing operator" "1" "" "1"

test "Letter in expression" "a" "+" "1"
test "Letter in expression" "a23Da" "+" "1"
test "Letter in expression" "1" "sdfds" "1"
test "Letter in expression" "2" "+" "aaa1RDSDcd"
test "Letter in expression" "a" "+" "a"

if [[ "$TOTAL" != "$SCORE" ]]; then
  echo "Test failed"
  exit 84
else
  echo "Test success"
fi
