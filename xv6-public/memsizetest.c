#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    //printf(1, "The processs is using %d\n",myproc()->sz);
    printf(1, "The processs is using %d\n",(uint)memsize());
    uint *x = (uint*) malloc(sizeof(uint));
    printf(1, "Allocating more memory\n");
    printf(1, "The processs is using %d\n",memsize());
    free(x);
    printf(1, "Freeing memory\n");
    printf(1, "The processs is using %d\n",memsize());
    exit();
}
