#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define MAX_INT 2147483647

typedef struct	s_info	t_info;

struct s_info
{
	int	num_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	num_must_eat;
};

int	str_err(char *str);
int	ft_strlen(char *str);
int	ft_atoi_pos(char *arg);

# endif
