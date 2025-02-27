/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:05:15 by habdella          #+#    #+#             */
/*   Updated: 2025/02/22 15:00:10 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	main_monitore(t_philo *philo)
{
	int	i;

	i = 0;
	sem_wait(philo->info->death);
	while (i++ <= philo->info->n_phil + 1)
		sem_post(philo->info->eat_limit);
	i = 0;
	while (i < philo->info->n_phil)
	{
		kill(philo->pid[i], SIGKILL);
		i++;
	}
	return ;
}

void	*second_monitore(void *arg)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)arg;
	while (i < philo->info->n_phil)
	{
		sem_wait(philo->info->eat_limit);
		i++;
	}
	sem_post(philo->info->death);
	return (NULL);
}

void	new_process(t_philo *philo)
{
	if (philo->info->n_phil == 1)
	{
		pthread_create(&philo->tid, NULL, &one_philo, (void *)(philo));
		pthread_join(philo->tid, NULL);
		return ;
	}
	philo->l_meal = curr_time();
	philo->info->z_time = curr_time();
	pthread_create(&philo->tid, NULL, &dining_table, (void *)(philo));
	monitoring(philo);
	pthread_join(philo->tid, NULL);
	return ;
}

void	launch(t_philo *philo)
{
	int		i;

	i = 0;
	while (i < philo->info->n_phil)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] == 0)
		{
			philo->index = i + 1;
			new_process(philo);
		}
		i++;
	}
	if (philo->info->n_phil == 1)
	{
		waitpid(philo->pid[0], NULL, 0);
		return ;
	}
	pthread_create(&philo->tid, NULL, &second_monitore, (void *)(philo));
	main_monitore(philo);
	pthread_join(philo->tid, NULL);
	return ;
}
