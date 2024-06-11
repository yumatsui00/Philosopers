/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:36:06 by yumatsui          #+#    #+#             */
/*   Updated: 2024/06/11 12:34:45 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	philo_state(t_philo *philo, int state)
{
	long	time;

	if (they_are(philo->data) != ALIVE)
		return ;
	time = gettime() - philo->data->starttime;
	pthread_mutex_lock(&philo->data->writers_soul);
	if (state == FORK)
		printf("%ld %d has taken a fork 👉🍴\n", time, philo->num);
	else if (state == EAT)
	{
		printf("%ld %d has taken a fork 👉🍴\n", time, philo->num);
		printf("%ld %d is eating        😝🍝\n", time, philo->num);
	}
	else if (state == SLEEP)
		printf("%ld %d is sleeping      😴💤\n", time, philo->num);
	else if (state == THINK)
		printf("%ld %d is thinking      🤔💭\n", time, philo->num);
	pthread_mutex_unlock(&philo->data->writers_soul);
	return ;
}

// void	philo_state(t_philo *philo, int	state)
// {
// 	long	time;
// 	if (they_are(philo->data) != ALIVE)
// 		return ;
// 	time = gettime() - philo->data->starttime;
// 	pthread_mutex_lock(&philo->data->writers_soul);
// 	if (state == FORK)
// 		printf("%ld %d has taken a fork\n", time, philo->num);
// 	else if (state == EAT)
// 	{
// 		printf("%ld %d has taken a fork\n", time, philo->num);
// 		printf("%ld %d is eating\n", time, philo->num);
// 	}
// 	else if (state == SLEEP)
// 		printf("%ld %d is sleeping\n", time, philo->num);
// 	else if (state == THINK)
// 		printf("%ld %d is thinking\n", time, philo->num);
// 	pthread_mutex_unlock(&philo->data->writers_soul);
// 	return ;
// }