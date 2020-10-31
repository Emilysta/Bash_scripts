#!/bin/bash

./zadanie6.sh &
numerPid=$!;
echo "$numerPid"
sleep 5
kill -19 $numerPid
echo "zatrzymano proces";
sleep 5
kill -18 $numerPid
echo "wznowiono proces";
sleep 10
kill -9 $numerPid
# SIGSTOP to jest to samo co CTRL+Z
# SIGCONT według mnie jest bliższe bg
# SIGCONT wznawia proces uzywając "&" czyli wznawia go w tle
# jesli uruchamiamy proces ponownie uzywając bg nasz proces
# uruchomi się z dodatkiem "&"
# zatem tak samo jak przy SIGCONT
# uruchomienie w tle łatwo sprawdzić klikając na terminal i wciskając ctrl+c
# zauważymy wtedy że nasz nie działa to w stosunku do skryptu zadanie6.sh
 

