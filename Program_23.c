#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * Thread_Proc(void * p)
{
    int iNo = (int)p;
    printf("IN THREAD : iNo : %d\n",iNo);
    pthread_exit(++iNo);
}

int main()
{
    int iRet = 0;
    int iNo = 0;

    pthread_t TID;

    iRet = pthread_create(&TID,NULL,Thread_Proc,10);

    pthread_join(TID,&iNo);

    printf("Value in Main : iNo: %d\n",iNo);


    return 0;
}