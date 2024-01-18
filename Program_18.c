#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int iRet = 0;

    iRet = fork();

    if(iRet == 0)
    {
        printf("Child is Ruuning");
        execl("./test",NULL,NULL);

    }
    else
    {
        printf("Parent running \n");
    }


    return 0;
}