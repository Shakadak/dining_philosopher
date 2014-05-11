/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 17:16:47 by npineau           #+#    #+#             */
/*   Updated: 2014/05/11 17:09:22 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
#include "libft.h"

static void	*stop(t_philo *list, int id, t_env *env)
{
	int		i;

	draw(env);
	if (id >= 0)
	{
		ft_putstr("Philosopher #");
		ft_putnbr(id);
		ft_putendl(" just died.");
	}
	i = 0;
	while (i < 7)
		list[i++].sat = 0;
	return (NULL);
}

void		*master(void *arg)
{
	t_philo	*list;
	long	id;
	int		time;

	list = philosopher((void *)-1);
	time = TIMEOUT * 4;
	while (time-- >= 0)
	{
		usleep(SECOND / 4);
		id = 0;
		while (id < MAX_PHILO)
		{
			list[id].health -= (time % 4 ? 0 : 1);
			if (list[id].health <= 0)
				return (stop(list, id, (t_env *)arg));
			id++;
			draw((t_env *)arg);
		}
	}
	stop(list, -1, (t_env *)arg);
	ft_putendl("Now, it is time... To DAAAAAAAANCE !!!");
	return ((void *)-1);
}
