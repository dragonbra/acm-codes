%#!/bin/bash
while true; do
    ./r > input
    ./A < input > output.a
    diff output.a output.b
    if [ $? -ne 0 ] ; then break; fi
done