n_procs=1000
#start=`date +%s%N`
pids=()
lats=()
range=$(seq $n_procs)
start=`date +%s%N`
#echo $range
# run processes and store pids in array
for i in $range; do
    ./main.out&
    pids[${i}]=$!
done

# wait for all pids
for pid in ${pids[*]}; do
    wait $pid
done
end=`date +%s%N`
echo Execution time was `expr $end - $start` nanoseconds for $n_procs clients.
