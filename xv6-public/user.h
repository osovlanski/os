#include "perf.h"

struct stat;
struct rtcdate;
// struct perf {
//   int ps_priority;
//   int stime;
//   int retime;
//   int rtime;
// };

// system calls
int set_cfs_priority(int priority);
int proc_info(struct perf *);
int fork(void);
void exit(int status) __attribute__((noreturn));
int wait(int *status);
int pipe(int*);
int write(int, const void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(const char*, int);
int mknod(const char*, short, short);
int unlink(const char*);
int fstat(int fd, struct stat*);
int link(const char*, const char*);
int mkdir(const char*);
int chdir(const char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);
int memsize(void);
int policy(int);
int set_ps_priority(int);

// ulib.c
int stat(const char*, struct stat*);
char* strcpy(char*, const char*);
void *memmove(void*, const void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void printf(int, const char*, ...);
char* gets(char*, int max);
uint strlen(const char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);
