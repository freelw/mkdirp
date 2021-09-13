#include "mkdirp.h"
int main(int argc, char *argv[])
{
    if (argc < 2) {
        return -1;
    }
    return mkdirp(argv[1], 0755);
}