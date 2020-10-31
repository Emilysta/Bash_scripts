#!/bin/sh
trap 'echo "Nie zniszczysz mnie za pomocą CTRL+C "' INT;
trap 'echo "Nie będę wykonywal zrzutu pamieci i konczyl pracy! "' QUIT;
trap 'echo "Bledy w implementacji systemu tez Ci nie pomoga mnie zabic! "' ILL;
trap 'echo "Teraz nie mozesz mnie zatrzymac wiec nie bedzie tez mozliwe wzowienie "' STOP;
trap 'echo "Wznowienie niemozliwe"' CONT;
trap 'echo "Zamkniecie terminala tez nic nie da - zerwanie lacznosci "' HUP;
trap 'echo "Pulapka sledzenia "' TRAP;
trap 'echo "Blas szyny - niewlasciwa implementacja nie zadzialala "' BUS;
trap 'echo "Bledy matematyczne mnie nie pokonaja "' FPE;
trap 'echo "Odwolanie do zlego miejsca pamieci rowniez mnie nie pokona "' SEGV;
trap 'echo "Nie uda ci sie zakonczyc planowo dzialania programu "' TERM;
trap 'echo "Bledy sprzetu nie zabija mnie "' ABRT;
trap 'echo "Mala moc mnie nie pokona "' PWR;
trap 'echo "Wcale nie przekroczylem ograniczenia zuzycia procesora "' XCPU;
trap 'echo "Wcale nie przekroczylem organiczenia rozmiaru plikow "' XFSZ;
trap 'echo "SIGALRM nie zadzaiala "' ALRM;
trap 'echo "SIGPIPE nie zadziala brak odebrania danych z potoku "' PIPE;
trap 'echo "sygnal user1 nie zadziala"' USR1;
trap 'echo "sygnal user2 nie zadziala"' USR2;
trap 'echo "To juz niestety zadziala :( "' KILL ;
while true;
do
	echo $(date +"%H:%M:%S") "PID: $$ ";
	sleep 1
done
