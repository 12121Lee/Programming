#!/bin/bash
if [[ $* -eq 0 ]]; then
	echo "usage: $0 percentage"
	exit 127
fi
for (( i = 0; i <= 100; i += $1 )); do
	./loading $i
	sleep 1
	clear
done