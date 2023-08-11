// copy and write data of file name and size into another file
// A4Q4 
// accept directory name and copy 10 bytes from all regular files into newly created files 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#pragma pack(1)
struct fileinfo
{
    char filename[20];
    int filesize;
};

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    char name[30];
    struct dirent *entry = NULL;
    struct stat sobj;
    char namecopy[30] = {'\0'};
    int imax = 0;
    struct fileinfo fobj;           //object of file info
    int fd = 0;

    printf("enter the name of directory : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);          // open directory
    if(dp == NULL)
    {
        printf("unable to open dirctory\n");
        return -1;
    }
    fd = creat("filecombine.txt",0777);
    
    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",DirName,entry -> d_name);
        printf("%s",entry -> d_name);           // file name
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            fobj.filesize = sobj.st_size;
            strcpy(fobj.filename,entry -> d_name);          // copy data from 1 file into new file
            write(fd,&fobj,sizeof(fobj));           // write copied data
            printf("%s\n",entry -> d_name);       
        }
    }

    closedir(dp);
    
    return 0;
}