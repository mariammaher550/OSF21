#!/bin/bash
while true; do
line = $( tail -n 1 ex02.txt)
line = $((line + 1))

while ! ln ex02.txt ex02.txt.lock 2> null ; do
sleep 0.1
done
echo $line >> ex02.txt
rm ex02.txt.lock
done


