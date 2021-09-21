counter=0
while [ $counter -lt 100 ]
do
if [ -e file.lock ]; then
.
else
ln file.txt file.lock
echo $(expr $(tail -1 file.txt) + 1) >> file.txt
rm file.lock
counter=$(expr $counter + 1)
fi
done