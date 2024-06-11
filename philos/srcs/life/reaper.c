/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:29:31 by yumatsui          #+#    #+#             */
/*   Updated: 2024/06/11 12:37:57 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	they_are(t_data *data)
{
	int	deadflag;

	pthread_mutex_lock(&data->deadflag);
	deadflag = data->theyre;
	pthread_mutex_unlock(&data->deadflag);
	return (deadflag);
}

static void	reaper_work(t_data *data, int i)
{
	pthread_mutex_lock(&data->deadflag);
	data->theyre = DEAD;
	pthread_mutex_unlock(&data->deadflag);
	pthread_mutex_lock(&data->writers_soul);
	printf("%ld %d died   💀⚰  😭😿😢\n", gettime() - data->starttime, i + 1);
	pthread_mutex_unlock(&data->writers_soul);
}

void	*reaper_life(void *tmp)
{
	t_data	*data;
	int		i;
	long	last_meal;

	data = (t_data *)tmp;
	ft_msleep(10);
	i = 0;
	while (they_are(data) == ALIVE)
	{
		pthread_mutex_lock(&data->philo[i].meal_mutex);
		last_meal = data->philo[i].last_meal;
		pthread_mutex_unlock(&data->philo[i].meal_mutex);
		if (data->time2die < gettime() - last_meal)
		{
			reaper_work(data, i);
			break ;
		}
		i++;
		if (i == data->philo_num)
			i = 0;
	}
	return (NULL);
}

// static void	reaper_work(t_data *data, int i)
// {
// 	pthread_mutex_lock(&data->deadflag);
// 	data->theyre = DEAD;
// 	pthread_mutex_unlock(&data->deadflag);
// 	pthread_mutex_lock(&data->writers_soul);
// 	printf("%ld %d died\n", gettime() - data->starttime, i + 1);
// 	pthread_mutex_unlock(&data->writers_soul);
// }