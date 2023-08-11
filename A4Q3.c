// A4Q3
// accept two file name from user and check content of both files are equal or not

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc , char *argv[])
{
    int fd1 = 0,fd2 =0,ret =0,i = 0;
    struct stat obj1,obj2;
    char buffer1[1024];
    char buffer2[1024];


    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[1],O_RDONLY);    
    
    if(fd1 ==-1 || fd2 == -2)
    {
        printf("unable to open file \n");
        return-1;
    }
    fstat(fd1,&obj1);
    fstat(fd2,&obj2);

    if(obj1.st_size != obj2.st_size)
    {
        printf("files are different \n");
        return -1;
    }
    while (ret = read(fd1,buffer1,sizeof(buffer1)) != 0)
    {
        printf("itration no : %d \n",i);
        i++;
        ret = read(fd2,buffer2,sizeof(buffer2));
        if(memcmp(buffer1,buffer2,ret) != 0)
        {
            break;
        }
        
    }
    if(ret == 0)
    {
        printf("both files are identicals \n");
    }
    else
    {
        printf("both files are different \n");
    }
    close(fd1);
    close(fd2);
    
    return 0;
}