/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_print_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:30:44 by habdella          #+#    #+#             */
/*   Updated: 2025/02/22 14:48:44 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write (2, &s[i], 1);
		i++;
	}
}

long	curr_time(void)
{
	long			time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec * 0.001);
	return (time);
}

int	_print(t_philo *philo, int state)
{
	long	time;

	sem_wait(philo->info->print);
	time = philo->info->z_time;
	if (!state)
		printf("%ld\t%d\t%s\n", curr_time() - time, philo->index, THINK);
	else if (state == 1)
		printf("%ld\t%d\t%s\n", curr_time() - time, philo->index, FORK);
	else if (state == 2)
		printf("%ld\t%d\t%s\n", curr_time() - time, philo->index, EAT);
	else if (state == 3)
		printf("%ld\t%d\t%s\n", curr_time() - time, philo->index, SLEEP);
	else if (state == 4)
	{
		printf("%ld\t%d\t%s\n", curr_time() - time, philo->index, DEAD);
		return (1);
	}
	sem_post(philo->info->print);
	return (0);
}
