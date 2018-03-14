#!/bin/bash
#
#
#Parse one of the memory columns from the output of vmstat or the free comand. And if the memory value exceeds a certain threshold for more than a certain timeframe, then print a report to alert the Ops team
#
#
s=249300

for ((i=0; i < 30; i++)); do
 vmstat > vm
 m=`awk 'NR==3{print $4}' vm`
 if [ "$m" -gt "$s" ]; then 
	echo "normal free"
 else
	echo "abnormal memory" > abnormal
	t=`date`
	cat abnormal | mail -s "abnormal event-$t" binqbu2002@gmail.com
 fi
 sleep 1
done
