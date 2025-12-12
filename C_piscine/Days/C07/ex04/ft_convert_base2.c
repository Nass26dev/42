/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:20:32 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/27 11:20:37 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_error_detector(char *base)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if (((9 <= base[i]) && (base[i] <= 13)) || base[i] == 32)
			return (1);
		j = 0;
		count = 0;
		while (base[j])
		{
			if (base[i] == base[j])
				count++;
			if (count > 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
