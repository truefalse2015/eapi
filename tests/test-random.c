#define __eapi_disable_init_text__
#include "../include/eapi.h"

int main(void) {
    printf("EAPI Test Unit 3\n");
    eapi_init();
    int x = 10;
    int g = 84;
    int counter = 0;
    eapi_swap(x, g);
    if (x == 84 and g == 10) { printf("EAPI SWAP: OK\n"); counter += 1; }
    else printf ("EAPI SWAP: FAIL\n");

    int min_val = 5;
    int max_val = 15;
    bool ok = true;

    eapi_rand_init();

    for (int i = 0; i < 10000; i++)
    {
        int r = eapi_rand_range(min_val, max_val);
        if (r < min_val || r > max_val)
        {
            ok = false;
            break;
        }
    }

    if (ok) { printf("EAPI TEST RANDOM RANGE: OK\n"); counter += 1; }
    else printf("EAPI TEST RANDOM RANGE: FAIL\n");

    char *str1 = eapi_gen_random_string_element(16);
    char *str2 = eapi_gen_random_string_element(16);

    if (str1 != NULL and str2 != NULL and strcmp(str1, str2) != 0)
    {
        printf ("EAPI TEST RANDOM STRINGS: OK\n");
        counter += 1;
    }
    else printf ("EAPI TEST RANDOM STRINGS: FAIL\n");
    
    free(str1);
    free(str2);

    if (counter == 3) eapi_printf (EAPI_GREEN, "ALL TESTS PASSED\n");
    else eapi_printf(EAPI_RED, "TESTS NOT PASSED\n");
    return 0;
}