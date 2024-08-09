#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{

    
    int p[2];
    
    char buf[4];

    pipe(p);

    int pid = fork();
    if(pid == 0){
        
        read(p[0], buf, sizeof(buf));
        printf("%d: received %s\n", getpid(), buf);
        write(p[1], "pong", 4);
        close(p[0]);
        close(p[1]);

    }
    else {

        
        write(p[1], "ping", 4);
        read(p[0], buf, sizeof(buf));
        printf("%d: received %s\n", getpid(),buf);
        close(p[0]);
        close(p[1]);
    }

    return 0;
}
