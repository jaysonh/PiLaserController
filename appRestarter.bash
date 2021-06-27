#!/bin/bash
while :; do
	sleep 5
	if test -f ".restart"; then
    		echo "restarting app"
		rm .restart
		sleep 2
		./main.exe &
		sleep 5
	fi
done
