echo "Ruslan" > file1.txt
echo "Khakimov" > file2.txt
gcc ex2.c -o ex2.out
sudo cp file1.txt ./lofsdisk
sudo cp file2.txt ./lofsdisk
sudo cp ex2.out ./lofsdisk

cd lofsdisk
sudo mkdir ./bin
sudo cp /bin/bash ./bin
sudo cp /bin/ls ./bin
sudo cp /bin/cat ./bin
sudo cp /bin/echo ./bin
# Libraries for bash
sudo mkdir ./lib
sudo mkdir ./lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libtinfo.so.6 ./lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libdl.so.2 ./lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libc.so.6 ./lib/x86_64-linux-gnu
sudo mkdir ./lib64
sudo cp /lib64/ld-linux-x86-64.so.2 ./lib64
# Libraries for ls
sudo cp /lib/x86_64-linux-gnu/libselinux.so.1 ./lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libpcre2-8.so.0 ./lib/x86_64-linux-gnu
#sudo cp /lib/x86_64-linux-gnu/libdl.so.2 ./lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libpthread.so.0 ./lib/x86_64-linux-gnu
# Libraries for cat and echo have already been copied
cd ..

sudo chroot ./lofsdisk ./ex2.out > ex2.txt
echo "Without changing root" >> ex2.txt
./ex2.out >> ex2.txt
