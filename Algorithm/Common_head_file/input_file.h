char *input_file(char* file);

char *input_file(char *file)
{
	int i = 1;
	char* string = malloc(sizeof(char));
	FILE* input = fopen(file, "r");
	if (input == NULL)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	while(!feof(input)) {
		char c = fgetc(input);
		if (c != '\n' && c != ' ' && !feof(input)) {
			string = realloc(string, (i + 1) * sizeof(char));
			if (string == NULL) {
				printf("Memory allocation failed.");
				exit(EXIT_FAILURE);
			};
			string[i - 1] = c;
			i++;
		}
	}
	string[i - 1] = '\0';
	return string;
}