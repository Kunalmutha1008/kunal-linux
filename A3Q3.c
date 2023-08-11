// A3Q3.c
// accept two directory name from user and move all files from source dirctory into destination directory

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
    char oldname[50];
    char newname[50];

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("unable to open directory \n");
        return -1;
    }
    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(oldname,"%s/%s",argv[1],entry->d_name);
        sprintf(newname,"%s/%s",argv[1],entry->d_name);

        rename(oldname,newname);
    }
    
    closedir(dp);
    return 0;

}