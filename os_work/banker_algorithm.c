#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max_Avail 5//资源种类上限
#define Max_AvailNum 5//每种资源可用数上限
#define Max_ProcNum 5//进程数目上限

void AllocaTionInit(int AllocaTion[Max_Avail][Max_ProcNum])
{
    int i = 0;
    for(; i < Max_Avail ; ++i)
    {
        int j = 0;
        for(; j < Max_ProcNum; ++j)
        {
            AllocaTion[i][j] = 0;
        }
    }
}
void ResourceAllocation(int** Available,int **Max,int **AllocaTion,int **Need)
{
    if(Available == NULL || Max == NULL || AllocaTion == NULL || Need == NULL)
    {
        return;
    }
    int i = 0;
    int j = 0;
    for(i = 0; i < Max_Avail; ++i)
    {
        for(j = 0; j < Max_ProcNum; ++j)
        {

        }
    }
}

int main()
{
    int Available[Max_Avail];//定义了可利用资源数目，下标即资源种类
    printf("请输入(0~4)五个资源各自的数目> ");
    int i = 0;
    for(; i < Max_Avail; ++i)
    {
        scanf("%d",&Available[i]);
    }
    int j = 0;
    printf("请输入(0~4)五个进程对每个资源的需求数目> ");
    int Max[Max_Avail][Max_ProcNum];
    for(i = 0; i < Max_Avail; ++i)
    {
        for(j = 0; j < Max_ProcNum; ++j)
        {
            scanf("%d",&Max[i][j]);
        }
    }
    
    int AllocaTion[Max_Avail][Max_ProcNum];
    AllocaTionInit(AllocaTion);//初始化分配矩阵
    int Need[Max_Avail][Max_ProcNum];
    for(i = 0;i < Max_Avail; ++i)//初始化需求矩阵
    {
        for(j = 0; j < Max_ProcNum; ++j)
        {
            Need[i][j] = Max[i][j] - AllocaTion[i][j];
        }
    }

    ResourceAllocation(Available,Max,AllocaTion,Need);
    IsSafe();
    
    return 0;
}
