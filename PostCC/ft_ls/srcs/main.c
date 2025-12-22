#include "ft_ls.h"

int main(int argc, char **argv) {
    DIR *dir;
    struct dirent *entry;
    char *path;

    if (argc > 1)
        path = argv[1];
    else
        path = ".";

    openDirectory(path, &dir);
    browseFiles(&entry, &dir);
    closedir(dir);
    return 0;
}
