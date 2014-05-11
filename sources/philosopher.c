/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 15:01:23 by npineau           #+#    #+#             */
/*   Updated: 2014/05/11 19:34:57 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	loop(t_philo *philo, int id)
{
	while (philo[id].health > 0 && philo[id].sat > 0)
	{
		if (philo[id].health <= MAX_LIFE * 0.3)
			eat(id, philo, 0);
		if (pthread_mutex_trylock(&philo[id].chopstick))
		{
			if (pthread_mutex_trylock(&philo[(id + 1) % 7].chopstick))
				rest(id, philo);
			else
				think(id, philo, (id + 1) % 7);
		}
		else
		{
			if (pthread_mutex_trylock(&philo[(id + 1) % 7].chopstick))
				think(id, philo, id);
			else
				eat(id, philo, 1);
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
	eat(id, philo, 0);
	rest(id, philo);
	loop(philo, id);
	return (NULL);
}
