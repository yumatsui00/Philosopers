/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:16:09 by yumatsui          #+#    #+#             */
/*   Updated: 2024/06/11 12:38:41 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	destroyer(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		pthread_mutex_destroy(&philo[i].meal_mutex);
		pthread_mutex_destroy(&data->forks[i]);
	}
	pthread_mutex_destroy(&data->deadflag);
	pthread_mutex_destroy(&data->writers_soul);
	free(philo);
	free(data->forks);
}

static void	lonely_philosopher(t_philo *philo, t_data *data)
{
	pthread_create(&philo[0].thread, NULL, lonely_life, &philo[0]);
	pthread_create(&data->reaper, NULL, reaper_life, data);
	pthread_join(philo[0].thread, NULL);
	pthread_join(data->reaper, NULL);
}

static void	enjoy_your_meal(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
		pthread_create(&philo[i].thread, NULL, philo_life, &philo[i]);
	pthread_create(&data->reaper, NULL, reaper_life, data);
	if (data->count != 0)
		pthread_create(&data->angel, NULL, angel_life, data);
	i = -1;
	while (++i < data->philo_num)
		pthread_join(philo[i].thread, NULL);
	pthread_join(data->reaper, NULL);
	if (data->count != 0)
		pthread_join(data->angel, NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (argcheck(argc, argv, &data) != OK)
		return (ERROR);
	data.starttime = gettime();
	philo = init(&data);
	if (data.philo_num == 1)
		lonely_philosopher(philo, &data);
	else
		enjoy_your_meal(philo, &data);
	destroyer(&data, philo);
	return (OK);
}
