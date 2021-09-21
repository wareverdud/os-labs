counter=0
while [ $counter -lt 100 ]
do
if [ -e locked.txt ]; then
echo $(expr $(tail -1 file.txt) + 1) >> file.txt
rm locked.txt
counter=$(expr $counter + 1)
fi
done