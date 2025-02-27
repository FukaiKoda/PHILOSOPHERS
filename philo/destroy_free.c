/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:44:39 by habdella          #+#    #+#             */
/*   Updated: 2025/02/19 14:57:01 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	threads_join(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->n_phil)
	{
		pthread_join(philo[i].tid, NULL);
		i++;
	}
}

void	destroy_forks(t_philo *philo, pthread_mutex_t *mutex)
{
	int	i;

	i = 0;
	while (i < philo->info->n_phil)
	{
		pthread_mutex_destroy(&mutex[i]);
		i++;
	}
	free(mutex);
}

void	free_philos(t_philo *philo, t_info info)
{
	int	i;

	i = 0;
	while (i < info.n_phil)
	{
		pthread_mutex_destroy(philo[i].left);
		pthread_mutex_destroy(philo[i].right);
		i++;
	}
	free(philo);
}

void	free_all(t_philo *philo, t_info *info)
{
	if (philo->forks)
		destroy_forks(philo, philo->forks);
	if (philo)
		free(philo);
	pthread_mutex_destroy(&info->death);
	pthread_mutex_destroy(&info->msg);
}
