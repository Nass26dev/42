#include <stdio.h>
#include <stdbool.h>

bool ft_ls(char *path);

int main(int argc, char **argv) {
    if (argc == 1)
        ft_ls(".");
    (void)argv;
}