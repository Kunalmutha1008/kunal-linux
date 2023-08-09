//accept the file name and mode from user open file in specific mode

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int fd = 0;
    int mode = 0;

    printf("name_of_executable   name_of_file   mode\n");
    if(argc != 3)
    {
        printf("invlaid number of arguments \n");
    }
    if(strcmp(argv[2],"read") == 0)
    {
        mode = O_RDONLY;
    }
    if(strcmp(argv[2],"write") == 0)
    {
        mode = O_WRONLY;
    }
    else
    {
        mode = O_RDWR;
        printf("file is open in read and write mode\n");
    }
    fd = open(argv[1],mode);
    if(fd == -1)
    {
        printf("unable to open file \n");
        return -1;
    }
    else
    {
        printf("file is successfully open with FD %d : \n",fd);
    }
    return 0;
}