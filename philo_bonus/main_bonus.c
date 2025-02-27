/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:25:22 by habdella          #+#    #+#             */
/*   Updated: 2025/02/22 14:48:12 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_init(t_philo *philo, t_info *info)
{
	philo->index = 0;
	philo->tid = 0;
	philo->l_meal = 0;
	philo->n_meals = 0;
	philo->info = info;
	philo->info->z_time = 0;
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_info	info;

	if (check_args(ac, av))
		return (1);
	info_init(&info, ac, av);
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (1);
	philo_init(philo, &info);
	launch(philo);
	clean_all(philo, &info);
	return (0);
}
