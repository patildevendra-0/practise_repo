#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE 512

int main(int argc ,char *argv[])
{

    int Fd = 0;
    char Buffer[BLOCKSIZE] = {'\0'};
    int iRet = 0;
    int Fd_2 = 0;

    if(argc!=2)
    {
        printf("Insufficient arguments....\n");
        return -1;
    }

    Fd = open(argv[1],O_RDONLY);
    if(Fd == -1)
    {
        printf("Unable to open file...\n");
        return -1;
    }


    Fd_2 = creat("test.txt",0777);
    if(Fd_2==-1)
    {
        printf("Unable to create file ..\n");
        return -1;
    }

    while (iRet = read(Fd,Buffer,sizeof(Buffer)))
    {
        write(Fd_2,Buffer,sizeof(Buffer));
        memset(Buffer,0,sizeof(Buffer));
    }
    


    return 0 ;

}