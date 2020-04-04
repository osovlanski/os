#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    // //printf(1, "The processs is using %d\n",myproc()->sz);
    // printf(1, "The processs is using %d\n",(uint)memsize());
    // uint *x = (uint*) malloc(sizeof(uint));
    // printf(1, "Allocating more memory\n");
    // printf(1, "The processs is using %d\n",memsize());
    // free(x);
    // printf(1, "Freeing memory\n");
    // printf(1, "The processs is using %d\n",memsize());
    // exit(2);

    int status;
    printf(1,"memsizetest: status adr: %d\n",&status);

    if (fork() == 0)
        exit(5);
    else{
        wait(&status);
        printf(1,"memsizetest: after wait status value is %d\n",status);
    }if (status == 5)
        printf(1, "memsizetest: Success!\n");
    else{
        printf(1, "memsizetest: Fail :(\n");
        printf(1, "memsizetest: status:%d\n",status);
    }
    printf(1, "memsizetest: Child exit status is %d\n", status);
    exit(0);
}
