// accept directory name and print name of file having largest file size

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
    char namecopy[30] = {'\0'};
    int imax = 0;


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
        sprintf(name,"%s/%s",Dirname,entry -> d_name);
        printf("%s",entry -> d_name);           // file name
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            if(imax < sobj.st_size)
            {
                imax = sobj.st_size;
                strcpy(namecopy,name);
            }          
        }
    }

    printf("Name of largest file %d with size %d bytes \n",namecopy,imax);
    closedir(dp);
    
    return 0;
}