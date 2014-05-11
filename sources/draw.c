/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 16:26:02 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/11 16:13:45 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "philo.h"

static int	get_color(t_philo philo)
{
	if (philo.health <= 0)
		return (REST_IN_PEACE);
	else if (philo.eating == 1)
		return (EAT);
	else if (philo.eating == -1)
		return (THINK);
	else if (philo.eating == 0)
		return (REST);
	else
		return (0xFF0000);
}

static void	draw_philo(t_env *env, int color, int x, int y)
{
	int		i;
	int		j;

	j = -1;
	while (++j < 80)
	{
		i = 0;
		while (i < 80)
			mlx_pixel_put(env->mlx, env->win, x + i++, j + y, color);
	}
}

static void	draw_table(t_env *env)
{
	int		i;
	int		j;

	j = -1;
	while (++j < 420)
	{
		i = 0;
		while (i < 800)
			mlx_pixel_put(env->mlx, env->win, i++, j + 280, WOOD);
	}
}

void		draw(t_env *env)
{
	t_philo	*list;

	list = philosopher((void *)-1);
	draw_table(env);
	draw_philo(env, get_color(list[0]), 0, 180);
	draw_philo(env, get_color(list[1]), 300, 180);
	draw_philo(env, get_color(list[2]), 600, 180);
	draw_philo(env, get_color(list[3]), 820, 460);
	draw_philo(env, get_color(list[4]), 600, 720);
	draw_philo(env, get_color(list[5]), 300, 720);
	draw_philo(env, get_color(list[6]), 0, 720);
}
