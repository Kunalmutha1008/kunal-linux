// A3Q2
// accept directory name and file name from user and check wheather file is present or not
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc , char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("unable to open the directory \n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        if(strcmp(argv[2],entry -> d_name) == 0)
        {
            printf("file is present in directory \n");
            break;
        }
    }
    if(entry == NULL)
    {
        printf("there is no such file \n");
        return -1;
    }
    closedir(dp);
    
    return 0;

}