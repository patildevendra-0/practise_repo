#include<stdio.h>
#include<fcntl.h>

int main(int argc ,char *argv[])
{

    int Fd = 0;

    if(argc != 2)
    {
        perror("INSUFFICIENT ARGUMENTS....\n");
        return -1;
    }

    Fd = open(argv[1],O_RDONLY);

    if(Fd == -1)
    {
        printf("UNABLE TO OPEN FILE ....\n");
        return -1;
    }
    else
    {
        printf("FILE IS SUCCESSFULLY OPEN .....\n");
    }

    return 0;
}