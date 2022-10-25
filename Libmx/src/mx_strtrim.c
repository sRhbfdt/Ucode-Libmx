#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    int length = mx_strlen(str);
    int count = 0;
    char *dst =  mx_strnew(length - count + 1);

    if (!str) 
        return NULL;
    
    while (mx_isspace(str[count])) {
        count++;
    }

    while (mx_isspace(str[length - 1])) {
        length--;
    }
    
    for (int i = 0; i < length - count; i++)
        dst[i] = (str+count)[i];

    return dst;
}

