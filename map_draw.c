/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:44:17 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 16:42:04 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	draw_enemy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N')
			{
				if (game->flag == 0)
					mlx_put_image_to_window(game->mlx, game->win, \
					game->ref_enemy, j * 64, i * 64);
				if (game->flag == 1)
					mlx_put_image_to_window(game->mlx, game->win, \
					game->ref_enemy1, j * 64, i * 64);
				game->flag = 1 - game->flag;
			}
			j++;
		}
		i++;
	}
}

static	void	draw_things(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->ref_escape, \
				j * 64, i * 64);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->ref_coin, \
				j * 64, i * 64);
			else if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->ref_wall, \
				j * 64, i * 64);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->ref_floor, \
				j * 64, i * 64);
			j++;
		}
		i++;
	}
}

static	void	draw_player_and_enemy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N')
				mlx_loop_hook(game->mlx, animation, game);
			else if (game->map[i][j] == 'P')
			{
				game->y = i;
				game->x = j;
				mlx_put_image_to_window(game->mlx, game->win, game->ref_floor, \
				j * 64, i * 64);
				mlx_put_image_to_window(game->mlx, game->win, game->ref_player, \
				j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

int	animation(t_game *game)
{
	if (game->time == 1000)
	{
		game->time = 0;
		draw_enemy(game);
	}
	game->time++;
	return (0);
}

void	draw_map(t_game *game)
{
	draw_things(game);
	draw_player_and_enemy(game);
}
