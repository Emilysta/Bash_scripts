#!/bin/bash

ulimit -u 300
./zadanie8.sh &

echo "Liczba procesow:" $(ps -u emilia | wc -l)
echo "Liczba procesow:" $(ps -u emilia | wc -l)
echo "Liczba procesow:" $(ps -u emilia | wc -l)
echo "Opanowanie sytuacji - zabijam wszystkie utworzone procesy"
pkill -9 -f "zadanie8.sh"
sleep 3
echo "Koncze prace"


