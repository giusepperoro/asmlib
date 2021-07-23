#include "libasm_bonus.h"

int	main()
{
	t_list	list;
	t_list	list_next;
	t_list	list_last;

	list.data = strdup("Hello");
	list.next = &list_next;
	list_next.data = strdup("pipl");
	list_next.next = &list_last;
	list_last.data = strdup("that");
	list_next.next = &list_last;
	list_last.data = strdup("me");
	list_last.next = NULL;
	
	printf("\033[22;34mft_list_size\033[0m");
	printf("list content:\n");
	printf_list(&list);
	printf("%d (from first 4)\n", ft_list_size(&list));
	printf("%d (from second 3)\n", ft_list_size(&list_next));
	printf("%d (NULL 0)\n", ft_list_size(NULL));
	printf("%d (from last 2)\n", ft_list_size(&list_last));
	printf("%d (from zero 1)\n", ft_list_size(&list_last));
	free(list_next.data);
	free(list_last.data);

	printf("\033[22;34mft_list_push_front\033[0m");
	t_list	*push = &list;
	ft_list_push_front(&push, strdup("Hello"));
	printf("\nadded: `%s` (next: %p)\n", push->data, push->next);
	printf("new list size: %d (4)\n", ft_list_size(push));
	free(push);
	free(list.data);
	free(push->data);


	push = NULL;
	ft_list_push_front(&push, strdup("Hello world"));
	printf("added: `%s` (s%p : n%p)\n", push->data, push, push->next);
	ft_list_push_front(&push, NULL);
	printf("added: `%s` (s%p : n%p)\n", push->data, push, push->next);
	free(push->next);
	push->next = NULL;
	ft_list_push_front(&push, strdup("Bye boy"));
	printf("added: `%s` (s%p : n%p)\n", push->data, push, push->next);
	ft_lstclear(&push);

	return (0);
}
