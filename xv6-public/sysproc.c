#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  int status = 0;
  if(argint(0, &status) < 0)
    return -1;

  exit(status);
  return 0;
}

int
sys_wait(void)
{
  int adr;

  if(argint(0, &adr) < 0)
    return -1;

  int *status = null;
  status = (int*)adr;
  int pid =  wait(status);
  
  return pid;
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int 
sys_memsize(void)
{
  return myproc()->sz;
}

int 
sys_policy(void){
  int policy;
  
  if(argint(0, &policy) < 0)
    return -1;

  sched_type = policy;
  return sched_type;
}

int 
sys_set_ps_priority(void){
  int priority;
  
  if(argint(0, &priority) < 0)
    return -1;

  myproc()->perf.ps_priority = priority;
  
  return priority;
}

int
sys_set_cfs_priority(void)
{
  int priority;
  
  if(argint(0, &priority) < 0)
    return 1;

  switch (priority)
  {
  case 1: //high
    myproc()->cfs_priority = 0.75;
    return 0;
  
  case 2: //normal
    myproc()->cfs_priority = 1;
    return 0;
  
  case 3: //low
    myproc()->cfs_priority = 1.25;
    return 0;
  

  default:
  
    return 1;
  }

  return 1;

}

int
sys_proc_info(void)
{

  int adr;

  if(argint(0, &adr) < 0)
    return -1;

  struct perf* p = (struct perf *)adr;
  *p = myproc()->perf ;
  
  return 0;
}
