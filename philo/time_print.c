/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:48:41 by habdella          #+#    #+#             */
/*   Updated: 2025/02/19 14:59:47 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

	pthread_mutex_lock(&philo->info->msg);
	pthread_mutex_lock(&philo->info->death);
	if (philo->info->stp)
	{
		pthread_mutex_unlock(&philo->info->msg);
		pthread_mutex_unlock(&philo->info->death);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->death);
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
		printf("%ld\t%d\t%s\n", curr_time() - time, philo->index, DEAD);
	pthread_mutex_unlock(&philo->info->msg);
	return (0);
}
