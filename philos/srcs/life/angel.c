/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:29:47 by yumatsui          #+#    #+#             */
/*   Updated: 2024/06/11 12:26:06 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*angel_life(void *tmp)
{
	int		i;
	int		eat_count;
	t_data	*data;

	data = (t_data *)tmp;
	i = 0;
	while (they_are(data) == ALIVE)
	{
		pthread_mutex_lock(&data->philo[i].meal_mutex);
		eat_count = data->philo[i].eat_count;
		pthread_mutex_unlock(&data->philo[i].meal_mutex);
		if (eat_count < data->count)
		{
			i = 0;
			continue ;
		}
		i ++;
		if (i == data->philo_num)
		{
			pthread_mutex_lock(&data->deadflag);
			data->theyre = DEAD;
			pthread_mutex_unlock(&data->deadflag);
		}
	}
	return (NULL);
}
