/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:17:04 by yumatsui          #+#    #+#             */
/*   Updated: 2024/06/10 19:31:00 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static int	argcheck2(char **argv)
{
	int	count;
	int	i;

	count = 0;
	while (argv[++count])
	{
		i = -1;
		while (argv[count][++i])
		{
			if (argv[count][i] < '0' || argv[count][i] > '9')
			{
				write(2, "INVALID ARGUMENTS: only num is allowed\n", 39);
				return (ERROR);
			}
		}
	}
	return (OK);
}

int	argcheck(int argc, char **argv, t_data *data)
{
	data->count = 0;
	if (argc != 5 && argc != 6)
		return (write(2, "Args have to be 5 or 6\n", 23));
	if (argcheck2(argv) == ERROR)
		return (ERROR);
	data->philo_num = ft_atoi(argv[1]);
	if (data->philo_num > 200 || data->philo_num < 1)
		return (write(2, "Philos num have to be between 1 & 200\n", 38));
	data->time2die = ft_atoi(argv[2]);
	if (data->time2die < 60)
		return (write(2, "Time2die has to be more than 60\n", 32));
	data->time2eat = ft_atoi(argv[3]);
	if (data->time2eat < 60)
		return (write(2, "Time2eat has to be more than 60\n", 32));
	data->time2sleep = ft_atoi(argv[4]);
	if (data->time2sleep < 60)
		return (write(2, "Time2sleep has to be more than 60\n", 34));
	if (argc == 6)
	{
		data->count = ft_atoi(argv[5]);
		if (data->count < 1)
			return (write(2, "INVALID ARGUMENTS\n", 18));
	}
	return (OK);
}
