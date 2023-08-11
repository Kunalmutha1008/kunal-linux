// accept two file name from user and copy contents of an existing file into newly created file
// used to display source code on screen     ./filesystem11.c  filesystem10  noofbyte(450)

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BLOCKSIZE 1024
int main(int argc ,char *argv[])
{
    int fdsource = 0;
    int fddest = 0;
    int ret = 0;
    char Buffer[BLOCKSIZE] = {'\0'};

    printf("usage : name of source file    name of destination file\n");     // .\filesystem8 marvellous.txt
    

    if(argc != 3)
    {
        printf("insufficient argument ");
        return -1;
    }
    fdsource = open(argv[1], O_RDONLY);         // open source file
    if(fdsource == -1)
    {
        printf("unable to open file \n");
        return -1;
    }

    fddest = creat(argv[2],0777);           // create dest file
    if(fddest == -1)
    {
        printf("unable to create destination file \n");
        close(fdsource);
        return -1;
    }


    printf("data from file : \n");
    while((ret = read(fdsource,Buffer,sizeof(Buffer))) != 0)
    {
        write(fddest,Buffer,ret);               // write data from buffer into dest file
        memset(Buffer,0,sizeof(Buffer));        // string.h header fi;le
    }
    close(fdsource);
    close(fddest);
    return 0;
}