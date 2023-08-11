// A4Q5
// accept file name and position from user and read 20 bytes from thata position

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc , char *argv[])
{
    int fd =0,ret = 0;
    char arr[20];
    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("unable to open file \n");
        return -1;
    }

    lseek(fd,atoi(argv[2]),0);
    read(fd,arr,20);
    
    printf("data from files is: %d\n",ret);
    write(1,arr,ret);

    close(fd);


    return 0;
}