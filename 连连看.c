#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 10 //行数
#define M 10 //列数
#define T 30 //一共有几对，请令 2T/K 为整数
#define K 4 //每种数字出现几次，请设为偶数
int x1,x2,y1,y2;
int n,m,a0[N][M],a[N][M];
void Set();
void Print();
int Judge2();
int Judge1();
int Judge0();
int Judge();
int main()
{
    int i,j,k;
    for(;;)
    {
        n = N;
        m = M;
        Set();
        Print();
        printf("0 to exit at any time.\nPlease input x1 y1 x2 y2 of the number you chose.\n\n");
        for(i=0;i<T;)
        {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            if(x1==0)
                break;
            if(Judge()==0)
                printf("LOST\n\n");
            else
            {
                a0[x1][y1] = 0;
                a0[x2][y2] = 0;
                Print();
                printf("CONTINUE\n\n");
                i++;
            }
        }
        if(i==T)
            printf("YOU ARE WIN!\n\n");
        printf("0 to exit,else to next time.\n");
        scanf("%d",&k);
        if(k==0)
            break;
    }
    return 0;
}

int Judge()
{
    x1--;
    y1--;
    x2--;
    y2--;
    if(x1<0||x1>n-1||y1<0||y1>m-1||x2<0||x2>n-1||y2<0||y2>m-1)
        return 0;
    else if(a0[x1][y1]!=a0[x2][y2]||a0[x1][y1]==0||(x1==x2&&y1==y2))
        return 0;
    else if(Judge0()==1)
        return 1;
    else if(Judge1()==1)
        return 1;
    else if(Judge2()==1)
        return 1;
    else
        return 0;
}
int Judge0()
{
    int i,find=1;
    if(x1==x2)
    {
        if(y1<y2)
            for(i=1;i<y2-y1;i++)
            {
                if(a0[x1][y1+i]!=0)
                {
                    find = 0;
                    break;
                }
            }
        else
            for(i=1;i<y1-y2;i++)
            {
                if(a0[x2][y2+i]!=0)
                {
                    find = 0;
                    break;
                }
            }
    }
    else if(y1==y2)
    {
        if(x1<x2)
            for(i=1;i<x2-x1;i++)
            {
                if(a0[x1+i][y1]!=0)
                {
                    find = 0;
                    break;
                }
            }
        else
            for(i=1;i<x1-x2;i++)
            {
                if(a0[x2+i][y2]!=0)
                {
                    find = 0;
                    break;
                }
            }
    }
    else
        find = 0;
    return find;
}
int Judge1()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            a[i][j] = a0[i][j];
    for(i=1;;i++)
        if(x1-i>=0&&a[x1-i][y1]==0)
            a[x1-i][y1] = -1;
        else
            break;
    for(i=1;;i++)
        if(x1+i<=n&&a[x1+i][y1]==0)
            a[x1+i][y1] = -1;
        else
            break;
    for(i=1;;i++)
        if(x2-i>=0&&a[x2-i][y2]==0)
            a[x2-i][y2] = -1;
        else
            break;
    for(i=1;;i++)
        if(x2+i<=n&&a[x2+i][y2]==0)
            a[x2+i][y2] = -1;
        else
            break;
    for(i=1;;i++)
        if(y1-i>=0&&a[x1][y1-i]==0)
            a[x1][y1-i] = -2;
        else if(y1-i>=0&&a[x1][y1-i]==-1)
            return 1;
        else
            break;
    for(i=1;;i++)
        if(y1+i<=m&&a[x1][y1+i]==0)
            a[x1][y1+i] = -2;
        else if(y1+i<=m&&a[x1][y1+i]==-1)
            return 1;
        else
            break;
    for(i=1;;i++)
        if(y2-i>=0&&a[x2][y2-i]==0)
            a[x2][y2-i] = -2;
        else if(y2-i>=0&&a[x2][y2-i]==-1)
            return 1;
        else
            break;
    for(i=1;;i++)
        if(y2+i<=m&&a[x2][y2+i]==0)
            a[x2][y2+i] = -2;
        else if(y2+i<=m&&a[x2][y2+i]==-1)
            return 1;
        else
            break;
    return 0;
}
int Judge2()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m-1;j++)
        {
            if(a[i][j]==-1)
            {
                j++;
                while(a[i][j]==0&&j<m-1)
                    j++;
                if(a[i][j]==-1)
                    return 1;
            }
        }
    for(j=0;j<m;j++)
        for(i=0;i<n-1;i++)
        {
            if(a[i][j]==-2)
            {
                i++;
                while(a[i][j]==0&&i<n-1)
                    i++;
                if(a[i][j]==-2)
                    return 1;
            }
        }
    return 0;
}
void Print()
{
    int i,j;
    printf("\n     y");
    for(i=1;i<=m;i++)
    {
        printf(" %2d",i);
    }
    printf("\n  x___");
    for(i=1;i<=m;i++)
    {
        printf("___",i);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf(" %2d|  ",i+1);
        for(j=0;j<m;j++)
        {
            if(a0[i][j]!=0)
                printf(" %02d",a0[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
    printf("\n");
}
void Set()
{
    int i,j,k,l;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            a0[i][j] = 0;
    srand((unsigned)time(NULL));
    for(l=0;l<K;l++)
    {
        for(k=1;k<=2*T/K;)
        {
            i = rand()%n;
            j = rand()%m;
            if(a0[i][j]==0)
            {
                a0[i][j] = k;
                k++;
            }
        }
    }
}
