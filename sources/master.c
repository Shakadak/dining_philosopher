/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 17:16:47 by npineau           #+#    #+#             */
/*   Updated: 2014/05/08 18:00:24 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

void	*master(void *arg)
{
	t_philo	*list;
	long	id;
	int		time;

	list = (t_philo *)arg;
	time = TIMEOUT;
	while (time--)
	{
		usleep(1000000);
		id = 0;
		while (id < MAX_PHILO)
		{
			if (--list[id].health <= 0)
				return ((void *)id);
		}
	}
	return (NULL);
}
