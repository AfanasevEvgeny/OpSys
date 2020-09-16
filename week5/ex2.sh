race:
if test ! -f Num
then
    echo 0 > Num
fi

for i in 'seq 1 100':
do
  n=$(tail -n  1 < Num)
  expr $n + 1 >> Num
done

no race:
if test ! -f Numbers
then
    echo 0 > Numbers
fi
if ln Numbers.lock
    then
    for i in 'seq 1 100':
    do
      n=$(tail -n  1 < Numbers)
      expr $n + 1 >> Numbers
    done  
    rm Numbers.lock
fi
