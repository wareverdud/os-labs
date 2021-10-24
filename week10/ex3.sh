touch _ex3.txt
echo "Exercise 3" > _ex3.txt
touch ex3.txt
chmod a-x _ex3.txt > ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod u=rwx _ex3.txt >> ex3.txt
chmod o=rwx _ex3.txt >> ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod g=u _ex3.txt >> ex3.txt
ls -l _ex3.txt >> ex3.txt
echo "chmod 660 means rw- for user, rw- for group and --- for others" >> ex3.txt
echo "chmod 775 means rwx for user, rwx for group and r-x for others" >> ex3.txt
echo "chmod 777 means rwx for user, rwx for group and rwx for others" >> ex3.txt
