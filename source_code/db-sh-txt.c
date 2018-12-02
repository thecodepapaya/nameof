#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct stud
{
    char id[10];
    char name[20];
}db;

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
                    printf(" %s\n",db.name);
                    continue;
                }
            }
        }

    }
    else if(isalpha(arg[1][0]))
    {
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