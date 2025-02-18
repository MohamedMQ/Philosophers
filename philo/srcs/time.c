/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:21:04 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/05/31 10:21:05 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

long long	get_time_since_start(long long time_to_wait)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (time_to_wait > 0)
		return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - time_to_wait);
	return (0);
}

long long	get_time_since_start2(long long time_to_wait)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (time_to_wait > 0)
		return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - time_to_wait);
	return (0);
}

void	ft_usleep(t_philos *data, long int time_in_ms)
{
	long int	start_time;

	start_time = get_time_since_start(data->life->start);
	while (get_time_since_start(data->life->start) < start_time + time_in_ms)
	{
		pthread_mutex_lock(&data->life->dead);
		if (data->life->smbdy_died)
		{
			pthread_mutex_unlock(&data->life->dead);
			return ;
		}
		pthread_mutex_unlock(&data->life->dead);
		usleep(time_in_ms / 20);
	}
}

void	ft_usleep2(t_data *data, long int time_in_ms)
{
	long int	start_time;

	start_time = get_time_since_start(data->life.start);
	while (get_time_since_start(data->life.start) < start_time + time_in_ms)
	{
		pthread_mutex_lock(&data->life.dead);
		if (data->life.smbdy_died)
		{
			pthread_mutex_unlock(&data->life.dead);
			return ;
		}
		pthread_mutex_unlock(&data->life.dead);
		usleep(time_in_ms / 20);
	}
}
