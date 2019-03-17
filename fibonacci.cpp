echo "enter how many terms"
read n
a=0
b=1
echo "The fibonacci sequence is:"
echo $a
echo $b
for((i=0;i<$n-2;i++))
do
c=$((a+b))
a=$b
b=$c
echo $c
done
