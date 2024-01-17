#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{

    char Path[30] = {'\0'};
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;

    dp = opendir(argv[1]);
    if (dp == NULL)
    {
        printf("Unable to open directory...\n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(Path, "%s/%s", argv[1], entry->d_name);
        stat(Path, &sobj);

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        if (S_ISDIR(sobj.st_mode))
        {
            DIR * sub_dp = NULL;

            sub_dp = opendir(Path);

            while ((entry = readdir(sub_dp)) != NULL)
            {
                printf("%s directory File:%s\n ",Path,entry->d_name);
            }


            closedir(sub_dp);
        }
        else
        {
            printf("%s directory File:%s\n ",Path,entry->d_name);
        }
    }
    closedir(dp);
    return 0;
}
