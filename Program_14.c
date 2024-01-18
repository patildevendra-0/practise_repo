#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024

int main()
{
    char File_Name_1[30] = {'\0'};
    char File_Name_2[30] = {'\0'};

    int Fd_1 = 0;
    int Fd_2 = 0;
    int iRet = 0;

    char Buffer_1[BLOCKSIZE];
    char Buffer_2[BLOCKSIZE];

    struct stat Sobj_1;
    struct stat Sobj_2;


    printf("ENTER THE FILE NAME THAT YOU WANT TO CHECK : \n");
    scanf("%s",File_Name_1);

    printf("ENTER THE FILE NAME THAT YOU WANT TO CHECK : \n");
    scanf("%s",File_Name_2);

    Fd_1 = open(File_Name_1,O_RDONLY);
    Fd_2 = open(File_Name_2,O_RDONLY);

    if(Fd_1 == -1 || Fd_2 == -1 )
    {
        printf("Unable to open files.....\n");
        return -1;
    }

    fstat(Fd_1,&Sobj_1);
    fstat(Fd_2,&Sobj_2);

    if(Sobj_1.st_size != Sobj_2.st_size)
    {
        printf("Size of both files different...\n");
        return -1;
    }

    while((iRet = read(Fd_1,Buffer_1,sizeof(Buffer_1)))!= 0)
    {
        iRet = read(Fd_2,Buffer_2,sizeof(Buffer_2));

        if(memcmp(Buffer_1,Buffer_2,iRet)!=0)
        {
            break;
        }
    }
    
    if(iRet == 0)
    {
        printf("BOTH FILES ARE IDENTICAL...\n");
    }
    else
    {
        printf("Both are different..\n");
    }

    close(Fd_1);
    close(Fd_2);



    return 0;
}