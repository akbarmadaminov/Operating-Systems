echo 0 > num.txt


#race condition can occur, can get file which didn't changed
while true;
do
	n=$(tail -1 num.txt | grep -Eo '[0-9]+$')
	n=$(($n + 1))
	echo $n >> num.txt 
done
