echo 0 > num.txt


#race condition will not occur  after following changes:
if ln num.txt num.txt.lock
  then
  while true;
    do
      n=$(tail -1 num.txt | grep -Eo '[0-9]+$')
      n=$(($n + 1))
      echo $n >> num.txt 
    done
    rm num.txt.lock
fi
