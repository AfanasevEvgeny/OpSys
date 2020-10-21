#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    struct dirent *dp;
    char *name[255];
    ino_t inode_n[255];
    DIR *dirp = opendir("./tmp");    
    int i = 0;

    while (readdir(dir)!=NULL) {  //does not work -__- idk how to fix it
        dp=readdir(dirp);
        inode_n[i] = dp->d_ino;
        name[i] = dp->d_name;
        i++;
    }
                
    for (int j = 0; j < i; j++) {
        for (int k = j + 1; k < i; k++) {
            if ((inode_n[k] == inode_n[j]) {
                printf(name[j], name[k]); //linked files
                inode_n[k] = 0;
            }
        }
    }
    return 0;
}