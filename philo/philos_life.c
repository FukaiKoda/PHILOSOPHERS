/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_life.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:46:50 by habdella          #+#    #+#             */
/*   Updated: 2025/02/22 16:41:49 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	_print(philo, 0);
	_print(philo, 1);
	usleep(philo->info->t_die * 1000);
	_print(philo, 4);
	return (NULL);
}

int	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->death);
	if (philo->info->stp)
	{
		pthread_mutex_unlock(&philo->info->death);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->death);
	pthread_mutex_lock(philo->left);
	_print(philo, 1);
	pthread_mutex_lock(philo->right);
	_print(philo, 1);
	_print(philo, 2);
	pthread_mutex_lock(&philo->info->lock);
	philo->n_meals++;
	philo->l_meal = curr_time();
	pthread_mutex_unlock(&philo->info->lock);
	usleep(philo->info->t_eat * 1000);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	if (_print(philo, 3))
		return (1);
	usleep(philo->info->t_sleep * 1000);
	return (0);
}

void	*dining_table(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->index % 2 == 0)
		usleep(1000);
	while (1337)
	{
		if (_print(philo, 0))
			return (NULL);
		if (philo->info->n_phil % 2)
			usleep(1000);
		if (philo_eat(philo))
			return (NULL);
		if (philo_sleep(philo))
			return (NULL);
	}
	return (NULL);
}
