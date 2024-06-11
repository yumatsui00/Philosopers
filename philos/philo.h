/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumatsui <yumatsui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:12:23 by yumatsui          #+#    #+#             */
/*   Updated: 2024/06/11 12:39:44 by yumatsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>

# define ERROR -1
# define MALLOCERROR -2
# define OK 1
# define DEAD -1
# define END 0
# define ALIVE 1
# define FORK 10
# define EAT 11
# define SLEEP 12
# define THINK 13
# define DIE 14

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int				philo_num;
	int				time2die;
	int				time2eat;
	int				time2sleep;
	int				count;
	t_philo			*philo;
	pthread_t		reaper;
	pthread_t		angel;
	pthread_mutex_t	*forks;
	int				theyre;
	pthread_mutex_t	deadflag;
	long			starttime;
	pthread_mutex_t	writers_soul;
}	t_data;

typedef struct s_philo
{
	struct s_data	*data;
	int				num;
	pthread_t		thread;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	long			last_meal;
	int				eat_count;
	pthread_mutex_t	meal_mutex;
}	t_philo;

//life
void	*philo_life(void *tmp);
void	*reaper_life(void *tmp);
void	*angel_life(void *tmp);
void	*lonely_life(void *tmp);

int		they_are(t_data *data);

// utils
int		argcheck(int argc, char **argv, t_data *data);
void	ft_msleep(unsigned int ms);
int		ft_atoi(const char *str);
long	gettime(void);
t_philo	*init(t_data *data);
void	philo_state(t_philo *philo, int state);

#endif