#ifndef MESSAGE_ERROR_H
#define MESSAGE_ERROR_H


# include "../libft/include/libft.h"

/* function error windows */
void    ft_err_win(size_t err);

/* function error file */
void    ft_err_file(size_t err);

/* function error t_map */
void    ft_err_t_map(size_t err);

/* function error t_card */
void	ft_err_t_card(size_t err);

/* function error allowance */
void	ft_err_allowance(size_t err);

/* function error coord */
void    ft_err_coord(size_t err);

/* function error player */
void    ft_err_player(size_t err);

/* function error image */
void    ft_err_image(size_t err);

/* function error leading asset xpm*/
void	ft_err_load_file_xpm(size_t err);
#endif
