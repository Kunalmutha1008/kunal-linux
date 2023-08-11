/// write structure in file and dtructure contain information of students 
// a5q1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)
struct student
{
    int Rollno;
    char Sname[20];
    float marks;
    int age;
};

int main(int argc, char *argv[])
{
    struct student sobj;
    char fname[20];
    int fd =0;

    strcpy(sobj.Sname,"kunal");

    printf("enter the file name : \n");
    scanf("%s",fname);
    
    fd = open(fname,O_RDONLY);
    read(fd,&sobj,sizeof(sobj));

    printf("roll number : %d : \n",sobj.Rollno);

    printf("name : %d : \n",sobj.Sname);
    printf("marks : %d : \n",sobj.marks);
    printf("age : %d : \n",sobj.age);

   // write(fd,&sobj,sizeof(sobj));       //sizeof indicate what size that you want to write
    return 0;
}