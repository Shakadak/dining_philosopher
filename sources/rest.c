/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 14:54:39 by npineau           #+#    #+#             */
/*   Updated: 2014/05/08 18:20:22 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "philo.h"

void	rest(int id, t_philo *list)
{
	list[id].eating = 0;
	ft_putstr("\nPhilosopher #");
	ft_putnbr(id);
	ft_putendl(" is resting.\n\t\tLike usual...");
	usleep(1000000 * REST_T);
}
