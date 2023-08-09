// ls -i command to display files in directory

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
int main(int argc,char*argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;

    if(argc != 2)
    {
        printf("insufficient arguments \n");
        return -1;
    }
    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("unable to open directory \n");
        return -1;
    }

    printf("-------------------------------------------------------------------------\n");
    printf("entries from directory files are : \n");
    printf("-------------------------------------------------------------------------\n");
    printf("file name  \n");
    while ((entry = readdir(dp)) != NULL)
    {
        printf("%s  :   \n",entry-> d_name);
    }
    printf("-------------------------------------------------------------------------\n");
    closedir(dp);
    return 0;
}