// accept file name which contain data of all files. if file is not there then create file
// A5Q5
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    if(argc != 2)
    {
        printf("invalid arguments \n");
        return -1;
    }
    fd = open(argv[1],O_RDONLY);            // create the file which is not created
    if(fd != -1)
    {
        printf("file is existing \n");
    }
    else
    {
        fd = creat(argv[1],0777);
        if(fd != -1)
        {
            printf("New File is created\n");
        }
    }

    return 0;
}