#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc ,char *argv[])
{

    int Fd = 0;
    int Mode = 0;

    if(argc != 3)
    {
        printf("Insufficient arguments....\n");
        return -1;
    }
    
    if(strcmp(argv[2],"read")== 0)
    {
        Mode = O_RDONLY;
    }
    else if( strcmp(argv[2],"write")==0)
    {
        Mode = O_WRONLY;
    }
    else
    {
        Mode = O_RDONLY;
    }

    Fd = open(argv[1],Mode);

    if(Fd == -1)
    {
        printf("Unable to open file...\n");
        return -1;
    }
    else
    {
        printf("Success :  File Open in Mode : %d \n",Mode);
    }


    return 0;
}