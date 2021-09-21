counter=0
while [ $counter -lt 100 ]
do
if [ -e locked.txt ]; then
.
else
echo $(expr $(tail -1 file.txt) + 1) >> file.txt
touch locked.txt
counter=$(expr $counter + 1)
fi
done