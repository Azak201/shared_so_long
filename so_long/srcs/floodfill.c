#include <so_long.h>

/*this function apply the flood fill alg. on the map sent to it*/
void flood_fill(t_map **map, int p_row, int p_col)
{
	if (p_row < 0 || p_col < 0 || p_col >= (*map)->col_num || p_row >= (*map)->row_num)
		return;
	if ((*map)->fmap[p_row][p_col] == '1' || (*map)->fmap[p_row][p_col] == 'F')
		return;
	(*map)->fmap[p_row][p_col] = 'F';
	flood_fill(&(*map), p_row - 1, p_col);
	flood_fill(&(*map), p_row + 1, p_col);
	flood_fill(&(*map), p_row, p_col + 1);
	flood_fill(&(*map), p_row, p_col - 1);
}

void check_empty_lines(char **line)
{
	int i;

	i = 0;
	while ((*line)[i] != '\0')
	{
		if ((((*line)[i] == '\n') && ((*line)[i + 1] == '\0')) ||
			(((*line)[i] == '\n') && ((*line)[i + 1] == '\n')))
		{
			free(*line);
			ft_exit_fd(0, "there is empty lines", 0);
		}
		i++;
	}
}