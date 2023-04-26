//
// Created by liulei on 2023/3/28.
//
#include "json_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

const char *FILE_NAME = "cJSON/test.json";
void wirte_file(cJSON *root){
    if(root==NULL) return;
    // ���ļ�
    FILE *file = NULL;

    file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("open fail errno = %d,reason = %s \n", errno, strerror(errno));
        // �ͷ�ָ���ڴ�
        cJSON_Delete(root);
        return;
    }
    char *cjValue = cJSON_Print(root);
    // д���ļ�
    //int ret = fwrite(cjValue, sizeof(char), strlen(cjValue), file);
    int ret = fputs(cjValue, file);
    if (ret == EOF) {
        printf("д���ļ�ʧ�ܣ�");
    }
    fclose(file);
    free(cjValue);
}

char *open_file(){
    // ���ļ�
    FILE *file = NULL;
    file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("open fail errno = %d,reason = %s \n", errno, strerror(errno));
        return NULL;
    }
    // ����ļ���С
    struct stat statbuf;
    stat(FILE_NAME, &statbuf);
    int fileSize = statbuf.st_size;
    printf("�ļ���С��%d\n", fileSize);

    // ��������ļ���С���ڴ�
    char *jsonStr = (char *)malloc(sizeof(char) * fileSize + 1);
    memset(jsonStr, 0, fileSize + 1);

    // ��ȡ�ļ��е�json�ַ���
    int size = fread(jsonStr, sizeof(char), fileSize, file);
    if (size == 0) {
        printf("open fail errno = %d,reason = %s \n", errno, strerror(errno));
        return NULL;
    }
    fclose(file);
    return jsonStr;
}