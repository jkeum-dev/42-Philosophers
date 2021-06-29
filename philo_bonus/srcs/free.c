#include "philo_bonus.h"

void	ft_sem_close_unlink(t_info *info)
{
	sem_close(info->fork);
	sem_close(info->status);
	sem_close(info->full);
	sem_close(info->died);
	sem_close(info->print_died);
	sem_unlink("/fork");
	sem_unlink("/status");
	sem_unlink("/full");
	sem_unlink("/died");
	sem_unlink("/print_died");
}

void	free_all(t_info *info)
{
	int		i;
	char	*name;

	if (!info->all_full)
		sem_post(info->full);
	else
		sem_post(info->died);
	ft_sem_close_unlink(info);
	i = -1;
	while (++i < info->num_philo)
	{
		sem_close(info->philo[i].protect);
		name = ft_strjoin_free("/protect", ft_itoa(i + 1));
		sem_unlink(name);
		free(name);
	}
	free(info->philo);
}
