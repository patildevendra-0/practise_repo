
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc ,char *argv[])
{
    if(argc != 2)
    {
        printf("Insufficient arguments....\n");
        return -1;
    }

    int DP = 0;

    DP = mkdir(argv[1]);
    if(DP == -1)
    {
        printf("Unable to create directory...\n");
        return -1;
    }
    else
    {
        printf("Success ...\n");
    }



    return 0;
}