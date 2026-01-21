#!/bin/bash
loops=5
i=0
sum=0
echo 'enter the exponent for counter.cpp:'
read var1
if ! [[ var1 == quit ]]; then
    while [[ i -lt loops ]]; do
	echo "Running iteration $((i + 1))..." 
	RUNNING_TIME=`./a.out ${var1}`
	let sum=sum+RUNNING_TIME
	echo "time taken: ${RUNNING_TIME} ms"
	let i=i+1
    done
else
    exit
fi
echo "${loops} iterations took ${sum} ms"
echo "Average time was $(( sum / loops ))"
