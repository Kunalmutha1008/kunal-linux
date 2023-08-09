// accept file name and open that file
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    char Fname[20];
    int fd = 0;
    printf("enter the file name that you want to open \n");
    scanf("%s",Fname);

    fd = open(Fname,O_RDONLY);
    if(fd == -1)
    {
        printf("unable to open the file \n");
    }
    else
    {
        printf("File is open successfully with FD %d\n",fd);
    }
    return 0;
}