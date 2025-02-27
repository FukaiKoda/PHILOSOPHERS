/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:25:12 by habdella          #+#    #+#             */
/*   Updated: 2025/02/20 18:34:45 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philo_init(t_info *info)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * info->n_phil);
	if (!philo)
		return (NULL);
	philo->forks = malloc(sizeof(pthread_mutex_t) * info->n_phil);
	if (!philo->forks)
		return (NULL);
	i = 0;
	while (i < info->n_phil)
	{
		philo[i].index = i + 1;
		philo[i].tid = 0;
		philo[i].l_meal = 0;
		philo[i].n_meals = 0;
		philo[i].info = info;
		philo[i].info->z_time = curr_time();
		pthread_mutex_init(&philo->forks[i], NULL);
		i++;
	}
	return (philo);
}

long	ft_atol(char *s)
{
	long	num;

	num = 0;
	if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		num = (*s - '0') + (num * 10);
		s++;
	}
	return (num);
}

void	info_init(t_info *info, int ac, char **av)
{
	info->stp = 0;
	info->z_time = 0;
	info->n_phil = (int)(ft_atol(av[1]));
	info->t_die = ft_atol(av[2]);
	info->t_eat = ft_atol(av[3]);
	info->t_sleep = ft_atol(av[4]);
	if (ac == 6)
		info->n_t_eat = ft_atol(av[5]);
	else
		info->n_t_eat = -1;
	pthread_mutex_init(&info->death, NULL);
	pthread_mutex_init(&info->msg, NULL);
	pthread_mutex_init(&info->lock, NULL);
}

int	check_arg(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[i] || s[i] == '-')
		return (1);
	if (s[i] == '+')
	{
		i++;
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
	}
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] != '\0')
		return (1);
	return (0);
}

int	check_args(int ac, char **av)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (ac != 5 && ac != 6)
		return (putstr("invalid number of args!\n"), 1);
	while (i < ac)
	{
		if (check_arg(av[i]) == 1)
			return (putstr("invalid input!\n"), 1);
		if (atol(av[i]) == 0)
			flag = 1;
		i++;
	}
	if (flag)
		return (putstr("invalid number: 0\n"), 1);
	return (0);
}
