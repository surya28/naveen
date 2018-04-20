#include<stdio.h>
#include<pthread.h>
#include<string.h>

char str[10];
int nthread;
void *work(void *);
int va=0,ve=0,vi=0,vo=0,vu=0,total=0;    
main()
{
    pthread_t id;
    int i,n;
    
//    printf("Enter The Size of a String:");//    scanf("%d",&n);//    str=(char *)malloc(sizeof(char)*n);

    printf("Enter The String:");
    scanf("%s",&str);
    //printf("%s",str);
    
    printf("Enter The No of Thread:");
    scanf("%d",&nthread);
    for(i=0;i<nthread;i++)
    {
        if(0==pthread_create(&id,NULL,work,(void *)&i))
        {
            continue;
        }
        else
        {
            printf("Problem In Thread Creation");
        }
    }    
    pthread_join(id,NULL);

    printf("a:%d\n",va);
    printf("e:%d\n",ve);
    printf("i:%d\n",vi);
    printf("o:%d\n",vo);
    printf("u:%d\n",vu);
    total=total+va+ve+vi+vo+vu;
    printf("Total:%d",total);    
}
void *work(void *i)
{
    int *tid,len,size=0,j,p;

    tid=(int *)i;
//    int va=0,ve=0,vi=0,vo=0,vu=0;    

    printf("Thread id=%d\n",*tid);
    len=strlen(str);
    size = len/nthread;
//    p=*tid;//    printf("%d",*tid);for(j=((*tid)*size);j<(((*tid)*size)+size);j++)
    {
        if(str[j]=='a'||str[j]=='A')
        {
            va++;
        }
        elseif(str[j]=='e'||str[j]=='E')
        {
            ve++;
        }
        elseif(str[j]=='i'||str[j]=='I')
        {
            vi++;
        }
        elseif(str[j]=='o'||str[j]=='O')
        {
            vo++;

        }
        elseif(str[j]=='u'||str[j]=='U')
        {
            vu++;
        }
    
    }
    
    
    pthread_exit(NULL);
}
