/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:06:01 by yumatsui          #+#    #+#             */
/*   Updated: 2024/06/10 18:50:38 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	pthread_initer(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
		pthread_mutex_init(&data->forks[i], NULL);
	pthread_mutex_init(&data->deadflag, NULL);
	pthread_mutex_init(&data->writers_soul, NULL);
}

t_philo	*init(t_data *data)
{
	t_philo			*philo;
	int				i;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->philo_num);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	pthread_initer(data);
	i = -1;
	while (++i < data->philo_num)
	{
		philo[i].num = i + 1;
		philo[i].last_meal = gettime();
		philo[i].data = data;
		philo[i].eat_count = 0;
		pthread_mutex_init(&philo[i].meal_mutex, NULL);
		if (i == 0)
			philo[i].right = &data->forks[data->philo_num - 1];
		else
			philo[i].right = &data->forks[i - 1];
		philo[i].left = &data->forks[i];
	}
	data->philo = philo;
	data->starttime = gettime();
	data->theyre = ALIVE;
	return (philo);
}
