/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 08:51:09 by habdella          #+#    #+#             */
/*   Updated: 2025/02/22 14:49:33 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	monitoring(t_philo *philo)
{
	while (1337)
	{
		if (curr_time() - philo->l_meal >= philo->info->t_die)
		{
			_print(philo, 4);
			sem_post(philo->info->death);
			return ;
		}
		if (philo->n_meals >= philo->info->n_t_eat
			&& philo->info->n_t_eat > 0)
		{
			sem_post(philo->info->eat_limit);
			return ;
		}
	}
}
