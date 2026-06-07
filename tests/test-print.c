#define __eapi_disable_init_text__
#include "../include/eapi.h"
int main(void)
{
    printf("EAPI Test Unit 2\n");
    eapi_init();

    for (int i = 0; i < EAPI_COLOR_COUNT; i++)
    {
        eapi_printf(i, "test\n");
    }
}