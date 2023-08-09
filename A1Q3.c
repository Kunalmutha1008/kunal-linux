
// access function used to access  the mode
// access -1 has zero permisssion and 0 has permission

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
    int mode = 0;
    if(argc != 3)
    {
        printf("insufficient arguments \n");
        return-1;
    }
    if(strcmp(argv[2],"read") == 0)
    {
        mode = R_OK;        // check read file
    }
    else if(strcmp(argv[2],"write") == 0)
    {
        mode = W_OK;        // check write file
    }
    else if(strcmp(argv[2],"execute") == 0)
    {
        mode = X_OK;        // check execute file
    }

    if(access(argv[1],mode) < 0)
    {
        printf("unable to access %s mode \n",argv[1],argv[2]);
    }
    else
    {
        printf("you can access %s file in %s mode \n",argv[1],argv[2]);
    }
    return 0;
}

/*
// accept file name and mode check our process access accepted file mode

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
        printf("file is open in read mode\n");
    }
    if(strcmp(argv[2],"write") == 0)
    {
        mode = O_WRONLY;
        printf("file is open in write mode\n");
    }
    else
    {
        mode = O_RDWR;
        printf("file is open in read and write mode\n");
    }

    fd = access("demo.txt",mode);

    if(fd == -1)
    {
        printf("unable to access file \n");
        return -1;
    }
    else
    {
        printf("file is successfully access with FD %d : \n",fd);
    }
    return 0;
}
*/
/*

*/