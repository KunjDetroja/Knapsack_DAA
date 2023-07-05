#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void display();
void weight();
void profit();
void calc();
void piwi();
void dyna();

int n,W;

struct item
{
    int no,v,w;
    float pw;
}it[100];

void main()
{
    int i,c,ch;
    printf("enter total number of item:-");
    scanf("%d",&n);
    printf("Enter the maximum weight:-");
    scanf("%d",&W);
    if(n==0 || W==0)
    {
        printf("\nKnapsack is not possible for given enter\n");
        exit(0);

    }
    float v,w;
    for(i=0;i<n;i++)
    {
        it[i].no=i+1;
        printf("enter the weight of item-%d:-",i+1);
        scanf("%d",&it[i].w);
        printf("enter the value of item-%d:-",i+1);
        scanf("%d",&it[i].v);
        v=it[i].v;
        w=it[i].w;
        it[i].pw=v/w;
    }
    display();
    printf("\n1.greedy approch\n2.dynamic approch");
    printf("enter the choice:- ");
    scanf("%d",&c);
    if(c==1)
    {
        printf("\n1.about weight\n2.about profit\n3.about pi/wi\n4.all of above\n");
        printf("enter the choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                weight();
                break;
            case 2:
                profit();
                break;
            case 3:
                piwi();
                break;
            case 4:
                weight();
                profit();
                piwi();
                break;
            default:
                printf("invalid entry");
                break;
        }
    }
    if(c==2)
    {
        dyna();
    }
}

void display()
{
	int m;
    printf("---------------------------\n");
    printf("| sr.no | weight | value  |\n");
    printf("---------------------------\n");
    for(m=0;m<n;m++)
    {
        printf("|   %02d  |   %02d   |   %02d   |\n",it[m].no,it[m].w,it[m].v);
    }
    printf("---------------------------\n");
    printf("And maximum weight is %d\n",W);
}

void weight()
{
    int temp1,temp2,temp3,temp4,i,j,m;
    printf("Item sorted by weight:-\n");
    for(i=0;i<n-2;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(it[j].w>it[j+1].w)
            {
                temp1=it[j].no;
                temp2=it[j].v;
                temp3=it[j].w;
                temp4=it[j].pw;
                it[j].no=it[j+1].no;
                it[j].v=it[j+1].v;
                it[j].w=it[j+1].w;
                it[j].pw=it[j+1].pw;
                it[j+1].no=temp1;
                it[j+1].v=temp2;
                it[j+1].w=temp3;
                it[j+1].pw=temp4;

            }
        }
    }
    display();
    calc();
}

void calc()
{
	int m,k;
    float r=W,p=0,a[100];
    printf("-----------------------------------------------\n");
    printf("| sr.no | weight | value  |   RW    | profit  |\n");
    printf("-----------------------------------------------\n");
    for(m=0;m<n;m++)
    {
        if(r>=it[m].w)
        {
            r=r-it[m].w;
            p=p+it[m].v;
            if(r>9)
            {
                printf("|   %02d  |   %02d   |   %02d   |  %2.2f  |  %.2f  |\n",it[m].no,it[m].w,it[m].v,r,p);
            }
            else
            {
                printf("|   %02d  |   %02d   |   %02d   |  0%2.2f  |  %.2f  |\n",it[m].no,it[m].w,it[m].v,r,p);
            }
            a[it[m].no]=1;
        }
        else if(r>0)
        {
            r=r/it[m].w;
            a[it[m].no]=r;
            p=p+r*it[m].v;
            r=0;
            printf("|   %02d  |   %02d   |   %02d   |  0%2.2f  |  %2.2f  |\n",it[m].no,it[m].w,it[m].v,r,p);
            r=0;
        }
    }
    printf("-----------------------------------------------\n");
    printf("\nTotal Profit is %.2f\n",p);
    printf("selected objects are { ");
    for(k=1;k<n;k++)
    {
        printf(" %.1f ,",a[k]);
    }
    printf(" %.1f }",a[n]);
}

void profit()
{
    int temp1,temp2,temp3,temp4,i,j;
    printf("\nItem sorted by profit:-\n");
    for(i=0;i<n-2;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(it[j].v<it[j+1].v)
            {
                temp1=it[j].no;
                temp2=it[j].v;
                temp3=it[j].w;
                temp4=it[j].pw;
                it[j].no=it[j+1].no;
                it[j].v=it[j+1].v;
                it[j].w=it[j+1].w;
                it[j].pw=it[j+1].pw;
                it[j+1].no=temp1;
                it[j+1].v=temp2;
                it[j+1].w=temp3;
                it[j+1].pw=temp4;
            }
        }
    }
    display();
    calc();
}

