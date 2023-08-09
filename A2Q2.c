// accept file and read data and display
// write system call
// used to display source code on screen     ./filesystem10.c  filesystem10  noofbyte(450)

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define BLOCKSIZE 1024
int main(int argc ,char*argv[])
{
    int fd = 0,ret = 0;
    char Buffer[BLOCKSIZE];
    printf("usage : name_of_executable    Name_of_file(output.txt)      no of byte (16)\n");     // .\filesystem8 marvellous.txt
    

    if(argc != 2)
    {
        printf("invalid no of argument ");
        return -1;
    }
    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("unable to open file \n");
        return -1;
    }
    printf("data from file : \n");
    while((ret = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        write(1,Buffer,ret);
    }
    close(fd);
    return 0;
}

//echo "hello world " | cat >> new.txt (name of text file in which you want to write data)