#!/bin/sh

output_file=16987

# Compile the source file
g++ -Wall -Wextra -ggdb -o "$output_file" "$output_file".cpp

line_number=1
failed=false

for f in input*.txt; do
    output=$(./"$output_file" < "$f")
    answer_line=$(sed -n "${line_number}p" answer.txt)


    if [ "$output" = "$answer_line" ]; then
        echo "### $output $answer_line SUCCESS: Test Case Correct for $f ###"
    else
        echo "### $output $answer_line WARNING: Test Case Failed for $f ###"
        failed=true
    fi
    
    line_number=$((line_number + 1))
done

if ! $failed; then
    echo "### Test Case All correct ###"
fi

# Clean up the compiled program
rm "$output_file"
