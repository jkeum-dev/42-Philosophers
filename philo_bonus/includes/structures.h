#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <unistd.h>	// fork, usleep
# include <pthread.h>	// pthread_()

typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

struct	s_info
{
	int			num_philo;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			num_must_eat;
	int			stop;
	int			base_time;
	int			all_full;
	sem_t		*fork;
	sem_t		*status;
	sem_t		*full;
	sem_t		*died;
	pthread_t	full_t;
	pthread_t	died_t;
	t_philo		*philo;
};

struct	s_philo
{
	int			n;
	int			start_time;
	int			meals;
	pid_t		philo_p;
	sem_t		*protect;
	pthread_t	monitor;
	t_info		*info;
};

#endif
