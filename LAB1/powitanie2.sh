#!/bin/bash

dzien=$(echo "$(LC_TIME=C date)" | awk '{print $1;}');
if [[ $dzien != "Sun" ]] && [[ $dzien != "Sat" ]] ;
then
echo "Zapowiada się ciekawy dzien w pracy";
else
echo "Milego weekendu";
fi
