/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:15:59 by habdella          #+#    #+#             */
/*   Updated: 2025/02/21 08:50:43 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitore_eating(t_philo *philo)
{
	int		i;
	int		meals;

	i = 0;
	meals = 0;
	while (i < philo->info->n_phil)
	{
		pthread_mutex_lock(&philo->info->lock);
		if (philo[i].n_meals >= philo->info->n_t_eat
			&& philo->info->n_t_eat > 0)
			meals++;
		pthread_mutex_unlock(&philo->info->lock);
		i++;
	}
	if (meals == philo->info->n_phil)
		return (1);
	return (0);
}

void	monitore_death(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->info->lock);
	if (curr_time() - philo[i].l_meal >= philo->info->t_die)
	{
		pthread_mutex_unlock(&philo->info->lock);
		_print(&philo[i], 4);
		pthread_mutex_lock(&philo->info->death);
		philo[i].info->stp = 1;
		pthread_mutex_unlock(&philo->info->death);
		return ;
	}
	pthread_mutex_unlock(&philo->info->lock);
}

void	monitoring(t_philo *philo)
{
	int	i;

	while (1337)
	{
		i = 0;
		while (i < philo->info->n_phil)
		{
			monitore_death(philo, i);
			if (philo->info->stp == 1)
				return ;
			i++;
		}
		if (monitore_eating(philo) == 1)
		{
			pthread_mutex_lock(&philo->info->death);
			philo->info->stp = 1;
			pthread_mutex_unlock(&philo->info->death);
			return ;
		}
	}
}
