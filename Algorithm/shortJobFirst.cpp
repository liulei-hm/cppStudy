//
// Created by liulei on 2023/2/19.
//

/** 假设P个相同的处理器，n个任务同时到达，要求安排一种调度算法使得任务的平均完成时间（包括等待时间）最短
 * 贪心算法 短作业优先  将任务按运行时间递增排序，
 * ***/
#include "all.h"
#define TASK_NUM 9
#define CPU 3
#define MM 3
int main(){
    int w[CPU][MM]={0};
    int t[TASK_NUM]={3,5,6,10,11,14,15,18,20};
    for(int i=0;i<TASK_NUM;i++){
        for(int j=0;j<CPU;j++)
        {
            w[i][j]=t[i*MM+j];
        }
    }
    for(int i=0;i<10;)
    {

    }



}