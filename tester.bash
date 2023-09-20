#!/bin/bash

BINARY=./build/philo/philo

NPHILO_MAX=200
NPHILO_MIN=2
NTESTS=100

NMEAL_MAX=100
NMEAL_MIN=1

FILENAME=tmp

for i in $(seq 1 ${NTESTS}); do
  NPHILO=$(($RANDOM % ($NPHILO_MAX - $NPHILO_MIN) + $NPHILO_MIN));
  NMEAL=$(($RANDOM % ($NMEAL_MAX - $NMEAL_MIN) + $NMEAL_MIN));
  echo -n "Test ${i} with ${NPHILO} philosophers and ${NMEAL} meals";
  ${BINARY} ${NPHILO} 800 200 200 ${NMEAL} > ${FILENAME};
  if [ $? -ne 0 ]; then
    echo -e "\eError: ${BINARY} ${NPHILO} 800 200 200 ${NMEAL} > ${FILENAME}";
    exit 1;
  fi
  LASTPHILO=$(cat ${FILENAME} | grep -iE "[0-9]+ [0-9]+ is eating" | tail -n 1 | awk '{print $2}');

done