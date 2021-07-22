#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fd, void *buf, size_t count);
size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strdup(const char *str);
int		ft_list_size(t_list *list);
int		ft_list_push_front(t_list **start, void *data);

#endif
