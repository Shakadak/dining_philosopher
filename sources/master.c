/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 17:16:47 by npineau           #+#    #+#             */
/*   Updated: 2014/05/09 18:33:51 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "philo.h"

void	*master(void *arg)
{
	t_philo	*list;
	long	id;
	int		time;

	list = philosopher((void *)-1);
	time = TIMEOUT;
	while (time--)
	{
		usleep(1000000);
		id = 0;
		while (id < MAX_PHILO)
		{
			if (--(list[id].health) <= 0)
			{
				draw((t_env *)arg);
				return ((void *)id);
			}
			id++;
			draw((t_env *)arg);
		}
	}
	return (NULL);
}
