/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:34:54 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/03/11 10:34:57 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

static size_t	ft_counter(const char *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			++count;
			while (s[i] && s[i] != c)
				++i;
		}
		else
			i++;
	}
	return (count + 1);
}

static char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	i = 0;
	matrix = malloc(sizeof(char *) * (ft_counter(s, c)));
	if (!matrix)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			while (*s && *s != c && ++j)
				++s;
			matrix[i++] = ft_substr(s - j, 0, j);
		}
		else
			++s;
	}
	matrix[i] = 0;
	return (matrix);
}

int	read_map(char *av, t_game *game)
{
    char    *str;
    int     fd;
    
    fd = open(av, O_RDONLY);
	if (fd == -1)
       return (0);
	str = malloc(sizeof(char) * 100);
    read(fd, str, 100);
	game->map = ft_split(str, '\n');
	free(str);
	if (!game->map)
		exit(0);
	while(game->map[game->rows])
	{
	printf("%s\n", game->map[game->rows]);
		game->cols = 0;
		while(game->map[game->rows][game->cols])
			game->cols++;
		game->rows++;
	}
	printf("%dp\n%dp\n",game->cols,game->rows);
	close(fd);
	return (1);
}
