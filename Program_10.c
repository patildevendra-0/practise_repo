#include <stdio.h>
#include <dirent.h>
#include<string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    char File_Name[30];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;

    if (argc != 2)
    {
        printf("INSUFFICIENT ARGUMENTS...\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if (dp == NULL)
    {
        printf("UNABLE TO OPEN DIRECTORY...\n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(File_Name, "%s/%s", argv[1], entry->d_name);
        stat(File_Name, &sobj);

        if((strcmp(entry->d_name,".")==0 ||(strcmp(entry->d_name,"..")==0 )))
        {
            continue;
        }

        if (S_ISDIR(sobj.st_mode))
        {   
            

            DIR *sub_dp = opendir(File_Name);
            if (sub_dp == NULL)
            {
                printf("UNABLE TO OPEN SUBDIRECTORY...\n");
                return -1;
            }

            while ((entry = readdir(sub_dp)) != NULL)
            {
                printf("%s\n", entry->d_name);
            }

            closedir(sub_dp);
        }
        else
        {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dp);
    return 0;
}
