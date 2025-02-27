/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:05:06 by habdella          #+#    #+#             */
/*   Updated: 2025/02/27 08:20:39 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	launch(t_philo *philo)
{
	int	i;

	if (philo->info->n_phil == 1)
	{
		philo[0].l_meal = curr_time();
		pthread_create(&philo[0].tid, NULL, &one_philo, (void *)(&philo[0]));
		pthread_join(philo[0].tid, NULL);
		return ;
	}
	i = 0;
	while (i < philo->info->n_phil)
	{
		philo[i].left = &philo->forks[i];
		philo[i].right = &philo->forks[(i + 1) % philo->info->n_phil];
		philo[i].l_meal = curr_time();
		pthread_create(&philo[i].tid, NULL, &dining_table, (void *)(philo + i));
		i++;
	}
	monitoring(philo);
	threads_join(philo);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_info	info;

	if (check_args(ac, av))
		return (1);
	info_init(&info, ac, av);
	philo = philo_init(&info);
	if (!philo)
		return (1);
	launch(philo);
	free_all(philo, &info);
	return (0);
}
