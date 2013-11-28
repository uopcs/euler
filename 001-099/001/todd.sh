sum=0;
for (( i=0; i < 1000; i++ ));
do
        if [ "$((i % 3))" == "0" ];
        then
                sum=$((sum+i));
        elif [ "$((i % 5))" == "0" ];
        then
                sum=$((sum+i));
        fi;
done;
echo "$sum";
