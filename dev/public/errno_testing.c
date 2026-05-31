#include <stdio.h>
#include <errno.h>

int main(void) {
    printf("EINVAL = %d\n", EINVAL);
    printf("ENAMETOOLONG = %d\n", ENAMETOOLONG);
    return 0;
}