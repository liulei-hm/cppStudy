//
// Created by liulei on 2023/3/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib/cJSON.h"
#include "json_file.h"
#include "json_obj.h"


//https://blog.csdn.net/m0_67265311/article/details/123344280

int main(){
    //дһ��json���ļ���
    cJSON *write_root = json_obj_create();
    //json_obj_print(write_root);
    wirte_file(write_root);
    free(write_root);
    //��ȡһ��json�ļ�
    cJSON *read_root = json_obj_read();
    json_obj_parse(read_root);
    free(read_root);


    return 0;
}