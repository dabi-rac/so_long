/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:06:45 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/03/21 18:58:08 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void		ft_move_up(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 126)
	{
		if (game->map[game->posy - 1][game->posx] == 'N')
			exit(2);
		if (game->map[game->posy - 1][game->posx] == 'E' && game->obj.coin == 0)
			exit(2);
		if (game->map[game->posy - 1][game->posx] != '1' && game->map[game->posy - 1][game->posx] != 'E')
		{
			game->map[game->posy][game->posx] = '0';
			game->posy--;
			if (game->map[game->posy][game->posx] == 'C')
				game->obj.coin--;
			game->map[game->posy][game->posx] = 'P';
		}
		game->moves++;
	}
}

static void		ft_move_down(int keycode, t_game *game)
{
	if (keycode == 1 || keycode == 125)
	{
		if (game->map[game->posy + 1][game->posx] == 'N')
			exit(2);
		if (game->map[game->posy + 1][game->posx] == 'E' && game->obj.coin == 0)
			exit(2);
		if (game->map[game->posy + 1][game->posx] != '1' && game->map[game->posy + 1][game->posx] != 'E')
		{
			game->map[game->posy][game->posx] = '0';
			game->posy++;
			if (game->map[game->posy][game->posx] == 'C')
				game->obj.coin--;
			game->map[game->posy][game->posx] = 'P';
		}
		game->moves++;
	}
}

static void		ft_move_right(int keycode, t_game *game)
{	
	if (keycode == 2|| keycode == 124)
	{
		if (game->map[game->posy][game->posx + 1] == 'N')
			exit(2);
		if (game->map[game->posy][game->posx + 1] == 'E' && game->obj.coin == 0)
				exit(2);
		if (game->map[game->posy][game->posx + 1] != '1' && game->map[game->posy][game->posx + 1] != 'E')
		{
			game->map[game->posy][game->posx] = '0';
			game->posx++;
			if (game->map[game->posy][game->posx] == 'C')
				game->obj.coin--;
			game->map[game->posy][game->posx] = 'P';
		}
		game->moves++;
	}
}

static void		ft_move_left(int keycode, t_game *game)
{
	if (keycode == 0 || keycode == 123)
	{
		if (game->map[game->posy][game->posx - 1] == 'N')
			exit(2);
		if (game->map[game->posy][game->posx - 1] == 'E' && game->obj.coin == 0)
			exit(2);
		if (game->map[game->posy][game->posx - 1] != '1' && game->map[game->posy][game->posx - 1] != 'E')
		{
			game->map[game->posy][game->posx] = '0';
			game->posx--;
			if (game->map[game->posy][game->posx] == 'C')
				game->obj.coin--;
			game->map[game->posy][game->posx] = 'P';
		}
		game->moves++;
	}
}
int		ft_move(int keycode, t_game *game)
{
	printf("numero mosse:%d\n", game->moves);
	if (keycode == 53)
		exit(2);
	// mlx_string_put(game->mlx, game->win,100, 100, 0xFFFFFF, "numero mosse");
	ft_move_up(keycode, game);
	ft_move_down(keycode, game);
	ft_move_right(keycode, game);
	ft_move_left(keycode, game);
	draw_map(game);
	return (1);
}