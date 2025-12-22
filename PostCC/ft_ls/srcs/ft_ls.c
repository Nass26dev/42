#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdbool.h>

bool ft_ls(char *path) {
    DIR *dir;
    struct dirent *entry;
    char **files;

    dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return true;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.')
            continue;
        files = saveName(entry->d_name);
    }
    sortFiles();
    printFiles();

    closedir(dir);

    return false;
}