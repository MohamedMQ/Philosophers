/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:20:50 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/05/31 10:20:52 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	solitary(t_data *data)
{
	data->life.start = get_time();
	printf("0   1 %s", TAKEN_FORK);
	ft_usleep2(data, data->life.time_death);
	printf(D_RED"%ld   1 %s"NC, data->life.time_death, PHILO_DIED);
}

int	philo_fork(t_philos *philo1)
{
	if (philo1->nbr == 1)
	{
		pthread_mutex_lock(philo1->left_fork);
		if (ft_write_status(philo1, TAKEN_FORK, L_PURPLE))
			return (pthread_mutex_unlock(philo1->left_fork), 1);
		pthread_mutex_lock(philo1->right_fork);
		if (ft_write_status(philo1, TAKEN_FORK, R_CYAN))
			return (pthread_mutex_unlock(philo1->right_fork)
				, pthread_mutex_unlock(philo1->left_fork), 1);
	}
	else
	{
		pthread_mutex_lock(philo1->right_fork);
		if (ft_write_status(philo1, TAKEN_FORK, R_CYAN))
			return (pthread_mutex_unlock(philo1->right_fork), 1);
		pthread_mutex_lock(philo1->left_fork);
		if (ft_write_status(philo1, TAKEN_FORK, L_PURPLE))
			return (pthread_mutex_unlock(philo1->left_fork)
				, pthread_mutex_unlock(philo1->right_fork), 1);
	}
	return (0);
}

int	philo_eat(t_philos *philo1)
{
	if (ft_write_status(philo1, EATING, E_GREEN))
		return (pthread_mutex_unlock(philo1->right_fork)
			, pthread_mutex_unlock(philo1->left_fork), 1);
	pthread_mutex_lock(&philo1->life->time);
	philo1->dying = get_time_since_start(philo1->life->start);
	pthread_mutex_unlock(&philo1->life->time);
	ft_usleep(philo1, philo1->life->time_eat);
	pthread_mutex_lock(&philo1->life->eat);
	philo1->has_eaten++;
	pthread_mutex_unlock(&philo1->life->eat);
	pthread_mutex_unlock(philo1->left_fork);
	pthread_mutex_unlock(philo1->right_fork);
	return (0);
}

int	philo_sleep(t_philos *philo1)
{
	if (ft_write_status(philo1, SLEEPING, S_BLUE))
		return (1);
	ft_usleep(philo1, philo1->life->time_sleep);
	return (0);
}

int	philo_think(t_philos *philo1)
{
	if (ft_write_status(philo1, THINKING, NC))
		return (1);
	return (0);
}
