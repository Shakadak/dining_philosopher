/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 18:20:29 by npineau           #+#    #+#             */
/*   Updated: 2014/05/08 15:50:53 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include "libft.h"
#include "philo.h"

t_philo	*init_table(void)
{
	t_philo	*new;
	int		i;

	new = (t_philo *)malloc(sizeof(t_philo) * MAX_PHILO);
	if (new == NULL)
		ft_putendl("fail malloc");
	i = 0;
	while (i < MAX_PHILO)
	{
		new[i].id = i;
		new[i].health = MAX_LIFE;
		new[i].sat = 0;
		new[i].eating = 0;
		if (pthread_mutex_init(&new[i].chopstick, NULL))
			ft_putendl("failed mutex");
		i++;
	}
	ft_putendl("Table successfully created.");
	return (new);
}
