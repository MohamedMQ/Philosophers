/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:21:56 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/05/31 10:21:58 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	make_philo(t_data *data)
{
	int			i;

	i = 0;
	data->life.start = get_time();
	while (i < data->nbr_philo)
	{
		data->pid[i] = fork();
		if (data->pid[i] == -1)
			return (msg("Error fork"), kill_processes(data, i), 1);
		if (data->pid[i] == 0)
			life(&data->philos[i], data);
		i += 2;
		if (i >= data->nbr_philo && i % 2 == 0)
		{
			i = 1;
			ft_usleep(data, 2);
		}
	}
	ft_waitpid_kill(data);
	return (0);
}

int	ft_waitpid_kill(t_data *data)
{
	int	i;
	int	status;

	i = -1;
	waitpid(-1, &status, 0);
	if ((status >> 8) == 1)
	{
		while (++i < data->nbr_philo)
			kill(data->pid[i], SIGKILL);
		destroy_semaphore(data);
		return (0);
	}
	i = -1;
	while (++i < data->nbr_philo)
		waitpid(data->pid[i], &status, 0);
	destroy_semaphore(data);
	return (0);
}

int	kill_processes(t_data *data, int until)
{
	int	i;

	i = 0;
	while (i < until)
	{
		usleep(100);
		kill(data->pid[i], SIGKILL);
		i += 2;
		if (i > until && i % 2 == 0)
			i = 1;
	}
	return (0);
}
