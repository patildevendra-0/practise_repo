#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>


int main(int argc ,char *argv[])
{
    
    if(argc != 2)
    {
        printf("Insufficient argument...\n");
        return -1;
    }

    char Path[30] = {'\0'};
    struct stat sobj;
    DIR * dp = NULL;
    struct dirent * entry = NULL;
    int iRet = 0;

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory...\n");
        return -1;
    }

    while ((entry = readdir(dp))!= NULL)
    {
        sprintf(Path,"%s/%s",argv[1],entry->d_name);
        stat(Path,&sobj);

        if(S_ISREG(sobj.st_mode) && sobj.st_size == 0)
        {
            iRet = remove(Path);
            if(iRet == 0)
            {
                printf("SUCCESS..\n");
            }
        }
    }
    closedir(dp);

    return 0;
}