void piwi()
{
    int temp1,temp2,temp3,temp4,i,j;
    printf("\nItem sorted by pi/wi:-\n");
    for(i=0;i<n-2;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(it[j].pw<it[j+1].pw)
            {
                temp1=it[j].no;
                temp2=it[j].v;
                temp3=it[j].w;
                temp4=it[j].pw;
                it[j].no=it[j+1].no;
                it[j].v=it[j+1].v;
                it[j].w=it[j+1].w;
                it[j].pw=it[j+1].pw;
                it[j+1].no=temp1;
                it[j+1].v=temp2;
                it[j+1].w=temp3;
                it[j+1].pw=temp4;
            }
        }
    }
    int m;
    printf("--------------------------------------\n");
    printf("| sr.no | weight | value  |   pi/wi  |\n");
    printf("--------------------------------------\n");
    for(m=0;m<n;m++)
    {
        if(it[m].pw>9)
        {
            printf("|   %02d  |   %02d   |   %02d   |   %.2f  |\n",it[m].no,it[m].w,it[m].v,it[m].pw);
        }
        else
        {
            printf("|   %02d  |   %02d   |   %02d   |   0%.2f  |\n",it[m].no,it[m].w,it[m].v,it[m].pw);
        }
        
    }
    printf("--------------------------------------\n");
    printf("And maximum weight is %d\n",W);
    int k;
    float r=W,p=0,a[100];
    printf("----------------------------------------------------------\n");
    printf("| sr.no | weight | value  |   pi/wi  |   RW    | profit  |\n");
    printf("----------------------------------------------------------\n");
    for(m=0;m<n;m++)
    {
        if(r>=it[m].w)
        {
            r=r-it[m].w;
            p=p+it[m].v;
            if(r>9)
            {
                printf("|   %02d  |   %02d   |   %02d   |   %.2f  |  %2.2f  |  %.2f  |\n",it[m].no,it[m].w,it[m].v,it[m].pw,r,p);
            }
            else
            {
                printf("|   %02d  |   %02d   |   %02d   |   %.2f  |  0%2.2f  |  %.2f  |\n",it[m].no,it[m].w,it[m].v,it[m].pw,r,p);
            }
            a[it[m].no]=1;
        }
        else if(r>0)
        {
            r=r/it[m].w;
            a[it[m].no]=r;
            p=p+r*it[m].v;
            r=0;
            printf("|   %02d  |   %02d   |   %02d   |   %.2f  |  0%2.2f  |  %2.2f  |\n",it[m].no,it[m].w,it[m].v,it[m].pw,r,p);
            r=0;
        }
    }
    printf("----------------------------------------------------------\n");
    printf("\nTotal Profit is %.2f\n",p);
    printf("selected objects are { ");
    for(k=1;k<n;k++)
    {
        printf(" %.1f ,",a[k]);
    }
    printf(" %.1f }",a[n]);
}

void dyna()
{
    int t[100][100],i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(j >= it[i].w)
            {
                if(t[i-1][j]>(it[i].v+t[i-1][j-it[i].w]))
                {
                    t[i][j]=t[i-1][j];
                }
                else
                {
                    t[i][j]=it[i].v+t[i-1][j-it[i].w];
                }
            }
            else if(it[i].w>j)
            {
                t[i][j]=t[i-1][j];
            }
            else if(i==0 || j==0)
            {
                t[i][j]=0;
            }
            
        }
    }
    printf("\ndyam table:-\n\n\t");
    for(j=0;j<=W;j++)
    {
        printf("00 ");
    }
    printf("\n\t");
    for(i=0;i<n;i++)
    {
        for(j=0;j<=W;j++)
        {
            printf("%02d ",t[i][j]);
        }
        printf("\n\t");
    }
    printf("\n\tMaximum profit is %d",t[n-1][W]);
    int a[100];
    i=n-1;
    int k=W;
    while (i>=0 && k>0)
    {
        if(t[i][k]!=t[i-1][k])
        {
            a[i]=1;
            k=k-it[i].w;
            i=i-1;
        }
        else
        {
            i=i-1;
        }
    }
    printf("\nselected objects are { ");
    for(k=0;k<n-1;k++)
    {
        printf(" %d ,",a[k]);
    }
    printf(" %d }",a[n-1]);
    
}