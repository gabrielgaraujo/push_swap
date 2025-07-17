#include "libft.h"
#include <stdio.h>

void simple_del(void *content)
{
	// Since our test uses string literals, we don't need to free them
	// Just a placeholder function
	(void)content;
}

int main(void)
{
	printf("=== TESTING MANDATORY FUNCTIONS ===\n");
	char *str = ft_strjoin("Hello, ", "World!");
	printf("ft_strjoin result: %s\n", str);
	printf("ft_strlen result: %zu\n", ft_strlen(str));
	free(str);
	
	printf("\n=== TESTING FT_PRINTF ===\n");
	int printed = ft_printf("ft_printf test: %s %d %c %x %%\n", 
							"string", 42, 'A', 255);
	printf("Characters printed: %d\n", printed);
	
	printf("\n=== TESTING BONUS FUNCTIONS (LISTS) ===\n");
	t_list *list = ft_lstnew("First");
	ft_lstadd_back(&list, ft_lstnew("Second"));
	ft_lstadd_back(&list, ft_lstnew("Third"));
	
	printf("List size: %d\n", ft_lstsize(list));
	t_list *current = list;
	while (current)
	{
		printf("List content: %s\n", (char *)current->content);
		current = current->next;
	}
	ft_lstclear(&list, simple_del);
	
	printf("\n=== BASIC TESTS COMPLETED SUCCESSFULLY ===\n");
	return (0);
} 