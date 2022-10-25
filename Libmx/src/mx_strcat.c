#include "../inc/libmx.h"

int mx_strlen(const char *s);

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    char* ptr = s1 + mx_strlen(s1);
    while (*s2 != '\0')
		*ptr++ = *s2++;
	*ptr = '\0';

	return ptr;
}
