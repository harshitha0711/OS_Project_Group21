#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
int sys_getppid(void)
{
    struct proc *p = myproc();
    return p->parent->pid;
}
int
sys_getprocinfo(void)
{
  procdump();
  return 0;
}
int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
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

// Set scheduling priority of a process identified by pid.
// Lower priority value = higher scheduling urgency (UNIX convention).
// Returns 0 on success, -1 if pid not found or bad arguments.
int
sys_setpriority(void)
{
  int pid, priority;

  if(argint(0, &pid) < 0 || argint(1, &priority) < 0)
    return -1;

  return setpriority(pid, priority);
}

// Send a message to the process identified by pid.
// Returns 0 on success, -1 if pid not found or bad arguments.
int
sys_sendmsg(void)
{
  int pid;
  char *msg;

  if(argint(0, &pid) < 0)
    return -1;

  if(argstr(1, &msg) < 0)
    return -1;

  return sendmsg(pid, msg);
}
int
sys_sleep2(void)
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