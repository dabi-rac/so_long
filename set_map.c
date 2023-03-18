/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:06:37 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/03/18 13:06:41 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	upload_image(t_game *game)
{
	int size;
	
	game->ref_wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm", &size, &size);
	game->ref_floor = mlx_xpm_file_to_image(game->mlx, "sprites/floor.xpm", &size, &size);
	game->ref_escape = mlx_xpm_file_to_image(game->mlx, "sprites/escape.xpm", &size, &size);
	game->ref_player = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", &size, &size);
	game->ref_coin = mlx_xpm_file_to_image(game->mlx, "sprites/coin.xpm", &size, &size);
	game->ref_enemy = mlx_xpm_file_to_image(game->mlx, "sprites/enemy.xpm", &size, &size);

}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->ref_coin, j * 64, i * 64);
			else if (game->map[i][j] == 'P')
			{
				game->posy = i;
				game->posx = j;
				mlx_put_image_to_window(game->mlx, game->win, game->ref_floor, j * 64, i * 64);
				mlx_put_image_to_window(game->mlx, game->win, game->ref_player, j * 64, i * 64);
			}
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->ref_escape, j * 64, i * 64);
			else if (game->map[i][j] == 'N')
				mlx_put_image_to_window(game->mlx, game->win, game->ref_enemy, j * 64, i * 64);
			else if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->ref_wall, j * 64, i * 64);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->ref_floor, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

