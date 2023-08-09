// accept file name and no of bytes and read no of bytes 

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc ,char*argv[])
{
    int fd = 0,ret = 0;
    char *buffer = NULL;
    int size = 0;
    printf("usage : name_of_executable    Name_of_file(output.txt)      no of byte (16)\n");     // .\filesystem8 marvellous.txt
    

    if(argc != 3)
    {
        printf("invalid no of argument ");
        return -1;
    }
    size = atoi(argv[2]);
    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("unable to open file \n");
        return -1;
    }
    buffer = (char *)malloc(size);             // atoi is ASCII TO INTEGER

    ret = read(fd,buffer,size);
    if(ret == 0)
    {
        printf("unable to read data \n");
        return -1;
    }
    printf("data from file is : \n");
    write(1,buffer,ret);
    return 0;
}