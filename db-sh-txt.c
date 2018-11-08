#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stud
{
    char id[10];
    char name[20];
}db;

int main(int argc,char **argid)
{
    FILE *fptr;
    if(argc==1)
    {
        printf(" Give at least on argument\n For example, use \"nameof 201851029\"\n");
        return 0;
    }
    int flag=0,i;
    char *readdata;
    fptr=fopen("database.txt","r");
    while(!feof(fptr))
    {
        fscanf(fptr,"%s",db.id);
        fscanf(fptr,"%s",db.name);
        if(!strcmp(db.id,argid[1]))
        {
            flag=1;
            printf(" %s\n",db.name);
        }
    }
    if(!flag)
    {
        printf(" No such record\n");
    }
    fclose(fptr);
    return 0;
}