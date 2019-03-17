echo Enter the number
read n
fact=1
for((i=$n;i>1;i--))
do
fact=$((fact*i))
done
echo "The factorial of a number is" $fact
