/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:35:13 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/03/12 14:18:56 by dabi-rac         ###   ########.fr       */
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

void	assign_sprite_wall(t_game *game, t_game *img0, char *str)
{
	int	dimma;

	dimma = 64;
	str = "./sprites/wall.xpm";
	game->refwall = mlx_xpm_file_to_image(game->mlx, str, &dimma, &dimma);
}

void	assign_sprite_termini(t_game *game, t_game *imge, char *str)
{
	int	dimma;

	dimma = 64;
	str = "./sprites/termini.xpm";
	game->reftermini = mlx_xpm_file_to_image(game->mlx, str, &dimma, &dimma);
}

void	assign_sprite_franchino(t_game *game, t_game *imgP, char *str)
{
	int	dimma;

	dimma = 64;
	str = "./sprites/franchino.xpm";
	game->reffranchino = mlx_xpm_file_to_image(game->mlx, str, &dimma, &dimma);
}

void	assign_sprite_floor(t_game *game, t_game *img1, char *str)
{
	int	dimma;

	dimma = 64;
	str = "./sprites/floor.xpm";
	game->reffloor = mlx_xpm_file_to_image(game->mlx, str, &dimma, &dimma);
}

void	assign_sprite_suppli(t_game *game, t_game *imgc, char *str)
{
	int	dimma;

	dimma = 64;
	str = "./sprites/suppli.xpm";
	game->refsuppli = mlx_xpm_file_to_image(game->mlx, str, &dimma, &dimma);
}

void 	put_sprites(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
			{
				assign_sprite_wall(game, &game->img0, game->refwall);
				mlx_put_image_to_window(game->mlx, game->win, game->refwall, j * 64, i * 64);
			}
			else if (game->map[i][j] == '0')
			{
				assign_sprite_floor(game, &game->img1, game->reffloor);
				mlx_put_image_to_window(game->mlx, game->win, game->reffloor, j * 64, i * 64);
			}
			else if (game->map[i][j] == 'P')
			{
				assign_sprite_franchino(game, &game->imgP, game->reffranchino);
				mlx_put_image_to_window(game->mlx, game->win, game->reffranchino, j * 64, i * 64);
			}
			else if (game->map[i][j] == 'C')
			{
				assign_sprite_suppli(game, &game->imgc, game->refsuppli);
				mlx_put_image_to_window(game->mlx, game->win, game->refsuppli, j * 64, i * 64);
			}
			else if (game->map[i][j] == 'E')
			{
				assign_sprite_termini(game, &game->imgc, game->reftermini);
				mlx_put_image_to_window(game->mlx, game->win, game->reftermini, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}
