#!/bin/bash

remove_output_file()
{
	rm $1
}
filename=$1
outputname=$2
# Check number of parameter
if [ $# != 2 ]
then
	echo "invalid parameter"
	exit 0
fi
# Check existing input file
if [ -f $filename ]
then 
	echo "Input file existing" >/dev/null
else
	echo "Input file not existing"
	exit 0
fi
# Remove output file if existing
if [ -f $outputname ]
then
	remove_output_file $outputname
fi
# Read in line and writing to output file 
while read line
do
    # display $line or do somthing with $line
	echo $line >temp.txt
	#columeNum=$(awk 'BEGIN {FS=":"};END{print NF}' temp.txt)
	for ((i=1;i<6;i++))
	do
		case $i in
		1) Mr=$(awk 'BEGIN {FS=":"}{print $1}' temp.txt);;
		2) Year=$(awk 'BEGIN {FS=":"}{print $2}' temp.txt) ;;
		3) Sex=$(awk 'BEGIN {FS=":"}{print $3}' temp.txt);;
		4) Company=$(awk 'BEGIN {FS=":"}{print $4}' temp.txt);;
		5) phone=$(awk 'BEGIN {FS=":"}{print $5}' temp.txt);;
		*) echo "error"
		esac
	done
	echo "Mr $Mr, $Year years old, sex is $Sex, work in $Company company, telephone number is $phone" >> $outputname
done <$filename
