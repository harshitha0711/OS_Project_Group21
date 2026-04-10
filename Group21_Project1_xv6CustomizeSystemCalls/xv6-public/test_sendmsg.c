#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
    int pid = fork();

    if(pid == 0){
        // child
        sleep(50); // wait for message
    } else {
        // parent
        sendmsg(pid, "Hello from parent!");
    }

    wait();
    exit();
}
