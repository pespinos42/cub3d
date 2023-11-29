#include "cub3d.h"

int     ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char    *ft_strnstr(char *b, char *l, size_t len)
{
	size_t  p1;
	size_t  p2;

	p1 = 0;
	if (!*l)
		return (b);
	while (b[p1] && p1 < len)
	{
		p2 = 0;
		while (b[p1 + p2] && b[p1 + p2] == l[p2] && p1 + p2 < len)
		{
			if (l[p2 + 1] == '\0' && b[p1 + p2 + 1] == '\0')
				return (&b[p1]);
			p2++;
		}
		p1++;
	}
	return (NULL);
}

int	ft_allow_chars(char *s, t_data *d)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (d->flag_char == 0)
		{
			if (s[i] == 'N' || s[i] == 'S' || s[i] == 'E' || s[i] == 'W')
				d->flag_char = 1;
			else if (s[i] != '0' && s[i] != '1')
				return (0);
		}
		else
		{
			if (s[i] != '0' && s[i] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}
