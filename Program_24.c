#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int Fd = 0;
    char * Path = "/tmp/demopipe";
    char Buffer[] = "SHREE GANESH";

    Fd = mkfifo(Path,0666);
    if(Fd == -1)
    {
        printf("Unable to create pipe..\n");
        return -1;
    }

    Fd = open(Path,O_WRONLY);
    if(Fd == -1)
    {
        printf("Unable to open pipe   \n");
        return -1;
    }

    write(Fd,Buffer,sizeof(Buffer));

    unlink(Path);

    return 0;
}