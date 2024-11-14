#!/bin/bash

SEED=$RANDOM
ARG=()
SIZE=$1

for i in $(seq 1 $SIZE)
do
	SEED=$((7**5*$SEED%(2**31-1)))
	ARG+=($(($SEED-2**30)))
done

RES="$(./push_swap ${ARG[@]})"
echo "${ARG[@]}"
echo "$RES" | wc -l
echo "$RES" | ./checker_linux ${ARG[@]}
