/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 14:44:21 by npineau           #+#    #+#             */
/*   Updated: 2014/05/08 18:02:51 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "libft.h"
#include "philo.h"

int	main(void)
{
	long		i;
	pthread_t	philos[MAX_PHILO + 1];
	t_philo		*list;

	i = 0;
	list = (t_philo *)philosopher((void *)-1);
	while (i < MAX_PHILO)
	{
		pthread_create(&philos[i], NULL, philosopher, (void *)i);
		i++;
	}
	pthread_create(&philos[i], NULL, master, (void *)list);
	pthread_join(philos[i], (void *)&i);
	ft_putstr("\nPhilosopher #");
	ft_putnbr(i);
	ft_putendl(" just died.\n");
	return (0);
}
