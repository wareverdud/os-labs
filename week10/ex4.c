#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main() {
    FILE *f = fopen("ex4.txt", "w");

	DIR *dir = opendir("./tmp");
    if (dir == NULL) return 0;
    struct dirent* file = readdir(dir);
    struct stat statistic;
    fprintf(f, "File - Hard Links\n");
    
    while ( file != NULL ) {
        if (    strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0   ) {
            
        }
        else {
            char file_n[260];
			snprintf(file_n, sizeof(file_n), "%s%s", "tmp/", file->d_name);
			stat(file_n, &statistic);
            if (statistic.st_nlink > 1) {
                fprintf(f, "%s - ", file->d_name);
                DIR *dir1 = opendir("./tmp");
                struct dirent* file1 = readdir(dir1);
                struct stat statistic1;
                while ( file1 != NULL ) {
                    char file_1_n[260];
                    snprintf(file_1_n, sizeof(file_1_n), "%s%s", "tmp/", file1->d_name);
                    stat(file_1_n, &statistic1);
                    if (statistic1.st_ino == statistic.st_ino) {
                        fprintf(f, "%s ", file1->d_name);
                    }
                    file1 = readdir(dir1);
                }
                fprintf(f, "\n");
            }
        }
        file = readdir(dir);
    }


    (void)closedir(dir);
    fclose(f);

    return 0;
}
