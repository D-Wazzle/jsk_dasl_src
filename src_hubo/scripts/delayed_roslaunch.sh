#!/bin/bash

echo "delaying: $1 seconds"
sleep $1
shift
echo "starting: roslaunch $@"
roslaunch $@