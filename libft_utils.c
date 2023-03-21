/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:07:05 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/03/21 19:06:26 by dabi-rac         ###   ########.fr       */
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
	char	*stringa;
	long	number;
	long	len;

	len = lenght_string(n);
	number = n;
	stringa = (char *)malloc(len + 1);
	if (!stringa)
		return (NULL);
	stringa[len--] = '\0';
	if (number < 0)
	{
		number = -number;
		stringa[0] = '-';
	}
	while (number >= 10)
	{
		stringa[len--] = 48 + (number % 10);
		number /= 10;
	}
	if (number >= 0 && number < 10)
		stringa[len] = 48 + (number % 10);
	return (stringa);
}