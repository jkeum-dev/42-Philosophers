#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include "structures.h"

# define MAX_INT 2147483647

int	str_err(char *str);
int	ft_strlen(char *str);
int	get_time(void);

int	ft_atoi_pos(char *arg);

int	dining_philo(t_info *info);

# endif
