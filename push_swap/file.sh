for ((i = 0; i< 10000; i++))
do
ARG=$(seq 0 99 | sort -R)
./push_swap $ARG | ./checker $ARG
done
