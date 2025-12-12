# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/23 14:21:24 by nyousfi           #+#    #+#              #
#    Updated: 2024/08/29 18:29:57 by nyousfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -c -o ft_putchar.o ft_putchar.c
gcc -c -o ft_swap.o ft_swap.c
gcc -c -o ft_putstr.o ft_putstr.c
gcc -c -o ft_strlen.o ft_strlen.c
gcc -c -o ft_strcmp.o ft_strcmp.c
ar rcs libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
