/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:34:36 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/03/12 14:19:37 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "./minilibx/mlx.h"

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
    void    *mlx;
    void    *win;
    // void	*wall;
	// void	*escape;
	// void	*player;
	// void	*coin;
    void    *refwall;
    void    *reffloor;
    void    *reffranchino;
    void    *refsuppli;
    void    *reftermini;
    int     rows;
    int     cols;
    void    *img1;
    void    *img0;
    void    *imgP;
    void    *imgc;
    void    *imge;
}       t_game;


// typedef struct s_img 
// {
//     t_game  *img;
// 	void	*img_wall;
// 	void	*img_escape;
// 	void	*img_player;
// 	void	*img_coin;
//     void    *reference;
// }       t_img;

//libft_utils
int	    ft_strlen(const char *s);
void    assign_sprite_wall(t_game *game, t_game *img0, char *str);
void	assign_sprite_floor(t_game *game, t_game *img1, char *str);
void	assign_sprite_franchino(t_game *game, t_game *img1, char *str);
void	assign_sprite_suppli(t_game *game, t_game *imgc, char *str);
void	assign_sprite_termini(t_game *game, t_game *imge, char *str);
void    put_sprites(t_game *game);
//maps
// int     check_form(t_game *game);
// int     check_walls(t_game *game);
// int     check_char(t_game *game);
int     map_error(int ac, char *av);
int     map_ok(t_game *game);
//map_read
// char	**ft_split(char const *s, char c);
int     read_map(char *av, t_game *game);
//main
t_game  *ft_init(void);
#endif