/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:35:13 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/03/15 15:55:05 by dabi-rac         ###   ########.fr       */
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
				game->posx = j;
				game->posy = i;
				printf("%d", j);
				printf("%d", i);
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

int		ft_move(int keycode, t_game *game)
{
	int j = game->posx;
	int i = game->posy;
	printf("key pressed -> %d\n", keycode);
	


if (keycode == 13 || keycode == 126) {
    if (i > 0 && game->map[i-1][j] != '1') {
        game->map[i][j] = '0'; // Change current tile to '0'
		printf("P tile before -> %c\n", game->map[i][j]);
        i--; // Move up one row
        game->map[i][j] = 'P'; // Change the tile above to 'P'
		printf("P tile before -> %c\n", game->map[i][j]);
    }
}
	// if (keycode == 13 || keycode == 126)
	// {
	// 	if(game->map[--i][j] !=1 )
	// 	{
	// 		printf("P tile before -> %c\n", game->map[i][j]);
	// 		game->map[i++][j] = 'P';
	// 		printf("P tile after -> %c\n", game->map[--i][j]);
	// 	}
	// }
	return (0);
}