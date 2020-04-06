#include "types.h"
#include "stat.h"
#include "user.h"
//#include "proc.h"

struct perf performance;
int status,pid;

void procTester(int priority,int cfs_priority){
    int i = 1000000;
    int dummy = 0;
    
    if((set_ps_priority(priority)) < 0){
        printf(2,"error in set_ps_priority");
        exit(1);
    }
    if((set_cfs_priority(cfs_priority)) < 0){
        printf(2,"error in set_cfs_priority");
        exit(1);
    }
    
    while(i--)
        dummy+=i;
        
    sleep(1);

    if(proc_info(&performance) < 0) {
        exit(1);
    }else{
        printf(1, "%d\t%d\t%d\t%d\t%d\n",getpid(),
            performance.ps_priority,
            performance.stime,
            performance.retime,
            performance.rtime);
    }
}

int main (int argc, char **argv){
    
    int priorityArr[] = {10,5,1};
    int cfs_priorityArr[] = {3,2,1};

    printf(1,"PID\tPS_PRIORITY\tSTIME\tRETIME\tRTIME\n");

    for (int kid = 0; kid < 3; kid++) {
        //Child process
        if ((pid = fork()) == 0){
            procTester(priorityArr[kid],cfs_priorityArr[kid]);
            exit(0);
        }
    }
    for (int kid = 0; kid < 3; ++kid) {
        wait(&status); // kids could be ready in any order
    }  
        
    exit(0);
}