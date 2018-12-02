#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct stud
{
    char id[10];
    char name[20];
}db;

void converttoupper(char**,int);

int main(int argcount,char **arg)
{
    FILE *fptr;
    int i,flag=0;
    char *readdata;
    if(argcount==1)
    {
        printf(" Give at least one argument\n For example, use \"nameof 201851000\"\n");
        return 0;
    }
    fptr=fopen("database.txt","r");
    if(isdigit(arg[1][0]))
    {
        for(i=1;i<=argcount-1;++i)
        {
            rewind(fptr);
            while(!feof(fptr))
            {
                fscanf(fptr,"%s",db.id);
                fscanf(fptr,"%s",db.name);
                if(!strcmp(db.id,arg[i]))
                {
                    flag=1;
                    printf(" %s\t%s\n",db.id,db.name);
                    continue;
                }
            }
        }

    }
    else if(isalpha(arg[1][0]))
    {
        converttoupper(arg,argcount);
        for(i=1;i<=argcount-1;++i)
        {            
            rewind(fptr);
            while(!feof(fptr))
            {
                fscanf(fptr,"%s",db.id);
                fscanf(fptr,"%s",db.name);
                if(strstr(db.name,arg[i]))
                {
                    flag=1;
                    printf(" %s\t%s\n",db.id,db.name);
                    continue;
                }
            }
        }
    }
    if(!flag)
    {
        printf(" No such record\n");
    }
    fclose(fptr);
    return 0;
}

void converttoupper(char **strings,int argcount)
{
    int i=0,j=0;
    for(i=1;i<=argcount-1;++i)
    {
        for(j=0;strings[i][j]!='\0';++j)
        {
            strings[i][j]=toupper(strings[i][j]);
        }
    }
}