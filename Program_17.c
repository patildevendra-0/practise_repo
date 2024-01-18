#include<stdio.h>
#include<unistd.h>

int main()
{
    int iRet = 0;

    iRet = fork();
    if(iRet == 0)
    {
        printf("CHILD IS RUNNING \n");
        printf("%d\n",getpid());
        printf("%d\n",getppid());
    }
    else
    {
        printf("Parent Running \n");
        printf("%d\n",getpid());
        printf("%d\n",iRet);
    }



    return 0;
}