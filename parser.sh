#!/bin/bash

# Parse config file
config_file="config.txt"

# Read config file line by line
while IFS= read -r line; do
    # Remove comments
    line=$(echo "$line" | sed 's/#.*//')

    # Extract parameter and its value
    if [[ $line =~ ^([^\s=]+)=([^;]+) ]]; then
        param="${BASH_REMATCH[1]}"
        value="${BASH_REMATCH[2]}"
        echo "--$param=$value "
    fi
done < "$config_file"

