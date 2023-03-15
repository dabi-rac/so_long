/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:35:06 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/03/15 14:35:59 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game  *ft_init(void)
{
	t_game	*game;
	game = malloc(sizeof(t_game));
	game->obj.escape = 0;
    game->obj.enemy = 0;
    game->obj.coin = 0;
    game->obj.player = 0;
	return (game);
}

int main(int ac, char **av)
{   
    t_game  *game;
    
     if (ac != 2)
        return (0);
    game = ft_init();
	printf("gameinit entrato\n");
    read_map(av[1], game);
	printf("readmap entrato\n");
    map_error(2, av[1]);
	printf("maperror entrato\n");
    if (map_ok(game) == 0)
    {
        perror("mappa non valida");
        exit (0);
    }
    game->mlx = mlx_init();
    printf("init ok\n");
    game->win = mlx_new_window(game->mlx, game->cols * 64, game->rows * 64, "So_long");
    
    mlx_key_hook(game->win, ft_move, &game);
    printf("new window ok\n");
    put_sprites(game);
    mlx_loop(game->mlx);
    printf("loop ok\n"); 
}