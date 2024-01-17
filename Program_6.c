#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#define BLOCKSIZE 512

int main(int argc ,char *argv[])
{

    int Fd = 0;
    char Buffer[BLOCKSIZE] = {'\0'};
    int iRet = 0;

    if(argc != 2)
    {
        printf("Insufficient Arguments....\n");
        return -1;
    }

    Fd = open(argv[1],O_RDONLY);
    if(Fd == -1)
    {
        printf("Unable to Open file ....\n");
        return -1;
    }

    while(iRet = read(Fd,Buffer,sizeof(Buffer)))
    {
        write(1,Buffer,sizeof(Buffer));
        memset(Buffer,0,sizeof(Buffer));
    }
    



    return 0;
}