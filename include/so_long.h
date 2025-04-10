/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:05:59 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/10 23:52:00 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "message_error.h"
# include <fcntl.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/types.h>

# define TYPE_FILE ".ber"
# ifndef DIR_FILE
#  define DIR_FILE "map/"
# endif

# define SIZE_MAP 50
# define NB_ASSET 12

/*asset disagne */
# define WALL 0
# define STAR 1
# define DOOR 2

/*asset player */
# define DOWN1 3
# define DOWM2 4
# define UP1 5
# define UP2 6
# define LEFT1 7
# define LEFT2 8
# define RIGHT1 9
# define RIGHT2 10
# define BG 11

typedef struct s_coord
{
	size_t					x;
	size_t					y;
}							t_coord;

typedef struct s_bag
{
	size_t					nb;
	size_t					nb_collected;
}							t_bag;

typedef struct s_player		*t_player;
typedef struct s_player
{
	t_coord					*coord;
	t_bag					bag;
	bool					move;
}							t_playe;
typedef struct s_map		*t_map;
typedef struct s_map
{
	int						*nb;
	char					*line;
	t_map					next;
}							t_ma;

typedef struct s_size_card
{
	size_t					height;
	size_t					width;
}							t_size_card;

typedef struct s_card		*t_card;
typedef struct s_card
{
	t_size_card				size;
	char					**map;
}							t_car;

typedef struct s_game_room	*t_game_room;
typedef struct s_game_room
{
	t_card					card;
	t_img					**asset;
	t_player				p;
}							t_game_roo;

typedef struct s_pixel
{
	int						x;
	int						y;
}							t_pixel;
typedef struct s_point		*t_point;
typedef struct s_point
{
	t_pixel					pixel;
	int						color;
}							t_poin;
typedef struct s_square		*t_square;
typedef struct s_square
{
	int						border;
	int						size_border;
	int						color_border;
	int						color_in;
	int						height;
	int						width;
	t_pixel					p;
}							t_squar;

typedef struct s_window		*t_window;
typedef struct s_window
{
	int						cpt;
	int						width;
	int						height;
	t_xvar					*mlx;
	t_win_list				*win;
	t_img					*img;
	t_game_room				room;
	char					*title;
}							t_windo;

/* function  close windows */
int							ft_close(t_window vars);

/* function  back tracking */
bool						back_traking(t_card c, t_coord now, bool t);
/* function  copy of card */
t_card						ft_cp_t_card(t_card c);
/* function check */
bool						ft_file_check(char *name_file);
int							ft_goto_end_file(int fd);

/* function file */
void						*ft_recover_card(char *name_file);
t_card						ft_create_card(t_map m);
bool						ft_check_size_t_map(t_map m);

/* function creation player */
t_player					create_t_player(t_card c);

/* function creation windows */
t_window					ft_create_window(int x, int y, char *title);

/* function creation  image */
t_img						*ft_create_new_image(t_window w);
/* function creation pixel */
t_point						ft_point(int x, int y, int color);

/* function free t_map */
void						ft_free_t_map(t_map m);
/* function free t_game_room */
void						ft_free_room(t_game_room room);

/* function free t_card */
void						ft_free_t_card(t_card c, int i);

/* function free windows */
void						ft_free_t_window(t_window win);

/* function free  t_coord */
void						ft_free_coord(t_coord *p);

/* function free t_player */
void						ft_free_player(t_player p);

/* function free all */
void						ft_free_all(t_window p);

/* function event */
int							ft_key_move(int keycode, t_window data);

/* function load asset */
void						ft_load_images(t_window win);

/* function draw */
void						ft_draw_asset(t_window win, int asset,  size_t x, size_t y);
void						ft_draw(t_img *data, t_pixel pix, int color);
void						ft_draw_line(t_point p1, t_point p2, t_img *data);
void						ft_draw_map(t_window win);
void	ft_move_player(t_window win, t_coord *c_player, t_player p, t_card card);
bool						ft_move_up(t_window win);
bool						ft_move_down(t_window win);
bool						ft_move_left(t_window win);
bool						ft_move_right(t_window win);
void						init_move(t_window win, t_coord *c_player,
								t_player p);
#endif
