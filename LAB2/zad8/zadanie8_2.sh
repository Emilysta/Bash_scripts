#!/bin/bash

./zadanie8.sh &

ulimit -n 300
echo $(ps -a | grep "zadanie8.sh" | wc -l)

pkill -f "zadanie8.sh"


