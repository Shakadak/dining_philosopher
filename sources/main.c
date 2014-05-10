/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 14:44:21 by npineau           #+#    #+#             */
/*   Updated: 2014/05/10 13:21:16 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "libft.h"
#include "philo.h"

int		expose_hook(t_env *env)
{
	draw(env);
	return (0);
}

int		key_hook(int keycode)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

/*
**		mlx_pixel_put(env->mlx, env->win, x, y, 0xFFFFFF);
*/

int	main(void)
{
	long		i;
	pthread_t	philos[MAX_PHILO + 1];
	t_env		env;

	i = 0;
	philosopher((void *)-1);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, X_WIN, Y_WIN, "philo");
	while (i < MAX_PHILO)
	{
		pthread_create(&philos[i], NULL, philosopher, (void *)i);
		i++;
	}
	pthread_create(&philos[i], NULL, master, (void *)&env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_expose_hook(env.win, expose_hook, &env);
	mlx_loop(env.mlx);
	pthread_join(philos[i], (void *)&i);
	return (0);
}
