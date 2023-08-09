// accept file name and print all information about file
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
int main(int argc,char *argv[])
{
    struct stat sobj;

    if(argc == -1)
    {
        printf("insufficient arguments \n");
    }
    stat(argv[1],&sobj);

    printf("file name %s\n",argv[1]);
    printf("file size is : %ld \n",sobj.st_size);
    printf("number of links : %ld\n",sobj.st_nlink);
    printf("inode number : %ld\n",sobj.st_ino);
    printf("file system number : %ld \n",sobj.st_dev);
    printf(" number of blocks : %ld \n",sobj.st_blocks);
    return 0;
}