/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:21:30 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/05/31 10:21:31 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*check_dead(void *data)
{
	int			i;
	t_philos	*philo;

	i = 0;
	philo = (t_philos *)data;
	while (!any_dead2(philo)
		&& (!philo->life->need_eating || !has_eaten(philo)))
	{
		if (any_dead2(philo))
			return (pthread_detach(philo->checker), NULL);
	}
	return (NULL);
}

int	any_dead2(t_philos *philo1)
{
	long long	time;

	sem_wait(philo1->life->time);
	time = get_time_since_start(philo1->life->start);
	sem_post(philo1->life->time);
	sem_wait(philo1->life->dead);
	if (philo1->life->smbdy_died == 1)
		return (sem_post(philo1->life->dead), 1);
	sem_post(philo1->life->dead);
	sem_wait(philo1->life->time);
	if (philo1->life->time_death < (time - philo1->dying))
	{
		sem_post(philo1->life->time);
		sem_wait(philo1->life->dead);
		philo1->life->smbdy_died = 1;
		sem_post(philo1->life->dead);
		sem_wait(philo1->life->write);
		printf(BRED"%lld   %d is dead\n"NC,
			get_time_since_start(philo1->life->start), philo1->nbr);
		usleep(1000);
		return (1);
	}
	sem_post(philo1->life->time);
	usleep(1000);
	return (0);
}

int	has_eaten(t_philos *philo)
{
	sem_wait(philo->life->eat);
	if (philo->has_eaten >= philo->life->need_eating)
	{
		sem_post(philo->life->eat);
		return (1);
	}
	sem_post(philo->life->eat);
	return (0);
}
