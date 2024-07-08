#!/bin/bash

PROBLEM_PATH="problems/*"
OUTPUT_PATH="results"

for folder in $PROBLEM_PATH; do
    for trash in "runner" "solution" "tc" ".cph" "*.aux" "*.bin" "*.exe" "*.fdb_latexmk" "*.fls" "*.log" "*.out" "*.synctex.gz" "*.zip" ; do
        rm -rfv $folder/$trash
    done
    rm -rfv $OUTPUT_PATH
done
