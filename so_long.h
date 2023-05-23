/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:38:29 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 16:29:08 by fcarlucc         ###   ########.fr       */
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
	int		coin;
	int		player;
	int		escape;
	int		enemy;
}			t_obj;

typedef struct s_game
{
	t_obj	obj;
	char	**map;
	char	*img;
	void	*mlx;
	void	*win;
	void	*ref_floor;
	void	*ref_wall;
	void	*ref_escape;
	void	*ref_player;
	void	*ref_coin;
	void	*ref_enemy;
	void	*ref_enemy1;
	int		rows;
	int		cols;
	int		mvs;
	int		x;
	int		y;
	int		flag;
	int		time;
}		t_game;

int		ft_strlen(const char *s);
char	*ft_itoa(int n);
int		map_error(int ac, char *av);
int		map_ok(t_game *game);
int		read_map(char *av, t_game *game);
void	draw_map(t_game *game);
int		animation(t_game *game);
int		ft_move(int keycode, t_game *game);
void	upload_image(t_game *game);
int		ft_close(t_game *game);
void	ft_init(t_game *game);
void	free_map(t_game *game);

#endif
