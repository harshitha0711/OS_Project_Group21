#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
    int pid = fork();

    if(pid < 0){
        printf(1, "fork failed\n");
        exit();
    }

    if(pid == 0){
        // Child process: set high priority (low value)
        setpriority(getpid(), 1);
        int i;
        for(i = 0; i < 5; i++){
            printf(1, "Child running (priority=1)\n");
        }
    } else {
        // Parent process: set low priority (high value)
        setpriority(getpid(), 20);
        int i;
        for(i = 0; i < 5; i++){
            printf(1, "Parent running (priority=20)\n");
        }
        wait();
    }

    exit();
}
