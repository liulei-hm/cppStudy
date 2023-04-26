//
// Created by liulei on 2023/4/12.
//
#include "all.h"

typedef struct List{
    int data;
    struct List *next;
}List_ST;

class List_CL{
public:
    List_CL() : data(-1), next(nullptr) {}
public:
    int data;
    List_CL *next;
};

void build_list_head_Fault(List_ST *list){
    list = (List_ST *)malloc(sizeof(List_ST));
}
void build_list_head(List_ST **list){
    *list = (List_ST *)malloc(sizeof(List_ST));
    memset(*list,0x00,sizeof(List_ST)); //清空结构体
    (**list).data = -1;
}
void build_list_head_CL(List_CL *&list){
    list = new List_CL();
    list->data = 4;
}

int main(){
    List_ST *list = nullptr;
    //build_list_head_Fault(list); 这样不行，list在函数中为副本，只能改变它指向的内容，不能改变它的指向
    build_list_head(&list);
    printf("list_head = %d\n",list->data);

    List_CL *list_cl = nullptr;
    build_list_head_CL(list_cl);
    cout << list_cl->data;

    return 0;
}