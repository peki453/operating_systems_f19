#! /bin/bash

file="output.txt"
lock="${file}.lock"

# for searching
re='[+-]?[0-9]+$'

# set current number to be 1
current=1

# check if file exist, if it does not, create file with number 1
if [ ! -f $file ]
then
echo 1 > $file
fi

# check if there is another process using the same file
while [ -f $lock ]
do
: # wait
done

# If file exists, add next number (last number in file + 1)
ln -s $file $lock	
while read line
do
for word in $line
do
if [[ $word =~ $re ]]
then
current=$word
fi
done
done < $file
((current++))
echo $current >> $file

# remove locking
rm $lock

# ****** Result ******
# Every time when we run this script there will be added new number to file output.txt (1, 2, 3, 4, 5...).
# If file output.txt does not exist, it will be created by this script with initial number 1.