#include "philo.h"

int	str_err(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}
