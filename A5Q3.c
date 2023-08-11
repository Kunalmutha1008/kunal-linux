/// assignment A5Q3
// accept dirctory name and write info of all regular file and then read contents of files

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
    struct stat sobj;

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
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            printf("file name : %s file size : %ld \n",name,sobj.st_size);           // size of file
        }
    }
    closedir(dp);
    
    return 0;
}