#include "mkdirp.h"
#include <errno.h>
#include <sys/stat.h>
#include <stdio.h>

#define BUFFER_LEN 1024
int mkdirp(const char *pathname, mode_t mode)
{
    char buffer[BUFFER_LEN];
    snprintf(buffer, BUFFER_LEN, "%s", pathname);
    size_t len = strnlen(buffer, BUFFER_LEN);
    if (buffer[len - 1] == '/') {
        buffer[len - 1] = 0;
    }
    char *p = NULL;
    for (p = buffer + 1; *p; p++){
        if (*p == '/') {
            *p = 0;
            if (0 != mkdir(buffer, mode)) {
                int is_exist_dir = 0;
                if (errno == EEXIST) {
                    struct stat _s;
                    stat(buffer, &_s);
                    if (S_ISDIR(_s.st_mode)) {
                        is_exist_dir = 1;
                    } else if (S_ISLNK(_s.st_mode)) {
                        char buffer_link_value[BUFFER_LEN];
                        struct stat _s1;
                        readlink(buffer, buffer_link_value, BUFFER_LEN);
                        stat(buffer_link_value, &_s1);
                        if (S_ISDIR(_s1.st_mode)) {
                            is_exist_dir = 1;
                        }
                    }
                }
                if (!is_exist_dir) {
                    return -1;
                }
            }
            *p = '/';
        }
    }
    return mkdir(buffer, mode);
}