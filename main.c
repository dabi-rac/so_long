/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:19:17 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/06/09 00:19:18 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
}

int	ft_close(t_game *game)
{
	free_map(game);
	exit(0);
}

void	ft_init(t_game *game)
{
	game->obj.escape = 0;
	game->obj.enemy = 0;
	game->obj.coin = 0;
	game->obj.player = 0;
	game->flag = 0;
	game->time = 0;
	game->mvs = 0;
}

void	upload_image(t_game *game)
{
	int	size;

	game->ref_wall = \
	mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm", &size, &size);
	game->ref_floor = \
	mlx_xpm_file_to_image(game->mlx, "sprites/floor.xpm", &size, &size);
	game->ref_escape = \
	mlx_xpm_file_to_image(game->mlx, "sprites/escape.xpm", &size, &size);
	game->ref_player = \
	mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", &size, &size);
	game->ref_coin = \
	mlx_xpm_file_to_image(game->mlx, "sprites/coin.xpm", &size, &size);
	game->ref_enemy = \
	mlx_xpm_file_to_image(game->mlx, "sprites/enemy.xpm", &size, &size);
	game->ref_enemy1 = \
	mlx_xpm_file_to_image(game->mlx, "sprites/enemy1.xpm", &size, &size);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (0);
	ft_init(&game);
	read_map(av[1], &game);
	map_error(2, av[1]);
	if (map_ok(&game) == 0)
	{
		write(1, "mappa non valida\n", 17);
		exit (1);
	}
	game.mlx = mlx_init();
	upload_image(&game);
	game.win = mlx_new_window(game.mlx, game.cols * 64, game.rows * 64, \
			"So_long dabi-rac");
	draw_map(&game);
	mlx_hook(game.win, 2, 1L << 0, ft_move, &game);
	mlx_hook(game.win, 17, 1L << 2, ft_close, &game);
	mlx_loop(game.mlx);
}
