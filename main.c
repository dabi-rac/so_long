/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:07:11 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/03/21 18:59:34 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    ft_close(void)
{
    exit(2);
}

t_game  *ft_init(void)
{
	t_game	*game;
    
	game = malloc(sizeof(t_game));
	game->obj.escape = 0;
    game->obj.enemy = 0;
    game->obj.coin = 0;
    game->obj.player = 0;
    game->moves = 0;
	return (game);
}

int main(int ac, char **av)
{   
    t_game *game;
    
     if (ac != 2)
        return (0);
    game = ft_init();
    read_map(av[1], game);
    map_error(2, av[1]);
    if (map_ok(game) == 0)
    {
        perror("mappa non valida");
        exit (0);
    }
    game->mlx = mlx_init();
    upload_image(game);
    printf("init ok\n");
    game->win = mlx_new_window(game->mlx, game->cols * 64, game->rows * 64, "So_long");
    printf("new window ok\n");
    draw_map(game);
    mlx_hook(game->win, 2, 1L << 0, ft_move, game);
    mlx_hook(game->win, 17, 1L << 2, ft_close, game);
    mlx_loop(game->mlx);
    printf("loop ok\n"); 
}