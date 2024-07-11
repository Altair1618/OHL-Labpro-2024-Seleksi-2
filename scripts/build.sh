#!/bin/bash

PROBLEM_PATH="problems/*"
GENERATOR_PATH="scripts/generate-problem.sh"
OUTPUT_PATH="results"
TIME_LIMIT=3
MEMORY_LIMIT=512

alphabet=({A..Z})
index=0
# folders=$(ls -d $PROBLEM_PATH)
folders=("problems/Pemenang-Permainan-Putar-Putar")
for folder in $folders; do
    # letter=${alphabet[index]}
    letter="PPP"
    problem_name=$(basename "$folder")

    echo "Generating Problem $letter $problem_name"
    $GENERATOR_PATH $letter $folder "$problem_name" $TIME_LIMIT $MEMORY_LIMIT $OUTPUT_PATH
    echo " "
    ((index++))
done
