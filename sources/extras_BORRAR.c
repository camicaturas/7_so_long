//BORRAR ESTE ARCHIVO EN LA ESCUELA

#include "so_long.h"


int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	if ((*s1 - *s2) < 0)
		return (-1);
	else if ((*s1 - *s2) > 0)
		return (1);
	else
		return (0);
}


char	*ft_readed_line(char *start)
{
	int		i;
	char	*line;

	if (!start || !start[0])
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
	{
		line[i] = start[i];
		i++;
	}
	if (start[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_next_line(char	*start)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\0')
	{
		free(start);
		return (NULL);
	}
	i += (start[i] == '\n');
	new_buff = (char *)malloc(1 + ft_strlen(start) - i);
	if (!new_buff)
		return (NULL);
	j = 0;
	while (start[i + j])
	{
		new_buff[j] = start[i + j];
		j++;
	}
	new_buff[j] = '\0';
	free(start);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	char		*buffer_content;
	int			fd_read;
	static char	*start_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_read = 1;
	buffer_content = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer_content)
		return (NULL);
	while (fd_read != 0)
	{
		fd_read = read(fd, buffer_content, BUFFER_SIZE);
		if (fd_read == -1)
			return ((free(buffer_content), (NULL)));
		buffer_content[fd_read] = '\0';
		start_str = ft_strjoin(start_str, buffer_content);
		if (ft_strchr (start_str, '\n'))
			break ;
	}
	free(buffer_content);
	buffer_content = ft_readed_line(start_str);
	start_str = ft_next_line(start_str);
	return (buffer_content);
}



size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	max;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	max = nmemb * size;
	if (max / nmemb != size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	newstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}




int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}


int	ft_printdigit(long n, int base, int uppercase)
{
	int			value;
	const char	*chars;

	value = 0;
	if (n < 0)
	{
		value += write(1, "-", 1);
		value += ft_printdigit(-n, base, uppercase);
	}
	else if (n < base)
	{
		if (uppercase)
			chars = "0123456789ABCDEF";
		else
			chars = "0123456789abcdef";
		return (value += write(1, &chars[n], 1));
	}
	else
	{
		value += ft_printdigit(n / base, base, uppercase);
		value += ft_printdigit(n % base, base, uppercase);
	}
	return (value);
}


int	printformat(va_list args, char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		print_length += ft_printdigit(va_arg(args, int), 10, 0);
	else if (format == 'p')
		print_length += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'u')
		print_length += ft_printdigit(va_arg(args, unsigned int), 10, 0);
	else if (format == 'x')
		print_length += ft_printdigit(va_arg(args, unsigned int), 16, 0);
	else if (format == 'X')
		print_length += ft_printdigit(va_arg(args, unsigned int), 16, 1);
	else if (format == '%')
		print_length += write(1, "%", 1);
	else
		print_length += write(1, &format, 1);
	return (print_length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		charactercount;

	i = 0;
	charactercount = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			charactercount += printformat(args, format[i + 1]);
			i++;
		}
		else
			charactercount += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (charactercount);
}


static	int	ft_putptr(uintptr_t num)
{
	char	*chars;
	int		value;

	value = 0;
	chars = "0123456789abcdef";
	if (num >= 16)
	{
		value += ft_putptr(num / 16);
		value += ft_putptr(num % 16);
	}
	else
		value += write(1, &chars[num], 1);
	return (value);
}

int	ft_printptr(unsigned long long ptr)
{
	int	value;

	value = 0;
	if (!ptr)
		value += write(1, "(nil)", 5);
	else
	{
		value += ft_printstr("0x");
		value += ft_putptr(ptr);
	}
	return (value);
}


int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}