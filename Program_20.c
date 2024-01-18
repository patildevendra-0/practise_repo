#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{

    int iRet = 0;

    iRet = getpriority(PRIO_PROCESS,NULL);
    iRet = nice(10);

    printf("%d\n",iRet);


    return 0;
}