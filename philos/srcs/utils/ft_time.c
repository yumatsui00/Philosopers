/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:09:34 by yumatsui          #+#    #+#             */
/*   Updated: 2024/06/11 12:37:03 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

long	gettime(void)
{
	struct timeval	time;
	long			ret;

	gettimeofday(&time, NULL);
	ret = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ret);
}

void	ft_msleep(unsigned int ms)
{
	struct timeval	start;
	struct timeval	end;
	unsigned int	time;

	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&end, NULL);
		time = (end.tv_sec - start.tv_sec) * 1000 + \
				(end.tv_usec - start.tv_usec) / 1000;
		if (time >= ms)
			break ;
		usleep(150);
	}
}

// int main()
// {
// 	struct timeval start, end;
// 	int i = 0;
// 	// usleep(5000000);
// 	ft_usleep(5000);
// 	// gettimeofday(&start, NULL);
// 	// while (i < 5)
// 	// {
// 	// 	gettimeofday(&end, NULL);
// 	// 	i = (end.tv_sec - start.tv_sec);
// 	// 	usleep(1000000);
// 	// 	printf("i = %d\n", i);
// 	// }
// }
