touch ../week01/file.txt
echo "Exercise 2 week10" > ../week01/file.txt
ln ../week01/file.txt _ex2.txt
node=$(stat -c '%i' ../week01/file.txt)
find ~/os-labs/ -inum $node > ex2.txt
find ~/os-labs/ -inum $node -exec rm {} \;
