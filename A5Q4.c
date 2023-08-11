/// assignment A5Q4
// accept directory name from user and combine all contents of file from that directory into one file name as ALLCombine

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{
    char Dirname[20];
    DIR *dp = NULL;
    char name[30];
    struct dirent *entry = NULL;

    printf("enter the name of directory : \n");
    scanf("%s",Dirname);

    dp = opendir(Dirname);          // open directory
    if(dp == NULL)
    {
        printf("unable to open dirctory\n");
        return -1;
    }
    
    while ((entry = readdir(dp)) != NULL)
    {
        sprintf("name,%s/%s",Dirname,entry -> d_name);
        printf("%s",entry -> d_name);           // file name

    }
    closedir(dp);
    
    return 0;
}