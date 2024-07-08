#!/bin/sh

# Usage: bash generate-problem.sh <id> <problem-slug/folder-name> <problem-name> <time-limit> <memory-limit> <dest-folder>
# bash generate-problem.sh subgraph arkavidia-2021-subgraph-divisibility "Subgraph Divisibility" 2 128 Final
# bash -i generate-problem.sh tes generate "tes" 2 128 temp

# read -p 'Probid: ' PROBID
# read -p 'Problem folder name: ' PROBLEM_SLUG
# read -p 'Problem name: ' PROBLEM_NAME
# read -p 'Time Limit: ' TIME_LIMIT
# read -p 'Memory Limit: ' MEM_LIMIT

PROBID=$1
PROBLEM_SLUG=$2
PROBLEM_NAME=$3
TIME_LIMIT=$4
MEM_LIMIT=$5
DEST_FOLDER=$6

CPP_VERSION=c++17

mkdir -p $DEST_FOLDER

# Generate statement, solution, and testcases
echo "preparing problem"
cd "$PROBLEM_SLUG"
# pdflatex "statement.tex"
# rm -f *.aux *.log *.dvi *.out *.toc *.synctex.gz

g++ solution.cpp -O2 -Wall -o solution -std=$CPP_VERSION
$TCFRAME_HOME/scripts/tcframe build
./runner
cd - > /dev/null

echo "creating problem"
TEMP_FOLDER=$DEST_FOLDER/temp
rm -rf "$TEMP_FOLDER"
mkdir "$TEMP_FOLDER"
cd "$TEMP_FOLDER"

# Generate domjudge-problem.ini
echo "probid=$PROBID" > domjudge-problem.ini
echo "timelimit='$TIME_LIMIT'" >> domjudge-problem.ini

# Generate problem.yaml
echo "---" > problem.yaml
echo "name: $PROBLEM_NAME" >> problem.yaml

cd - > /dev/null
FILE=$PROBLEM_SLUG/validator.cpp # whether custom checker is used
if test -f "$FILE"; then
    echo "validation: custom" >> $TEMP_FOLDER/problem.yaml
    # Add validator
    mkdir "$TEMP_FOLDER/output_validators"
    cp "$PROBLEM_SLUG/validator.cpp" "$TEMP_FOLDER/output_validators/validator.cpp"
fi

cd "$TEMP_FOLDER"
echo "limits:" >> problem.yaml
echo "    memory: $MEM_LIMIT" >> problem.yaml

# Add testcase
cd - > /dev/null
mkdir -p "$TEMP_FOLDER/data/secret"
for testcases in "$PROBLEM_SLUG/tc/*"; do
    cp $testcases "$TEMP_FOLDER/data/secret"
done

cd "$TEMP_FOLDER/data/secret"
# rm -f *_sample_*
rename 's/\.out$/.ans/' *
rename 's/^.*_//' *
cd - > /dev/null

# Add statement
cp "$PROBLEM_SLUG/statement.pdf" "$TEMP_FOLDER/problem.pdf"

# zipping everything
cd $TEMP_FOLDER
zip -r "problem.zip" "." > /dev/null
cd -

cp "$TEMP_FOLDER/problem.zip" "$DEST_FOLDER/$PROBID.zip"
mv "$TEMP_FOLDER/problem.zip" "$PROBLEM_SLUG/$PROBID.zip"

echo "creating problem complete"
