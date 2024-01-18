#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int iRet = 0;
    int Fd = 0;

    char * Path = "/home/devendra/Desktop/practise_repo/Demo.txt";
    char Buffer[] = "Shree Ganesh \n";

    iRet = daemon(0,0);
    if(iRet == -1)
    {
        printf("Unable to create daemon process...\n");
        return -1;
    }

    Fd = open(Path,O_RDWR);
    if(Fd == -1)
    {
        printf("Unable to open file..\n");
        return -1;
    }

    int iCnt = 0 ;

    while(iCnt != 10)
    {
        write(Fd,Buffer,sizeof(Buffer));
        sleep(1);
        iCnt++;
    }

    printf("Daemon stop...\n");
    
    return 0;
}