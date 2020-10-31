#!/bin/bash

./zadanie5.sh &
sleep 5
numerPid=$!;
i=1;
while [ $i -le 8 ];
do
	kill -$i $numerPid
	i=$((i+1));
	sleep 3;
done

kill -9 $numerPid


