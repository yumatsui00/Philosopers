/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:25:43 by yumatsui          #+#    #+#             */
/*   Updated: 2024/06/11 12:39:07 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	philo_sleep_and_think(t_philo *philo)
{
	long	bedtime;

	philo_state(philo, SLEEP);
	bedtime = gettime();
	while (gettime() - bedtime < philo->data->time2sleep)
	{
		usleep(100);
		if (they_are(philo->data) != ALIVE)
			break ;
	}
	philo_state(philo, THINK);
}

static void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	philo_state(philo, FORK);
	pthread_mutex_lock(philo->right);
	philo_state(philo, EAT);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = gettime();
	philo->eat_count ++;
	pthread_mutex_unlock(&philo->meal_mutex);
	while (gettime() - philo->last_meal < philo->data->time2eat)
	{
		usleep(100);
		if (they_are(philo->data) != ALIVE)
			break ;
	}
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
}

void	*philo_life(void *tmp)
{
	t_philo		*philo;

	philo = (t_philo *)tmp;
	if (philo->num % 2 == 1)
		ft_msleep(50);
	while (they_are(philo->data) == ALIVE)
	{
		philo_eat(philo);
		philo_sleep_and_think(philo);
	}
	return (NULL);
}

void	*lonely_life(void *tmp)
{
	t_philo	*philo;

	philo = (t_philo *)tmp;
	philo_state(philo, FORK);
	while (they_are(philo->data) == ALIVE)
		usleep(1000);
	return (NULL);
}
