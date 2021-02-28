int		distribute(char *buf, char **current, char **next)
{
	size_t	i;
	int		len;
	char	*xtr;
	int		rest_len;

	i = 0;
	while (buf[i] != '\n' && i < ft_strlen(buf))
		i++;
	if (i >= ft_strlen(buf))
		return (0);
	buf[i] = '\0';
	len = i + 1;
	rest_len = ft_strlen(buf) - len;
	xtr = (char*)malloc(len);
	while (len--)
		*xtr++ = *buf++;
	*current = &xtr[0];
	if (!rest_len)
		xtr = NULL;
	else
		xtr = (char*)malloc(rest_len);
	while (rest_len--)
		*xtr++ = *buf++;
	*next = xtr;
	return (1);
}
