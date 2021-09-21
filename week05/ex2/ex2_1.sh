counter=0
while [ $counter -lt 100 ]
do
counter=$(expr $counter + 1)
echo $(expr $(tail -1 file.txt) + 1) >> file.txt
done
#critical region occurs when one process takes last line from the file
#and then another process does the same. so they both get the same last
#line and produce the same output.