#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
char *bigStr = "zHObYpJufpveb2xIatH0wGHGwmcRSKsWgIpOXReM0IvQmuCd42ZHicOTul9hpLgJxO6d1cHE5I5aF0izSXEu6JygosCAxVDfBH1SA9vAeG4BsJuq6ow6mBcYTy3T6CwAzlMGZ2sdPvd8NtDNqlOWJvRUDfyujuV94CKt54XN2a1DIT8CwIlvABGVFMDGicwh3qP7TDVQkaXzuMsljE0ZwOsdaQAJ1ggpkbtxQXv1G2FybThSQDlr16rUM4x8aur5mXs12ki81168PP9xlgZHZ9oiX46WUvlq9bcWU4nhh76ktUUfmLRw7ZrYz43ctTYMX6deb4Q2f3hGwCWQbfBovs1nEIeQ4t6EWJOPQS2hPkmUCUzxusPUgKi7kkU3eGD2IMpeS9ebPepyeS9BQsb5QJ8xcjxu3SotzWBoU7yIKzkAbrROBx4RbEwsuwqIshnSjU8nSwzrMwYCf2F1E039Jxdc1JR84RVFTFu53OXssFh3mjXosicg";

int main(){
	printf("10 chars string -> %d\n", ft_strlen("0123456789"));
	printf("Empty string -> %d\n", ft_strlen(""));
	printf("50 chars string -> %d\n", ft_strlen("qwertyuiop;loikjuyhgtrfdewsaqzxswqaswedfrtghyujkiu"));
	printf("1 char string -> %d\n", ft_strlen("a"));
	printf("500 char string -> %d\n", ft_strlen(bigStr));

	printf(" -- return -> %zd\n", ft_write(1, "yoyoyo", 6));
	printf(" -- return -> %zd\n", write(1, "yoyoyo", 6));
	printf(" -- return -> %zd\n", ft_write(1, "", 0));
	printf(" -- return -> %zd\n", write(1, "", 0));
	printf(" -- return -> %zd\n", ft_write(1, "\n", 1));
	printf(" -- return -> %zd\n", write(1, "\n", 1));
	printf(" -- return -> %zd\n", ft_write(1, "Bonjour a tous allez l'OL", 25));
	printf(" -- return -> %zd\n", write(1, "Bonjour a tous allez l'OL", 25));

	char buff[50];
	read(1, buff, 49);
	printf("%s", buff);
	char ft_buff[50];
	ft_read(1, ft_buff, 49);
	printf("%s", ft_buff);
	return 0;
}