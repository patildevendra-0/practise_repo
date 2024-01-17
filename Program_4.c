#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc ,char *argv[])
{
   struct stat sobj;

   if(argc != 2)
   {
        printf("insufficient arguments....\n");;
        return -1;
   } 
   
   stat(argv[1],&sobj);

   printf("%d\n",sobj.st_atime);
   printf("%d\n",sobj.st_mode);

    return 0 ;
}