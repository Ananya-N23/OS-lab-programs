#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t parent=getpid();
    pid_t pid=fork();
    if(pid==-1){
        printf("fork failed\n");
    }
    else if(pid>0){
        int status;
        printf("Parent id:%d\n will be waiting for childto complete\n",getpid());
        waitpid(pid,&status,0);
    }
    else{
        printf("child process1 id:%d\n",(int)pid);
        printf("parent process1 id:%d\n",getppid());
        execl("/bin/ls","/bin/ls","-r","-t","-l",(char*)0);
        _exit(EXIT_FAILURE);
    }
}
