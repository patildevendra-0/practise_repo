#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * Thread_Proc(void *p)
{
    printf("SHREE GANESH.....\n");
    pthread_exit(NULL);
}

int main()
{
    int iRet = 0;

    pthread_t TID;

    iRet = pthread_create(&TID,NULL,Thread_Proc,NULL);
    if(iRet != 0)
    {
        printf("Unable to create thread...\n");
        return -1;
    }

    pthread_join(TID,NULL);


    return 0;
}