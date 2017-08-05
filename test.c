#include <libft.h>

int main()
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		ft_putendl(line);
		free(line);
	}
}
