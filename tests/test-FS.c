#define __eapi_disable_init_text__
#include "../include/eapi.h"
int main(void)
{
    printf("EAPI Test Unit 1\n");
    eapi_init();

    int counter = 0;

    if (eapi_new_object ("sosiska.txt") == true) { printf("Test File creation: OK\n"); counter += 1; }
    else printf("Test File creation: FAIL\n");

    if (is_file_exists("sosiska.txt") == true) { printf("Test File check: OK\n"); counter += 1; }
    else printf("Test File check: FAIL\n");

    if (eapi_remove("sosiska.txt", FILE_TYPE) == true) { printf("Test file remove: OK\n"); counter += 1; }
    else printf ("Test File remove: FAIL\n");

    if (counter == 3) printf("\033[32mALL TESTS PASSED\033[0m\n");
    else printf ("\033[31mTESTS NOT PASSED\033[0m\n");
}