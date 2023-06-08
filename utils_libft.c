/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:17:55 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/06/09 00:17:58 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	lenght_string(int n)
{
	long int	number;
	int			len;

	number = n;
	len = 1;
	if (number < 0)
	{
		len++;
		number = -number;
	}
	while (number >= 10)
	{
		number = number / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	number;
	long	len;

	len = lenght_string(n);
	number = n;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (number < 0)
	{
		number = -number;
		str[0] = '-';
	}
	while (number >= 10)
	{
		str[len--] = 48 + (number % 10);
		number /= 10;
	}
	if (number >= 0 && number < 10)
		str[len] = 48 + (number % 10);
	return (str);
}
