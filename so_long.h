/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:06:31 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/03/18 13:06:33 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <mlx.h>

typedef struct s_obj 
{
    int     coin;
    int     player;
    int     escape;
	int		enemy;
}			t_obj;

typedef struct s_game
{
	t_obj	obj;
    char    **map;
    char    *img;
    void    *mlx;
    void    *win;
    void    *ref_floor;
    void    *ref_wall;
    void    *ref_escape;
    void    *ref_player;
    void    *ref_coin;
    void    *ref_enemy;
    int     posx;
    int     posy;
    int     rows;
    int     cols;
    int     moves;
}       t_game;

//libft_utils
int	    ft_strlen(const char *s);
//maps
int     map_error(int ac, char *av);
int     map_ok(t_game *game);
//map_read
int     read_map(char *av, t_game *game);
//map_popolation
void	draw_map(t_game *game);
void	upload_image(t_game *game);
int	    ft_move(int keycode, t_game *game);
//main
t_game  *ft_init(void);
#endif