/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:06:29 by habdella          #+#    #+#             */
/*   Updated: 2025/02/21 10:44:39 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define THINK "is thinking"
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define DEAD "died"

typedef struct s_info
{
	long			z_time;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	long			n_t_eat;
	int				n_phil;
	int				stp;
	pthread_mutex_t	death;
	pthread_mutex_t	lock;
	pthread_mutex_t	msg;
}	t_info;

typedef struct s_philo
{
	pthread_t		tid;
	long			l_meal;
	int				index;
	int				n_meals;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*forks;
	t_info			*info;
}	t_philo;

/* /////////////// input checks \\\\\\\\\\\\\\\ */
int		check_args(int ac, char **av);
int		check_arg(char *s);
void	putstr(char *s);
void	info_init(t_info *info, int ac, char **av);
long	ft_atol(char *s);
t_philo	*philo_init(t_info *info);
/* /////////////// threads lunch \\\\\\\\\\\\\\\ */
void	launch(t_philo *philo);
void	*dining_table(void *arg);
/* /////////////// routine \\\\\\\\\\\\\\\ */
void	*one_philo(void *arg);
int		philo_eat(t_philo *philo);
int		philo_sleep(t_philo *philo);
/* /////////////// monitoring \\\\\\\\\\\\\\\ */
void	monitoring(t_philo *philo);
int		monitore_eating(t_philo *philo);
void	monitore_death(t_philo *philo, int i);
/* /////////////// time and actions \\\\\\\\\\\\\\\ */
long	curr_time(void);
int		_print(t_philo *philo, int state);
/* /////////////// destroy and free \\\\\\\\\\\\\\\ */
void	threads_join(t_philo *philo);
void	free_all(t_philo *philo, t_info *info);
void	free_philos(t_philo *philo, t_info info);
void	destroy_forks(t_philo *philo, pthread_mutex_t *mutex);

#endif