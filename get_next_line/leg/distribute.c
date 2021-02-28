void	distribute(char *buf, char *current, char *next)
{
	int		i;
	int		j;
	char	*xtr;

	while (buf[i] != '\n' && i < strlen(buf))
		i++;
	if (i == strlen(buf))
		return;
	buf[i] = '\0';
	len = i + 1;
	xtr = (char*)malloc(len);
	while (j <= i)
	{
		xtr[j] = buf[j];
		j++;
	}
	*current = xtr;
	xtr = (char*)malloc(strlen(buf) - len);
	i = 0;
	ft_bzero(xtr, strlen(buf) - len);
	while (j < (strlen(buf) - len))
	{
		xtr[i] = buf [j]
		j++;
		i++;
	}
	*next = xtr;
	free(buf);
}
