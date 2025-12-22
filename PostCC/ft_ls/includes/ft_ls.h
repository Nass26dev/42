#ifndef FT_LS_H
#define FT_LS_H

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/* ft_ls.c */
void openDirectory(char *path, DIR **dir);
void browseFiles(struct dirent **entry, DIR **dir);
/* utils.c */
void ft_putstr(char *str);
void ft_putchar(char c);
#endif