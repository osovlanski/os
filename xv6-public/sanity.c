#include "types.h"
#include "stat.h"
#include "user.h"
//#include "proc.h"

int main (int argc, char **argv){
    printf(1, "Hello World XV6\n");
    struct perf *performance = null;
    int status=0;
    
    printf(1, "PID\tPS_PRIORITY\tSTIME\tRETIME\tRTIME\n");
    
    if (fork() == 0){
        if(fork() == 0){
            if(fork() == 0){

                //first child
                int i = 1000000;
                int dummy = 0;
                while(i--)
                    dummy+=i;
                
                
                    if((set_ps_priority(10)) < 0){
                        printf(2,"error in set_ps_priority");
                        exit(1);
                    }
                    if((set_cfs_priority(3)) < 0){
                        printf(2,"error in set_cfs_priority");
                        exit(1);
                    }

                if(proc_info(performance) < 0) {
                    exit(1);
                }else{
                    printf(1, "%d\t%d\t%D\t%d\t%d\n",getpid(),10,performance->stime,performance->retime,performance->rtime );
                }
            }else{ //second child
            wait(&status);
            int i = 1000000;
            int dummy = 0;
            while(i--)
                dummy+=i;
            }
        }else{ //third child
            wait(&status);
            int i = 1000000;
            int dummy = 0;
            while(i--)
                dummy+=i;
        }

    }else{ //father
        wait(&status);
        int i = 1000000;
        int dummy = 0;
        while(i--)
        dummy+=i;


    }

    
    exit(0);
}