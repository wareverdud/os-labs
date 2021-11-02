#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main() {
	DIR *dir = opendir("/");
	if (dir == NULL) return 0;
	
	struct dirent *file = readdir(dir);
	
	while (file != NULL) {
		printf("%s\n", file->d_name);
		file = readdir(dir);
	}
	
	(void)closedir(dir);
	
	return 0;
}
