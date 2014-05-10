/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 17:16:47 by npineau           #+#    #+#             */
/*   Updated: 2014/05/10 16:14:57 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
#include "libft.h"

static void	stop(t_philo *list, int id)
{
	int		i;

	if (id >= 0)
	{
		ft_putstr("Philosopher #");
		ft_putnbr(id);
		ft_putendl(" just died.");
	}
	i = 0;
	while (i < 7)
		list[i++].sat = 0;
}

void		*master(void *arg)
{
	t_philo	*list;
	long	id;
	int		time;

	list = philosopher((void *)-1);
	time = TIMEOUT;
	while (time-- >= 0)
	{
		usleep(SECOND);
		id = 0;
		while (id < MAX_PHILO)
		{
			if (--(list[id].health) <= 0)
			{
				draw((t_env *)arg);
				stop(list, id);
				return ((void *)id);
			}
			id++;
			draw((t_env *)arg);
		}
	}
	stop(list, -1);
	ft_putendl("Now, it is time... To DAAAAAAAANCE !!!");
	return ((void *)-1);
}
