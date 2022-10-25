#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    char temp;   
    size_t count = 0;
    (*lineptr) = (char *) mx_realloc(*lineptr, buf_size);
    mx_memset((*lineptr), '\0', malloc_size((*lineptr)));
    
    if (buf_size < 0 || fd < 0) {
        return -2;
    }

    if (read(fd, &temp, 1)) {
        if (temp == delim)
            return count;

        (*lineptr) = (char *) mx_realloc(*lineptr, count + 1);
        (*lineptr)[count] = temp;
        count++;
    }
    else {
        return -1;
    }

    while (read(fd, &temp, 1)) {
        if (temp == delim) {
            break;
        }

        if (count >= buf_size) {
            (*lineptr) = (char *) mx_realloc(*lineptr, count + 1);
        }

        (*lineptr)[count] = temp;
        count++;
    }

    (*lineptr) = (char *) mx_realloc(*lineptr, count + 1);

    size_t free_bytes = malloc_size((*lineptr)) - count;
    mx_memset(&(*lineptr)[count], '\0', free_bytes);

    return count + 1;
}

