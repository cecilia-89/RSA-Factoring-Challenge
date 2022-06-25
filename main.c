#include "main.h"

int main(__attribute__ ((unused)) int argc, char **argv)
{
	char *line, *ptr;

	unsigned long long count, res, int_line;

	size_t buffer;

	FILE *file;

	buffer = 32;

	file = fopen(argv[1], "r");

	if (file == NULL || argc != 2)
	{
		fprintf(stderr, "USAGE: factors <file>\n");

		exit (EXIT_FAILURE);
	}

	line = malloc(buffer);

	while (getline(&line, &buffer, file) > 1)
	{
		count = 2;

		int_line = strtoll(line, &ptr, 10);

		for (count; count < int_line; count++)
		{
			if (int_line % count == 0)
			{
				res = int_line / count;

				printf("%lld=%lld*%lld\n", int_line, res, count);

				break;
			}

		}
	}

	return (0);
}


