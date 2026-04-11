#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
    printf(1, "Sleeping for 100 ticks...\n");
    sleep2(100);
    printf(1, "Woke up!\n");
    exit();
}