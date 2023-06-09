/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:19:04 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/06/09 00:19:06 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_error(int ac, char *av)
{
	int	len;

	len = 0;
	if (ac != 2)
		return (0);
	while (av[len])
		len++;
	if (av[len] == 'r' && av[len - 1] == 'e' && av[len - 2] == 'b' \
	&& av[len - 3] == '.')
		return (1);
	return (0);
}

static	int	check_form(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = game->cols;
	while (i < game->rows)
	{
		if (len != ft_strlen(game->map[i]))
			return (0);
		i++;
	}
	return (1);
}

static	int	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = game->rows;
	while (++i < game->cols)
	{
		if (game->map[0][i] != '1')
			return (0);
	}
	while (--i > 0)
	{
		if (game->map[j - 1][i] != '1')
			return (0);
	}
	while (game->map[--j] > game->map[-1])
	{
		if (game->map[j][0] != '1' && game->map[j][game->cols] != '1')
			return (0);
	}
	return (1);
}

static	int	check_char(t_game *game)
{
	int	i;
	int	j;

	j = -1;
	while (game->map[++j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'P')
				game->obj.player++;
			else if (game->map[j][i] == 'C')
				game->obj.coin++;
			else if (game->map[j][i] == 'E')
				game->obj.escape++;
			else if (game->map[j][i] == 'N')
				game->obj.enemy++;
			else if (game->map[j][i] != '0' && game->map[j][i] != '1')
				return (0);
			i++;
		}
	}
	if (game->obj.coin < 1 || game->obj.player != 1 || game->obj.escape != 1)
		return (0);
	return (1);
}

int	map_ok(t_game *game)
{
	if (check_form(game) == 1)
	{
		if (check_walls(game) == 1)
		{
			if (check_char(game) == 1)
				return (1);
		}
	}
	return (0);
}
