n_procs=2
start=`date +%s%N`
pids=()
range=$(seq 1 8)
echo $range
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
echo Execution time was `expr $end - $start` nanoseconds.
