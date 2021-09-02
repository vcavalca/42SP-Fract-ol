/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:30:40 by vcavalca          #+#    #+#             */
/*   Updated: 2021/09/02 20:09:07 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "screen_setup.h"
# include "error_messages.h"
# include "key_linux.h"
# include "calculations.h"

/*Struct Fractol MLX*/
typedef struct s_fractol
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			type;
	double		x_param;
	double		y_param;
	int			x_mouse;
	int			y_mouse;
	int			color;
	double		side;
	double		vert;
	double		mag;
	int			max_i;
}t_fractol;

/*Struct Complex*/
typedef struct s_complex
{
	double	x;
	double	y;
}t_complex;

enum
{
	MANDELBROT = 1,
	JULIA_MOUSE,
	JULIA_PARAM,
	BURNINGSHIP
};

double	ft_atof(char *s);
double	ft_mod_complex(t_complex a);

int		ft_strcmp_f(const char *s1, const char *s2);
int		ft_args_verification(t_fractol *fractol, int argc, char **argv);
int		ft_argv_check(char *s);
int		ft_fractol_init(t_fractol *fractol);
int		ft_make_img(t_fractol *fractol);
int		ft_create_trgb(t_fractol *fractol, int i);
int		ft_mandelbrot(t_fractol *fractol, int ix, int iy);
int		ft_julia(t_fractol *fractol, int ix, int iy);
int		ft_burning_ship(t_fractol *fractol, int ix, int iy);
int		ft_mouse_hook(int x, int y, t_fractol *fractol);
int		ft_key_hook(int keycode, t_fractol *fractol);
int		ft_mouse_click(int button, int x, int y, t_fractol *fractol);
int		ft_cross_button(t_fractol *fractol);

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color);
void	ft_error_print(void);
void	ft_free_mlx(t_fractol *fractol);
void	ft_fractal(t_fractol *fractol);
void	ft_init_complex(t_complex *c, double a, double b);
void	ft_add_complex(t_complex *c, t_complex a, t_complex b);
void	ft_sqr_complex(t_complex *c, t_complex a);
void	ft_map_point(t_fractol *fractol, t_complex *c, int x, int y);

#endif
