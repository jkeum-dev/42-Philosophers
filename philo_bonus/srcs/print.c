#include "philo_bonus.h"

void	print_status(t_philo *philo, int status)
{
	sem_wait(philo->info->status);
	// if (philo->info->stop)
	// {
	// 	sem_post(philo->info->status);
	// 	return ;
	// }
	printf("%d\t", get_time() - philo->info->base_time);
	printf("Philo %d ", philo->n + 1);
	if (status == FORK)
		printf("has taken a fork\n");
	else if (status == EATING)
		printf("is eating\n");
	else if (status == SLEEPING)
		printf("is sleeping\n");
	else if (status == THINKING)
		printf("is thinking\n");
	else if (status == DIED)
		printf("died\n");
	sem_post(philo->info->status);
}
