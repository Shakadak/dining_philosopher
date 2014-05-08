/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 13:38:18 by npineau           #+#    #+#             */
/*   Updated: 2014/05/08 17:21:56 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "philo.h"

void	eat(int	id, t_philo *list, int reserved)
{
	if (!reserved)
	{
		pthread_mutex_lock(&list[(id + id % 2) % MAX_PHILO].chopstick);
		pthread_mutex_lock(&list[(id + (id + 1) % 2) % MAX_PHILO].chopstick);
	}
	list[id].eating = 1;
	usleep(EAT_T * 1000000);
	list[id].health = MAX_LIFE;
	pthread_mutex_unlock(&list[(id + id % 2) % MAX_PHILO].chopstick);
	pthread_mutex_unlock(&list[(id + (id + 1) % 2) % MAX_PHILO].chopstick);
}
