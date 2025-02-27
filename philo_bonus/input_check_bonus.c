/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:32:25 by habdella          #+#    #+#             */
/*   Updated: 2025/02/22 12:51:42 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	semaphore_init(t_info *info)
{
	unlink_sem();
	info->enter = sem_open("/enter", O_CREAT, 0644, info->n_phil / 2);
	info->forks = sem_open("/forks", O_CREAT, 0644, info->n_phil);
	info->death = sem_open("/death", O_CREAT, 0644, 0);
	info->eat_limit = sem_open("/limit", O_CREAT, 0644, 0);
	info->print = sem_open("/print", O_CREAT, 0644, 1);
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
	info->z_time = 0;
	info->n_phil = (int)(ft_atol(av[1]));
	info->t_die = ft_atol(av[2]);
	info->t_eat = ft_atol(av[3]);
	info->t_sleep = ft_atol(av[4]);
	if (ac == 6)
		info->n_t_eat = ft_atol(av[5]);
	else
		info->n_t_eat = -1;
	semaphore_init(info);
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
