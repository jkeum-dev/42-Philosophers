#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include "structures.h"

# define MAX_INT 2147483647

# define FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5

int		str_err(char *str);
int		ft_strlen(char *str);
int		get_time(void);

int		ft_atoi_pos(char *arg);

int		dining_philo(t_info *info);
int		eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

void	print_status(t_philo *philo, int status);

#endif
