#include "philo.h"

void	print_status(t_philo *philo, int status)
{
	if (philo->info->stop)
		return ;
	pthread_mutex_lock(&(philo->info->status));
	printf("%d\t\t", get_time() - philo->info->base_time);
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
	pthread_mutex_unlock(&(philo->info->status));
}
