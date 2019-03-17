echo "Enter a string"
read str
echo "Enter which character to be replaced"
read ch
echo "Enter the replacement"
read rep
echo "$str" | tr "$ch" "$rep"
