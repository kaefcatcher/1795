#!/bin/bash

config_file="config.txt"

while IFS= read -r line; do
    line=$(echo "$line" | sed 's/#.*//')

    if [[ $line =~ ^([^\s=]+)=([^;]+) ]]; then
        param="${BASH_REMATCH[1]}"
        value="${BASH_REMATCH[2]}"
        echo "--$param=$value "
    fi
done < "$config_file"

