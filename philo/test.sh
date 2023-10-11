#!/bin/bash

COMMAND=./philo
TIMES=100
NPHILO=100
FILE=tmp
BUFF=""

function exec_command() {
	MAXEAT=$1
	BUFF=""
	$COMMAND $NPHILO 60 10 10 $MAXEAT>$FILE

	for i in $(seq 1 $NPHILO); do
		NEAT=$(cat $FILE | grep -iE '[0-9]+ '"$i"' is eating' | wc -l)
		BUFF="$BUFF $NEAT"
	done

	MIN=$(min "$BUFF")
	if (( $MIN == $1 )); then
		return 0;
	else
		return 1;
	fi
}

for i in $(seq 1 $TIMES); do
	exec_command $i
	echo $?
done
