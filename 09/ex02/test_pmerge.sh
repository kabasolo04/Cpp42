#!/bin/bash

GREEN="\033[1;32m"
RED="\033[1;31m"
YELLOW="\033[1;33m"
RESET="\033[0m"

MAX=5000
MODE="seq"   # seq | rand

echo -e "${YELLOW}🚀 Pmerge tester started (${MODE} mode)${RESET}"
echo

for ((i=1; i<=MAX; i++)); do
	args=""

	if [ "$MODE" = "seq" ]; then
		for ((j=1; j<=i; j++)); do
			args="$args $j"
		done
	else
		for ((j=1; j<=i; j++)); do
			args="$args $((RANDOM % 10000))"
		done
	fi

	output=$(./Pmerge$args 2>&1)

	if echo "$output" | grep -qi "no"; then
		echo -e "${RED}❌ FAILED${RESET}"
		echo -e "${RED}➡ With $i numbers${RESET}"
		echo
		echo "Output:"
		echo "$output"
		exit 1
	fi

	printf "\r${GREEN}✅ OK with %-5d numbers${RESET}" "$i"
done

echo
echo -e "${GREEN}🎉 All tests passed up to $MAX numbers${RESET}"
