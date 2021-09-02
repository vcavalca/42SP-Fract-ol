/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:30:40 by vcavalca          #+#    #+#             */
/*   Updated: 2021/09/02 06:25:27 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdint.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "colors.h"
# include "error_messages.h"
# include "key_linux.h"

/*Screen resolution*/
# define SCREEN_X 1024
# define SCREEN_Y 768

/*Struct Image MLX*/
typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_length;
	int		endian;
}t_img_data;

/*Struct Fractol MLX*/
typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_img_data	*img;
}t_mlx;

void		my_mlx_pixel_put(t_img_data	*img, int x, int y, int color);
void		*ft_memmalloc(size_t size);
void		ft_exit(char *s);

t_img_data	*ft_init_img(void *mlx);

#endif
