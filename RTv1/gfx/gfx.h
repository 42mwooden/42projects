/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:33:05 by mwooden           #+#    #+#             */
/*   Updated: 2017/04/27 07:38:59 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H

# define W_WIDTH 640
# define W_HEIGHT 480

# define NUM_THREADS 4

# define FLOOR_C 0x696969
# define CIELING_C 0x454545

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 124
# define KEY_RIGHT 123
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_LESS 43
# define KEY_GREATER 47
# define KEY_ESCAPE 53
# define KEY_SPACE 49

# define FALSE 0
# define TRUE !FALSE

# include <stdlib.h>
# include <math.h>
# include <pthread.h>

typedef struct		s_bham
{
	int				da;
	int				pa;
	int				da_sign;
	int				pa_sign;
	float			m;
	float			err;
}					t_bham;

typedef struct		s_view
{
	float			ar;
	float			focal_d;
}					t_view;

typedef struct		s_wolf
{
	int				hit;
	int				side;
	int				mapx;
	int				mapy;
	double			ray_posx;
	double			ray_posy;
	double			ray_dirx;
	double			ray_diry;
	double			side_distx;
	double			side_disty;
	double			delta_distx;
	double			delta_disty;
	double			floor_x;
	double			floor_y;
	double			floor_cx;
	double			floor_cy;
	double			weight;
	double			dist_w;
	double			dist_p;
	double			dist_c;
	int				floor_tx;
	int				floor_ty;
	int				floor_done;
	double			perp_dist;
	int				line_height;
	int				stepx;
	int				stepy;
	int				line_start;
	int				line_end;
	double			frame_time;
	double			camerax;
	double			wallx;
	unsigned int	color;
	int				texx;
	int				texy;
	int				tex_i;
}					t_wolf;

typedef struct		s_env
{
	int				**map;
	unsigned int	**tex;
	double			t_speed;
	double			r_speed;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	void			*mlx;
	void			*win;
	void			*img_id;
	unsigned int	*img;
	int				bpp;
	int				size_line;
	int				endian;
	int				status;
	int				command;
	int				running_threads;
	pthread_mutex_t	mutex;
	pthread_cond_t	start_cond;
	pthread_cond_t	done_cond;
	unsigned int	w_press:1;
	unsigned int	s_press:1;
	unsigned int	a_press:1;
	unsigned int	d_press:1;
	unsigned int	q_press:1;
	unsigned int	e_press:1;
}					t_env;

typedef struct		s_thread
{
	int				x_start;
	int				x_end;
	pthread_t		thread;
	t_wolf			*wolf;
	t_env			*env;
}					t_thread;

/*
** ~~~~~~~~~~~~~~~~~~ FRACT'OL ~~~~~~~~~~~~~~~~~~
*/

/*
**typedef struct		s_env
**{
**	void			*mlx;
**	void			*win;
**	void			*img_id;
**	unsigned int	*img;
**	int				bpp;
**	int				size_line;
**	int				endian;
**	int				status;
**	int				option;
**	int				max;
**	double			mxoff;
**	double			xoff;
**	double			yoff;
**	double			z;
**	int				lock;
**	int				c;
**	unsigned int	*colors;
**	t_fract			*fract;
**}					t_env;
*/
typedef struct		s_fract
{
	int				x;
	int				y;
	double			pi;
	double			pr;
	double			newre;
	double			oldre;
	double			newim;
	double			oldim;
	double			sre;
	double			sim;
	int				i;
}					t_fract;

/*
** ~~~~~~~~~~~~~~~~ END FRACT'OL ~~~~~~~~~~~~~~~~
** ~~~~~~~~~~~~~~~~~~~~ FDF ~~~~~~~~~~~~~~~~~~~~~
*/

typedef struct		s_3dp
{
	float			x;
	float			y;
	float			z;
}					t_3dp;

typedef struct		s_vert
{
	t_3dp			*initial;
	t_3dp			*centered;
	t_3dp			*pixl;
}					t_vert;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	void			*img_id;
	char			*img;
	int				bpp;
	int				size_line;
	int				endian;
	float			**map;
	int				lines;
	int				words;
	int				cur;
	float			xshift;
	float			yshift;
	float			xrot;
	float			yrot;
	float			zrot;
	float			scale;
	float			zscale;
	int				line_len;
	t_vert			***vert;
	int				edge;
	t_view			*view;
}					t_fdf;

/*
** ~~~~~~~~~~~~~~~~~~ END FDF ~~~~~~~~~~~~~~~~~~~
*/

t_3dp				*create_3dp(double x, double y, double z);

void				draw_line_3d(t_env *env, t_3dp *p1, t_3dp *p2);
void				put_img_pixel(t_env *env, float y, float x,
					unsigned int color);

void				mat_bzero(float mat[4][4]);
void				mat_identity(float mat[4][4]);
void				mat_copy(float src[4][4], float dst[4][4]);
void				mat_rotate(float mat[4][4], float psi, float phi,
					float theta);
void				mat_translate(float mat[4][4], float x, float y, float z);
void				mat_scale(float mat[4][4], float x, float y, float z);
void				mat_mult(float mat1[4][4], float mat2[4][4],
					float res[4][4]);
void				mat_vector_mult(t_3dp *src, float mat[4][4], t_3dp *dst);
void				mat_world(float mat[4][4], t_fdf *env);
void				mat_print(float mat[4][4]);

#endif
