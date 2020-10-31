#!/bin/bash
echo "Pisanie2"
i=100;
while true;
do
	echo "$i">potok;
	echo "$i"
	i=$((i+1));
	sleep 1
done;
