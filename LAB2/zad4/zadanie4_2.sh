#!/bin/bash
echo "Pisanie"
i=0;
while true;
do
	echo "$i">potok
	echo "$i"
	i=$((i+1));
	sleep 1;
done;
