#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc ,char *argv[])
{
    int iRet = 0;

    iRet = fork();

    if(iRet == 0)
    {
        printf("Child is running..\n");
        execl("./test","10",NULL);
    }
    else
    {
        printf("Parent is running\n");
    }

    return 0;
}