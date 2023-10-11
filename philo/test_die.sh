#!/bin/bash

COMMAND=./philo
FILE=tmp
TIMES=100

#colors
RED='\e[0;31m'
GREEN='\e[0;32m'
NC='\e[0m'

function gen_cmd() {
	COMMAND="./philo $1 $2 $3 $4 $5"
}

function gen_and_check() {	
	NPHILO=$(($RANDOM % 198 + 2))
	TTD=$(($RANDOM % 1940 + 60))
	TTE=$(($RANDOM % 940 + 60))
	TTS=$(($RANDOM % 940 + 60))
	MIN_EAT=$(($RANDOM % 10 + 1))

	if (($NPHILO % 2 == 0)); then
		#even checking
		if (($TTD - $TTE - $TTS > 10)); then
			return 0
		else
			return 1
		fi
	else
		return 1
	fi
}

function test_one() {
	FILE="tmp_$1"
	gen_and_check
	while (($? == 1)); do
		gen_and_check
	done
	gen_cmd $NPHILO $TTD $TTE $TTS $MIN_EAT
	$COMMAND>$FILE
	RESULT=$(cat $FILE | grep "died" | wc -l)
	if (($RESULT == 0)); then
		printf "%-50s|${GREEN}%-10s${NC}|%-10s\n" "$COMMAND" "OK" "$FILE"
	else
		printf "%-50s|${RED}%-10s${NC}|%-10s\n" "$COMMAND" "KO" "$FILE"
	fi

}

for i in {1..10}; do
	test_one $i
done

