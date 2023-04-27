
#include<stdio.h>
#define MAX 50
  struct  queue{
     int front,rear;
     int a[MAX];
}q;

 void initq()
 {

     q.rear=-1;
     q.front=-1;
 }
 int isempty()
{

    if(q.front==-1||q.front>q.rear)
    {

        return 1;
    }
    else{
        return 0;
    }
}
int isfull()
{

    if(q.rear==(MAX-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

 void addq(int num)
 {

    if(q.front==-1)
    {

        q.front=0;
    }
   if(isfull())
   {

       printf("\n q is full");
   }
     else{
        q.rear++;
        q.a[q.rear]=num;
     }

 }
 int delq()
 {
       int v;
     if(isempty())
     {

         printf("\n q is empty");
     }
     else{
        v=q.a[q.front];
        q.front++;
        return v;

     }


 }

void bfs(int g[20][20],int n)
{

    int visited[20]={0};
    int i,v=0;
    visited[v]=1;
    addq(v);

    while(!isempty())
    {


          v=delq();
          printf("%d\t",v);
         for(i=0;i<n;i++)
         {



                if(g[v][i]==1&&visited[i]==0)
                {

                    addq(i);
                    visited[i]=1;


                }


         }



    }



}


void main()
{
    initq();

    int g[20][20],i,j,n;
    printf("\n enter the  number of vertices");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {

        for(j=0;j<n;j++)
        {

            scanf("%d",&g[i][j]);

        }
    }
      for(i=0;i<n;i++)
      {
          for(j=0;j<n;j++)
          {

              printf("%d\t",g[i][j]);
          }
          printf("\n");
      }

      bfs(g,n);
}
