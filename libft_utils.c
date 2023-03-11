/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:35:13 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/03/11 12:03:48 by dabi-rac         ###   ########.fr       */
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

void	assign_sprite(t_game *game, t_game *img, char *str)
{
	int	dimma;

	dimma = 64;
	str = "./sprites/wall.xpm";
	game->reference = mlx_xpm_file_to_image(game->mlx, str, &dimma, &dimma);
}

void 	put_wall(t_game *game)
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
				assign_sprite(game, &game->img, game->reference);
				mlx_put_image_to_window(game->mlx, game->win, game->reference, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}
