#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
    int pid = fork();

    if(pid == 0){
        // child process
        while(1){
            printf(1, "Child running...\n");
            sleep(20);
        }
    } else {
        sleep(50);

        kill2(pid, 2); // pause
        sleep(50);

        kill2(pid, 3); // resume
        sleep(50);

        kill2(pid, 1); // kill
    }

    wait();
    exit();
}