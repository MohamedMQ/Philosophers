/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:21:50 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/05/31 10:21:52 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!check_args(argc, ++argv))
		return (1);
	if (!init(&data, argv))
		return (1);
	if (ft_atoi(argv[0]) == 1)
		return (one_phil(&data), 0);
	if (!make_philo(&data))
		return (1);
	return (0);
}

void	one_phil(t_data *data)
{
	data->pid[0] = fork();
	if (data->pid[0] == 0)
	{
		data->life.start = get_time();
		printf("0	1%s", TAKEN_FORK);
		ft_usleep(data, data->life.time_death);
		printf(BRED"%ld   1 %s"NC, data->life.time_death, PHILO_DIED);
	}
	waitpid(data->pid[0], NULL, 0);
	destroy_semaphore(data);
}
