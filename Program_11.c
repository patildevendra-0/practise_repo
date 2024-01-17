#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>

int main()
{

    char Dir_Name[30] = {'\0'};
    char File_Name[30] = {'\0'};

    DIR * dp = NULL;
    struct dirent * entry = NULL;

    printf("Enter the directory name : \n");
    scanf("%s",Dir_Name);

    printf("Enter the file name that you want to check : \n");
    scanf("%s",File_Name);

    dp = opendir(Dir_Name);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp))!= NULL)
    {
        if(strcmp(entry->d_name,File_Name)==0)
        {
            printf("File is Present..");
            break;
        }

    }

    if(entry == NULL)
    {
        printf("file is Not Present...\n");
        return -1;
    }
    


    return 0;
}