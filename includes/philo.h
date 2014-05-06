/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 18:29:45 by npineau           #+#    #+#             */
/*   Updated: 2014/05/06 15:11:56 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define MAX_PHILO 7
# define MAX_LIFE 7
# define EAT_T 6
# define REST_T 3
# define THINK_T 4
# define TIMEOUT 60

void	*philosopher(void *id);

#endif
