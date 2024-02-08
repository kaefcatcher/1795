#!/bin/bash

param=$(./parser.sh "$1")

if [ $? -eq 0 ]; then
    ./waf --run "scratch/HIGHWAY ($param) --Periodic"
else
    echo "Error: Parameter '$1' not found in config file."
fi