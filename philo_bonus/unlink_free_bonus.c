/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_free_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 08:54:27 by habdella          #+#    #+#             */
/*   Updated: 2025/02/22 14:54:19 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	close_sem(t_info *info)
{
	sem_close(info->enter);
	sem_close(info->forks);
	sem_close(info->death);
	sem_close(info->print);
	sem_close(info->eat_limit);
}

void	unlink_sem(void)
{
	sem_unlink("/enter");
	sem_unlink("/forks");
	sem_unlink("/death");
	sem_unlink("/limit");
	sem_unlink("/print");
}

void	clean_all(t_philo *philo, t_info *info)
{
	close_sem(info);
	unlink_sem();
	if (philo)
		free(philo);
	philo = NULL;
}
