#include<stdio.h>
#include<pthread.h>

void * Print_1_100(void * P)
{
    int iCnt = 0;

    for(iCnt=0;iCnt<=100;iCnt++)
    {
        printf("%d\n",iCnt);
    }
    pthread_exit(NULL);
}

void * Print_A_Z(void * P)
{
    int iCnt = 0;
    char data = 'A';

    for(iCnt=1;iCnt<=26;iCnt++)
    {
        printf("%c\n",data);
        data++;
    }
    pthread_exit(NULL);
}

int main()
{
    int iRet_1 = 0;
    int iRet_2 = 0;

    pthread_t TID_1;
    pthread_t TID_2;

    iRet_1 = pthread_create(&TID_1,NULL,Print_1_100,NULL);
    iRet_2 = pthread_create(&TID_2,NULL,Print_A_Z,NULL);

    pthread_join(TID_1,NULL);
    pthread_join(TID_2,NULL);


    return 0;
}