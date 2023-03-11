/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:34:36 by dabi-rac          #+#    #+#             */
/*   Updated: 2023/03/11 10:34:41 by dabi-rac         ###   ########.fr       */
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
    void	*wall;
	void	*escape;
	void	*player;
	void	*coin;
    int     rows;
    int     cols;
}       t_game;

// typedef struct s_img 
// {
// 	void	*wall;
// 	void	*escape;
// 	void	*player;
// 	void	*coin;
// }       t_img;

//libft_utils
int	    ft_strlen(const char *s);
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