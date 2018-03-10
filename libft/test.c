#include "libft.h"

int	main(int argc, char ** argv)
{
	char	*line;
	int		fd;

	if (argc != 2)
		return (1);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (1);
	while (ft_get_next_line(fd, &line))
	{
		ft_putendl(line);
		free(line);
	}
	return (0);
}
