#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc ,char *argv[])
{

    int fd = 0;
    char *BUFFER = NULL;
    int iRet = 0;

    if(argc!=2)
    {
        printf("insufficient arguments....\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);

    BUFFER = (char *)malloc(sizeof(argv[1]));


    while(iRet = read(fd,BUFFER,sizeof(BUFFER))!= 0)
    {
        write(1,BUFFER,sizeof(BUFFER));
    }

    return 0;
}