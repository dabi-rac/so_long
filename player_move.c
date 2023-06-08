/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:18:18 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/06/09 00:18:20 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move_up(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 126)
	{
		if (game->map[game->y - 1][game->x] == 'N')
			exit(0);
		if (game->map[game->y - 1][game->x] == 'E' && game->obj.coin == 0)
			exit(0);
		if (game->map[game->y - 1][game->x] != '1' &&
			game->map[game->y - 1][game->x] != 'E')
		{
			game->map[game->y][game->x] = '0';
			game->y--;
			if (game->map[game->y][game->x] == 'C')
				game->obj.coin--;
			game->map[game->y][game->x] = 'P';
		}
		game->mvs++;
	}
}

static void	ft_move_down(int keycode, t_game *game)
{
	if (keycode == 1 || keycode == 125)
	{
		if (game->map[game->y + 1][game->x] == 'N')
			exit(0);
		if (game->map[game->y + 1][game->x] == 'E' && game->obj.coin == 0)
			exit(0);
		if (game->map[game->y + 1][game->x] != '1'
			&& game->map[game->y + 1][game->x] != 'E')
		{
			game->map[game->y][game->x] = '0';
			game->y++;
			if (game->map[game->y][game->x] == 'C')
				game->obj.coin--;
			game->map[game->y][game->x] = 'P';
		}
		game->mvs++;
	}
}

static void	ft_move_right(int keycode, t_game *game)
{	
	if (keycode == 2 || keycode == 124)
	{
		if (game->map[game->y][game->x + 1] == 'N')
			exit(0);
		if (game->map[game->y][game->x + 1] == 'E' && game->obj.coin == 0)
			exit(0);
		if (game->map[game->y][game->x + 1] != '1'
			&& game->map[game->y][game->x + 1] != 'E')
		{
			game->map[game->y][game->x] = '0';
			game->x++;
			if (game->map[game->y][game->x] == 'C')
				game->obj.coin--;
			game->map[game->y][game->x] = 'P';
		}
		game->mvs++;
	}
}

static void	ft_move_left(int keycode, t_game *game)
{
	if (keycode == 0 || keycode == 123)
	{
		if (game->map[game->y][game->x - 1] == 'N')
			exit(0);
		if (game->map[game->y][game->x - 1] == 'E' && game->obj.coin == 0)
			exit(0);
		if (game->map[game->y][game->x - 1] != '1'
			&& game->map[game->y][game->x - 1] != 'E')
		{
			game->map[game->y][game->x] = '0';
			game->x--;
			if (game->map[game->y][game->x] == 'C')
				game->obj.coin--;
			game->map[game->y][game->x] = 'P';
		}
		game->mvs++;
	}
}

int	ft_move(int keycode, t_game *game)
{
	char	*moves;

	if (keycode == 53)
		exit(0);
	ft_move_up(keycode, game);
	ft_move_down(keycode, game);
	ft_move_right(keycode, game);
	ft_move_left(keycode, game);
	draw_map(game);
	moves = ft_itoa(game->mvs);
	mlx_string_put(game->mlx, game->win, 10, 10, 0x000000, "numero mosse :");
	mlx_string_put(game->mlx, game->win, 155, 10, 0x000000, moves);
	free(moves);
	return (1);
}
