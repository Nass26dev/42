#include "ft_ls.h"

void openDirectory(char *path, DIR **dir) {
    *dir = opendir(path);
    if (!*dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }
}

void browseFiles(struct dirent **entry, DIR **dir) {
    while ((*entry = readdir(*dir)) != NULL) {
        ft_putstr((*entry)->d_name);
        ft_putchar('\n');
    }
}