#!/bin/bash

PASS=0
FAIL=0

for file in tests/lexer/*.js
do
    base=$(basename "$file" .js)

    # Skip error tests
    if [[ "$base" == error_* ]]; then
        echo "SKIP: $base (error test)"
        continue
    fi
    
    ./build/kelp "$file" > /tmp/out.txt
    
    diff -w /tmp/out.txt "tests/lexer/$base.expected"

    if [ $? -eq 0 ]; then
        echo "PASS: $base"
        PASS=$((PASS+1))
    else
        echo "FAIL: $base"
        FAIL=$((FAIL+1))
    fi
done

echo
echo "Passed: $PASS"
echo "Failed: $FAIL"