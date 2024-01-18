#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc ,char *argv[])
{
    DIR * dp = NULL;
    struct dirent * entry = NULL;
    struct stat Sobj;
    char Path[30] = {'\0'};


    if(argc != 2)
    {
        printf("Insufficient arguments...\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory..\n");
        return -1;
    }

    while((entry = readdir(dp))!= NULL)
    {

        sprintf(Path,"%s/%s",argv[1],entry->d_name);
        stat(Path,&Sobj);

        if(Sobj.st_size == 0)
        {
            remove(Path);
        }
        
    }
    
    closedir(dp);

    return 0;
}