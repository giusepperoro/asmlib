#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <sys/errno.h>
#include "libasm.h"

size_t	ft_strlen(char *str);

int		main(int argc, char **argv)
{
	(void)argc;

	char	*str = "aabbcc";
	char	str2[10];
	char	str3[7] = "zzxxcc";
	char	*str4 = NULL;
	char	*str5 = "sdbgisdjbfkasjbfaskjfbnas fas hoahfi ahsfj ashf asflakshf dsjbFK DSbfkjbF ;jdbf;dsjg;3b2i 3b2r;k23b41;2b4";
	char	*str6;
	char	*str7;
	int		fd;
	int		rd = 0;
	char	buf[32] = {0};
	char	Buff2[32] = {0};

	str6 = malloc(4);
	str7 = malloc(7);
	str6 = "mem";
	str7 = "kekmem";

	printf("\nft_write\n");
	printf("ft_write  |%zd|\n", ft_write(1, "Hello\n", 6));
	printf("write     |%zd|\n", write(1, "Hello\n", 6));


	printf("\nft_strcpy\n");
	printf("ft_strcpy |%s|\n", ft_strcpy(str2, "Hello lol"));
	printf("strcpy    |%s|\n", strcpy(str2, "Hello lol"));


	printf("\nft_strlen\n");
	printf("strlen    |%lu|\n", strlen(str));
	printf("ft_strlen |%zu|\n", ft_strlen(str));
	printf("strlen    |%lu|\n", strlen(str5));
	printf("ft_strlen |%zu|\n", ft_strlen(str5));

	printf("\nft_strcmp\n");
	printf("1\n");
	printf("strcmp    |%d|\n", strcmp("", str7));
	printf("ft_strcmp |%d|\n", ft_strcmp("", str7));
	printf("2\n");
	printf("strcmp    |%d|\n", strcmp(str6, ""));
	printf("ft_strcmp |%d|\n", ft_strcmp(str6, ""));
	printf("3\n");
	printf("strcmp    |%d|\n", strcmp(str6, str7));
	printf("ft_strcmp |%d|\n", ft_strcmp(str6, str7));
	printf("4\n");
	printf("strcmp    |%d|\n", strcmp("Hello", "Hello"));
	printf("ft_strcmp |%d|\n", ft_strcmp("Hello", "Hello"));
	printf("5\n");
	printf("strcmp    |%d|   > 0\n", strcmp("hello", "Hello"));
	printf("ft_strcmp |%d|  > 0\n", ft_strcmp("hello", "Hello"));
	printf("6\n");
	printf("strcmp    |%d|  < 0\n", strcmp("Hello", "hello hi"));
	printf("ft_strcmp |%d| < 0\n", ft_strcmp("Hello", "hello hi"));

	printf("\nft_strdup\n");
	printf("strdup     |%s|\n", strdup(str6));
	str4 = ft_strdup(str6);
	printf("ft_strdup  |%s|\n", str4);
	printf("strdup     |%s|\n", strdup(""));
	printf("ft_strdup  |%s|\n", ft_strdup(""));
	free(str4);



	printf("Errors:\n");
	errno = 0;
	printf("ft_write  |%zd|\n", ft_write(-1, "Hello\n", 6));
	printf("-1 fd errno: %s\n", strerror(errno));
	errno = 0;
	printf("write     |%zd|\n", write(1, NULL, 6));
	printf("null str errno: %s\n", strerror(errno));
	errno = 0;
	printf("write     |%zd|\n", write(-1, "Hello\n", 6));
	printf("-1 fd errno: %s\n", strerror(errno));
	errno = 0;
	printf("ft_write  |%zd|\n", ft_write(1, NULL, 6));
	printf("null str errno: %s\n", strerror(errno));

	printf("ft_read:\n");
	if (!(rd = ft_read(0, Buff2, 16)))
		return (-1);
	printf("bytes read from 0 fd: %d\n", rd);
	printf("buf = |%s|\n", Buff2);

	if (!(fd = open(argv[1], O_RDONLY)))
		return (-1);
	if (!(rd = ft_read(fd, buf, 16)))
		return (-1);
	printf("bytes read from file: %d\n", rd);
	printf("buf = |%s|\n", buf);
	close(fd);

	printf("\nread:\n");
	memset(Buff2, 0, sizeof(char) * 32);
	if (!(rd = read(0, Buff2, 16)))
		return (-1);
	printf("bytes read from 0 fd: %d\n", rd);
	printf("buf = |%s|\n", Buff2);
	if (!(fd = open(argv[1], O_RDONLY)))
		return (-1);
	memset(Buff2, 0, sizeof(char) * 32);
	if (!(rd = read(fd, buf, 16)))
		return (-1);
	printf("bytes read from file: %d\n", rd);
	printf("buf = %s", buf);
	printf("\n");

	printf("Errors:\n");
	errno = 0;
	if (!(rd = ft_read(-1, buf, 16)))
		return (-1);
	printf("-1 fd errno: %s\n", strerror(errno));
	errno = 0;
	if (!(rd = ft_read(fd, "", 16)))
		return (-1);
	printf("null buf: %s\n", strerror(errno));
	close(fd);

	return (1);
}
