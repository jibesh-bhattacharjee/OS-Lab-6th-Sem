#!/bin/bash
echo ""
echo "The kernal version is: "
cat /proc/version
echo ""
echo "Now displaying Hostname & Username, current date and calendar:"
hostname
echo "$USER"
date
cal
echo ""
echo "Displaying how long system has been running:"
last reboot
echo ""
echo "Showing memory status:"
free

