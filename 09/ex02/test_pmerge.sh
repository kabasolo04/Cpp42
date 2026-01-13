#!/bin/bash

GREEN="\033[1;32m"
RED="\033[1;31m"
YELLOW="\033[1;33m"
RESET="\033[0m"

MAX_SIZE=3500
CYCLE=1

echo -e "${YELLOW}🚀 Pmerge tester started (random values, sizes 1→${MAX_SIZE}, infinite)${RESET}"
echo

while true; do
	echo -e "${YELLOW}🔁 Cycle #$CYCLE${RESET}"

	for ((SIZE=1; SIZE<=MAX_SIZE; SIZE++)); do
		# New seed per size (reproducible)
		SEED=$RANDOM
		RANDOM=$SEED

		args=""
		for ((i=1; i<=SIZE; i++)); do
			args="$args $((RANDOM % 10000))"
		done

		output=$(./Pmerge$args 2>&1)

		if echo "$output" | grep -qi "no"; then
			echo -e "\n${RED}❌ FAILED${RESET}"
			echo -e "${RED}➡ Cycle $CYCLE | SIZE=$SIZE | SEED=$SEED${RESET}"

			{
				echo "CYCLE=$CYCLE SIZE=$SIZE SEED=$SEED"
				echo "$args"
				echo "OUTPUT:"
				echo "$output"
				echo "-----------------------------"
			} >> error_test

			echo -e "${RED}➡ Logged in error_test${RESET}"
		fi

		printf "\r${GREEN}✅ Cycle %-4d | Tested SIZE=%-4d${RESET}" "$CYCLE" "$SIZE"
	done

	echo
	((CYCLE++))
done
