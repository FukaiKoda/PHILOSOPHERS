/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_life_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:57:06 by habdella          #+#    #+#             */
/*   Updated: 2025/02/22 15:27:24 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->l_meal = curr_time();
	philo->info->z_time = curr_time();
	_print(philo, 0);
	_print(philo, 1);
	usleep(philo->info->t_die * 1000);
	_print(philo, 4);
	return (NULL);
}

int	philo_eat(t_philo *philo)
{
	sem_wait(philo->info->enter);
	sem_wait(philo->info->forks);
	_print(philo, 1);
	sem_wait(philo->info->forks);
	_print(philo, 1);
	_print(philo, 2);
	philo->n_meals++;
	philo->l_meal = curr_time();
	usleep(philo->info->t_eat * 1000);
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
	sem_post(philo->info->enter);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	_print(philo, 3);
	usleep(philo->info->t_sleep * 1000);
	return (0);
}

void	*dining_table(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->l_meal = curr_time();
	philo->info->z_time = curr_time();
	while (1337)
	{
		_print(philo, 0);
		if (philo->info->n_phil % 2)
			usleep(1000);
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}
