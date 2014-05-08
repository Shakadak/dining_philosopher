/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 15:18:07 by npineau           #+#    #+#             */
/*   Updated: 2014/05/08 18:21:20 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "philo.h"

void	think(int id, t_philo *list, int stick_id)
{
	pthread_mutex_unlock(&list[stick_id].chopstick);
	list[id].eating = 0;
	ft_putstr("\nPhilosopher #");
	ft_putnbr(id);
	ft_putendl(" is thinking.\n\t\tlol\n");
	usleep(1000000 * THINK_T);
}
