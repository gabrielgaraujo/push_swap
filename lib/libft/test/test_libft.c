#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	// Test mandatory functions
	printf("=== TESTING MANDATORY FUNCTIONS ===\n");
	char *str = ft_strjoin("Hello, ", "World!");
	printf("ft_strjoin result: %s\n", str);
	printf("ft_strlen result: %zu\n", ft_strlen(str));
	free(str);
	
	// Test ft_printf
	printf("\n=== TESTING FT_PRINTF ===\n");
	int printed = ft_printf("ft_printf test: %s %d %c %x %p %%\n", 
							"string", 42, 'A', 255, &str);
	printf("Characters printed: %d\n", printed);
	
	// Test bonus functions (linked lists)
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
	ft_lstclear(&list, NULL);
	
	// Test get_next_line
	printf("\n=== TESTING GET_NEXT_LINE ===\n");
	
	// Create a test file
	int fd = open("test/test_file.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd != -1)
	{
		write(fd, "Line 1\nLine 2\nLine 3\n", 20);
		close(fd);
		
		// Read the file with get_next_line
		fd = open("test/test_file.txt", O_RDONLY);
		if (fd != -1)
		{
			char *line;
			int line_num = 1;
			while ((line = get_next_line(fd)) != NULL)
			{
				printf("get_next_line %d: %s", line_num++, line);
				free(line);
			}
			close(fd);
		}
	}
	
	printf("\n=== ALL TESTS COMPLETED ===\n");
	return (0);
} 