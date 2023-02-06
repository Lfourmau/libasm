#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int _ft_strlen(char *str);
ssize_t _ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t _ft_read(int fildes, void *buf, size_t nbyte);
char *_ft_strcpy(char *dest, const char *src);
int _ft_strcmp(const char *s1, const char *s2);
char *_ft_strdup(const char *s);

char *bigStr = "zHObYpJufpveb2xIatH0wGHGwmcRSKsWgIpOXReM0IvQmuCd42ZHicOTul9hpLgJxO6d1cHE5I5aF0izSXEu6JygosCAxVDfBH1SA9vAeG4BsJuq6ow6mBcYTy3T6CwAzlMGZ2sdPvd8NtDNqlOWJvRUDfyujuV94CKt54XN2a1DIT8CwIlvABGVFMDGicwh3qP7TDVQkaXzuMsljE0ZwOsdaQAJ1ggpkbtxQXv1G2FybThSQDlr16rUM4x8aur5mXs12ki81168PP9xlgZHZ9oiX46WUvlq9bcWU4nhh76ktUUfmLRw7ZrYz43ctTYMX6deb4Q2f3hGwCWQbfBovs1nEIeQ4t6EWJOPQS2hPkmUCUzxusPUgKi7kkU3eGD2IMpeS9ebPepyeS9BQsb5QJ8xcjxu3SotzWBoU7yIKzkAbrROBx4RbEwsuwqIshnSjU8nSwzrMwYCf2F1E039Jxdc1JR84RVFTFu53OXssFh3mjXosicg";

void strlen_tests(){
	printf("\033[0;32mStrlen\033[0m\n\n");
	//STRLEN
	printf("10 chars string -> %d\n", _ft_strlen("0123456789"));
	printf("Empty string -> %d\n", _ft_strlen(""));
	printf("50 chars string -> %d\n", _ft_strlen("qwertyuiop;loikjuyhgtrfdewsaqzxswqaswedfrtghyujkiu"));
	printf("1 char string -> %d\n", _ft_strlen("a"));
	printf("500 char string -> %d\n", _ft_strlen(bigStr));
}
void write_tests(){
	printf("\n\033[0;32mWrite\033[0m\n\n");
	//WRITE
	printf(" -- return -> %zd (_ft_write)\n", _ft_write(1, "yoyoyo", 6));
	printf(" -- return -> %zd\n", write(1, "yoyoyo", 6));
	printf(" -- return -> %zd (_ft_write)\n", _ft_write(1, "", 0));
	printf(" -- return -> %zd\n", write(1, "", 0));
	printf(" -- return -> %zd (_ft_write)\n", _ft_write(1, "\n", 1));
	printf(" -- return -> %zd\n", write(1, "\n", 1));
	printf(" -- return -> %zd (_ft_write)\n", _ft_write(1, "Bonjour a tous allez l'OL", 25));
	printf(" -- return -> %zd\n", write(1, "Bonjour a tous allez l'OL", 25));
}

void read_tests(int to_read){
	int fd = open("./utils/read_test.txt", O_RDONLY);
	printf("\n\033[0;32mRead\033[0m\n\n");
	//READ
	char *buff = calloc(to_read + 1, sizeof(char));
	int ret = read(fd, buff, to_read);
	printf("[%s] -- ret = %d\n", buff, ret);
	close(fd);
	fd = open("./utils/read_test.txt", O_RDONLY);
	char *ft_buff = calloc(to_read + 1, sizeof(char));
	ret = _ft_read(fd, ft_buff, to_read);
	printf("[%s] -- ret = %d\n", ft_buff, ret);
	free(buff);
	free(ft_buff);
}

void strcpy_tests(){
	printf("\n\033[0;32mStrcpy\033[0m\n\n");
	//STRCPY
	char *dest = malloc(sizeof(char) * 9);
	strcpy(dest, "ohlalala");
	printf("%s\n", dest);
	char *my_dest = malloc(sizeof(char) * 9);
	_ft_strcpy(my_dest, "ohlalala");
	printf("%s\n", my_dest);
	char *string1 = malloc(sizeof(char) * 9);
	strcpy(string1, "");
	printf("{%s}\n", string1);
	char *string2 = malloc(sizeof(char) * 9);
	_ft_strcpy(string2, "");
	printf("{%s}\n", string2);
	char *last = malloc(sizeof(char) * 9);
	char *tmp = malloc(sizeof(char) * 9);
	last = _ft_strcpy(tmp, "bonsoirl");
	printf("%s\n", last);
	printf("%p -- %p\n", last, tmp);
	char buffer[100] = {0};
	_ft_strcpy(buffer, "");
	printf("{%s -- %p}\n", buffer, &buffer[0]);
	strcpy(buffer, "");
	printf("{%s -- %p}\n", buffer, &buffer[0]);
	free(dest);
	free(my_dest);
	free(string1);
	free(string2);
	free(last);
}

void strcmp_tests(){
	printf("\n\033[0;32mStrcmp\033[0m\n\n");
	//STRCMP
	char str1[] = "La string 8";
	char str2[] = "La string 1";
	printf("real strcmp -> %d\n", strcmp(str1, str2));
	printf("My strcmp -> %d\n", _ft_strcmp(str1, str2));
	char str3[] = "La string 8";
	char str4[] = "La string 8";	
	printf("real strcmp -> %d\n", strcmp(str3, str4));
	printf("My strcmp -> %d\n", _ft_strcmp(str3, str4));
	char str5[] = "La string 8rer";
	char str6[] = "La string 8";	
	printf("real strcmp -> %d\n", strcmp(str5, str6));
	printf("My strcmp -> %d\n", _ft_strcmp(str5, str6));
	char str7[] = "La string 8rer";
	char str8[] = "";	
	printf("real strcmp -> %d\n", strcmp(str7, str8));
	printf("My strcmp -> %d\n", _ft_strcmp(str7, str8));
	char str9[] = "La string 8rer";
	char strX[] = "La string 8rer oleole";	
	printf("real strcmp -> %d\n", strcmp(str9, strX));
	printf("My strcmp -> %d\n", _ft_strcmp(str9, strX));
}
void strdup_tests(){
	printf("\n\033[0;32mStrdup\033[0m\n\n");
	//STRDUP
	char string[] = "Bonjour, dupplique moi";
	char *newStr = strdup(string);
	printf("%s\n", newStr);
	free(newStr);
	newStr = _ft_strdup(string);
	printf("%s\n", newStr);
	free(newStr);
	newStr = strdup("");
	printf("[%s]\n", newStr);
	free(newStr);
	newStr = _ft_strdup("");
	printf("[%s]\n", newStr);
	free(newStr);
}

int main(){
	strlen_tests();
	write_tests();
	read_tests(10);
	read_tests(50);
	read_tests(85);
	strcmp_tests();
	strcpy_tests();
	strdup_tests();
	return 0;
}