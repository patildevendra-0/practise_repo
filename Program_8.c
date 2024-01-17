#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

#define BLOCKSIZE 20

int main(int argc ,char *argv[])
{
    int Fd = 0;
    char Buffer[BLOCKSIZE] = {'\0'};

    if(argc != 2)
    {
        printf("Insuffucient Arguments...\n");
        return -1;
    }

    Fd = open(argv[1],O_WRONLY);

    if(Fd==-1)
    {
        printf("Unable to open file...\n");
        return -1;
    }

    printf("Enter the data : \n");
    scanf("%[^'\n']s",Buffer);

    write(Fd,Buffer,strlen(Buffer));



    return 0;
}



