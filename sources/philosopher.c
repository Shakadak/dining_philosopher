/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 15:01:23 by npineau           #+#    #+#             */
/*   Updated: 2014/05/09 18:31:22 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "philo.h"

static void	loop(t_philo *philo, int id)
{
	while (philo[id].health > 0)
	{
		eat(id, philo, 0);
		rest(id, philo);
		if (pthread_mutex_trylock(&philo[id].chopstick))
		{
			if (pthread_mutex_trylock(&philo[id + 1].chopstick))
				rest(id, philo);
			else
				think(id, philo, id + 1);
		}
		else
		{
			if (pthread_mutex_trylock(&philo[id + 1].chopstick))
				eat(id, philo, 1);
			else
				think(id, philo, id);
		}
	}
}

void		*philosopher(void *arg)
{
	int				id;
	static t_philo	*philo;

	id = (int)arg;
	if (id == -1)
	{
		if (philo == NULL)
			philo = init_table();
		return ((void *)philo);
	}
	loop(philo, id);
	return (NULL);
}
