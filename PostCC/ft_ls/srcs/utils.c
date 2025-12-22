#include <stdio.h>
#include <unistd.h>

size_t ft_strlen(char *str) {
    int i = 0;

    while (str[i]) {
        i++;
    }
    return i;
}

void ft_putstr(char *str) {
    write(1, str, ft_strlen(str));
}

void ft_putchar(char c) {
    write(1, &c, 1);
}