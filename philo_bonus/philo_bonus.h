/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:23:23 by habdella          #+#    #+#             */
/*   Updated: 2025/02/23 13:12:18 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <semaphore.h>

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
	sem_t			*forks;
	sem_t			*death;
	sem_t			*print;
	sem_t			*eat_limit;
	sem_t			*enter;
}	t_info;

typedef struct s_philo
{
	pthread_t		tid;
	long			l_meal;
	int				index;
	int				n_meals;
	pid_t			pid[62020];
	t_info			*info;
}	t_philo;

/* /////////////// input checks \\\\\\\\\\\\\\\ */
int		check_args(int ac, char **av);
int		check_arg(char *s);
void	putstr(char *s);
void	info_init(t_info *info, int ac, char **av);
long	ft_atol(char *s);
void	philo_init(t_philo *philo, t_info *info);
/* /////////////// routine \\\\\\\\\\\\\\\ */
void	*dining_table(void *arg);
void	*one_philo(void *arg);
int		philo_eat(t_philo *philo);
int		philo_sleep(t_philo *philo);
/* /////////////// time and actions \\\\\\\\\\\\\\\ */
long	curr_time(void);
int		_print(t_philo *philo, int state);
/* /////////////// start \\\\\\\\\\\\\\\ */
void	launch(t_philo *philo);
void	new_process(t_philo *philo);
void	monitoring(t_philo *philo);
/* /////////////// monitoring \\\\\\\\\\\\\\\ */
void	main_monitore(t_philo *philo);
void	*second_monitore(void *arg);
/* /////////////// close unlink free \\\\\\\\\\\\\\\ */
void	clean_all(t_philo *philo, t_info *info);
void	close_sem(t_info *info);
void	unlink_sem(void);

#endif