//
// Created by liulei on 2023/3/28.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "json_obj.h"
#include "json_file.h"

void json_obj_print(cJSON *root){
    if(root==NULL) return;
    // ��ӡ����̨�鿴
    char *cPrint = cJSON_Print(root);
    char *cPrintUnformatted = cJSON_PrintUnformatted(root);
    printf("cJSON_Print��%s\n", cPrint);		// cJSON_Print��������ʽ����
    printf("cJSON_PrintUnformatted��%s\n", cPrintUnformatted);	// cJSON_PrintUnformatted��û������ʽ����
    // ���ص��ַ���ָ����Ҫ�Լ��ͷ�
    free(cPrint);
    free(cPrintUnformatted);
}

cJSON *json_obj_create(){
    // ������� { }
    cJSON *interest = cJSON_CreateObject();
    // ����Ԫ�أ��Ե�ֵ���ַ���ʱ����Ҫʹ�ú���cJSON_CreateString()����
    cJSON_AddItemToObject(interest, "basketball", cJSON_CreateString("����"));
    cJSON_AddItemToObject(interest, "badminton", cJSON_CreateString("��ë��"));
    cJSON_AddItemToObject(interest, "pingpang", cJSON_CreateString("ƹ����"));
    // ���� [ ] ����
    cJSON *color = cJSON_CreateArray();
    // �����������Ԫ��
    cJSON_AddItemToArray(color, cJSON_CreateString("black"));
    cJSON_AddItemToArray(color, cJSON_CreateString("white"));
    // ������� { }
    cJSON *serialOne = cJSON_CreateObject();
    cJSON_AddItemToObject(serialOne, "language", cJSON_CreateString("����"));
    cJSON_AddItemToObject(serialOne, "grade", cJSON_CreateNumber(10));

    cJSON *serialTwo = cJSON_CreateObject();
    cJSON_AddItemToObject(serialTwo, "language", cJSON_CreateString("Ӣ��"));
    cJSON_AddItemToObject(serialTwo, "grade", cJSON_CreateNumber(6));

    // ������� { }
    cJSON *languages = cJSON_CreateObject();
    cJSON_AddItemToObject(languages, "serialOne", serialOne);
    cJSON_AddItemToObject(languages, "serialTwo", serialTwo);
    // ���� [ ] ����
    cJSON *education1 = cJSON_CreateArray();
    cJSON_AddItemToArray(education1, cJSON_CreateString("Сѧ"));
    cJSON_AddItemToArray(education1, cJSON_CreateString("����"));

    cJSON *education2 = cJSON_CreateArray();
    cJSON_AddItemToArray(education2, cJSON_CreateString("����"));
    cJSON_AddItemToArray(education2, cJSON_CreateString("��ѧ"));

    // ���� [ ] ����
    cJSON *education = cJSON_CreateArray();
    cJSON_AddItemToArray(education, education1);
    cJSON_AddItemToArray(education, education2);


    // ���� { } ����
    cJSON *likeObject1 = cJSON_CreateObject();
    cJSON_AddItemToObject(likeObject1, "game", cJSON_CreateString("�����"));
    cJSON_AddItemToObject(likeObject1, "price", cJSON_CreateNumber(66.6));    // ��ֵ������ʱ����Ҫʹ�ú���cJSON_CreateNumber()����
    //cJSON_AddNumberToObject(likeObject1, "price", 66.6);  // ��������д

    cJSON *likeObject2 = cJSON_CreateObject();
    cJSON_AddItemToObject(likeObject2, "game", cJSON_CreateString("�궷��"));
    cJSON_AddItemToObject(likeObject2, "price", cJSON_CreateNumber(77.7));

    // ���� [ ] ����
    cJSON *like = cJSON_CreateArray();
    // �����������Ԫ��
    cJSON_AddItemToArray(like, likeObject1);
    cJSON_AddItemToArray(like, likeObject2);

    // ����������
    cJSON *root = cJSON_CreateObject();
    // ��������������
    cJSON_AddItemToObject(root, "name", cJSON_CreateString("С��"));  // "name":  "С��"
    cJSON_AddItemToObject(root, "age", cJSON_CreateNumber(23));      // "age":  23
    cJSON_AddItemToObject(root, "interest", interest);
    cJSON_AddItemToObject(root, "color", color);
    cJSON_AddItemToObject(root, "like", like);
    cJSON_AddItemToObject(root, "education", education);
    cJSON_AddItemToObject(root, "languages", languages);
    cJSON_AddItemToObject(root, "vip", cJSON_CreateTrue());  // "vip":  true    ���벼������������Ҫʹ��cJSON_CreateBool����
    cJSON_AddItemToObject(root, "address", cJSON_CreateNull());  // "address":  null  ����NULLֵ��Ҫʹ��cJSON_CreateNull����
    //cJSON_AddTrueToObject(root, "vip");
    //cJSON_AddNullToObject(root, "address");  // ��������дҲ�ǿ��Ե�
    return root;
}

cJSON *json_obj_read(){
    // ����ȡ����json�ַ���ת����json����ָ��
    char *jsonStr = open_file();
    if(!jsonStr) return NULL;
    cJSON *read_root = cJSON_Parse(jsonStr);
    if (!read_root) {
        const char *err = cJSON_GetErrorPtr();
        printf("Error before: [%s]", err);
        free((void *)err);
        free(jsonStr);
        return NULL;
    }
}


static void parse_key(cJSON *root){
    cJSON *item = NULL;
    char *v_str = NULL;
    int v_int = 0;
    // ������"name":	"С��",
    item = cJSON_GetObjectItem(root, "name");
    if (item != NULL) {
        /* д��һ��*/
        // �ж��ǲ����ַ�������
        //if (item->type == cJSON_String) {
        //	v_str = cJSON_Print(item);		// ͨ��������ȡֵ
        //	printf("name = %s", v_str);
        //	free(v_str);					// ͨ���������ص�ָ����Ҫ����free������ᵼ���ڴ�й©
        //	v_str = NULL;
        //}
        /* д������ */
        // �ж��ǲ����ַ�������
        if (item->type == cJSON_String) {
            v_str = item->valuestring;		// �˸�ֵ��ǳ����������Ҫ�����ͷ��ڴ�
            printf("name = %s\n", v_str);
        }
    }
    // ������"age":	"23",
    item = cJSON_GetObjectItem(root, "age");
    if (item != NULL) {	// �Ϸ��Լ��
        if (item->type == cJSON_Number) {		// �ж��ǲ�������
            v_int = item->valueint;			// ��ȡֵ
            printf("age = %d\n", v_int);
        }
    }
    // ������"vip":	true,
    item = cJSON_GetObjectItem(root, "vip");
    if (item != NULL) {
        if (item->type == cJSON_True || item->type == cJSON_False) {
            v_str = cJSON_Print(item);		// ����bool���ͽṹ����û�и���������ʹ���ַ�������
            printf("vip = %s\n", v_str);
            free(v_str);
            v_str = NULL;
        }
    }


// ������"address":	null
    item = cJSON_GetObjectItem(root, "address");
    if (item != NULL && item->type == cJSON_NULL) {
        v_str = cJSON_Print(item);		// ����NULL���ͽṹ����û�и���������ʹ���ַ�������
        printf("address = %s\n", v_str);
        free(v_str);
        v_str = NULL;
    }
}
static void parse_object(cJSON *root)
{
    cJSON *item = NULL;
    char *v_str = NULL;
    /*************** ��ʽһ ***************/
    item = cJSON_GetObjectItem(root, "interest");		// ��ȡobject������
    if (item != NULL) {
        cJSON *val = NULL;

        val = cJSON_GetObjectItem(item, "basketball");	// ����object��������������basketball����
        if (val != NULL && val->type == cJSON_String) {
            v_str = val->valuestring;
            printf("basketball = %s\n", v_str);
        }

        val = cJSON_GetObjectItem(item, "badminton");	// ����object��������������badminton����
        if (val != NULL && val->type == cJSON_String) {
            v_str = val->valuestring;
            printf("badminton = %s\n", v_str);
        }
    }

    /*************** ��ʽ�� ***************/
    item = cJSON_GetObjectItem(root, "interest");
    if (item != NULL) {
        cJSON *obj = item->child;	// ��� "basketball":	"����"

        while (obj) {
            if (obj->type == cJSON_String) {
                char *v_str = obj->valuestring;
                printf("%s = %s\n", obj->string, v_str);	// ����ͨ��string��ü�
            }
            // ��ȡ��һ��Ԫ��
            obj = obj->next;
        }
    }
}

static void parse_array(cJSON *root)
{
    cJSON *item = NULL;
    char *v_str = NULL;
    /*************** ��ʽһ ***************/
    item = cJSON_GetObjectItem(root, "color");
    if (item != NULL) {
        int size = cJSON_GetArraySize(item);	// ����������

        for (int i = 0; i < size; i++) {
            cJSON *arr = cJSON_GetArrayItem(item, i);	// ����������������е�ֵ

            if (arr != NULL && arr->type == cJSON_String) {
                v_str = arr->valuestring;
                printf("color = %s\n", v_str);
            }
        }
    }
    /*************** ��ʽ�� ***************/
    item = cJSON_GetObjectItem(root, "color");
    if (item != NULL) {
        cJSON *arr = item->child;	// ��� "black"

        while (arr) {
            if (arr->type == cJSON_String) {
                char *v_str = arr->valuestring;
                printf("color = %s\n", v_str);
            }
            // ��ȡ��һ��Ԫ��
            arr = arr->next;
        }
    }
}

static void parse_object_in_array(cJSON *root)
{
    cJSON *item = NULL;
    char *v_str = NULL;
    double v_double = 0.0;
    /*************** ��ʽһ ***************/
    item = cJSON_GetObjectItem(root, "like");
    if (item != NULL) {
        int size = cJSON_GetArraySize(item);	// ��ȡ�������С

        for (int i = 0; i < size; i++) {
            cJSON *obj = cJSON_GetArrayItem(item, i);		// ��ȡ���������obj
            cJSON *val = NULL;

            if (obj != NULL && obj->type == cJSON_Object) {	// �ж������ڵ�Ԫ���ǲ���obj����
                val = cJSON_GetObjectItem(obj, "game");		// ���obj���ֵ

                if (val != NULL && val->type == cJSON_String) {
                    v_str = val->valuestring;
                    printf("game = %s\n", v_str);
                }

                val = cJSON_GetObjectItem(obj, "price");
                if (val != NULL && val->type == cJSON_Number) {
                    v_double = val->valuedouble;
                    printf("price = %.2f\n", v_double);
                }
            }
        }
    }


    /*************** ��ʽ�� ***************/
    item = cJSON_GetObjectItem(root, "like");
    if (item != NULL) {
        cJSON *obj = item->child;	// ��� { "game": "�����", "price": 66.6 }

        while (obj) {
            if (obj->type == cJSON_Object) {

                cJSON *objValue = obj->child;	// ��� "game": "�����"
                while (objValue) {

                    // ��ͨ������ȥ����
                    if (objValue->type == cJSON_String) {
                        char *v_str = objValue->valuestring;
                        printf("%s = %s\n", objValue->string, v_str);

                    } else if (objValue->type == cJSON_Number) {
                        double v_double = objValue->valuedouble;
                        printf("%s = %.2f\n", objValue->string, v_double);
                    }
                    // ��ȡ��һ��Ԫ��
                    objValue = objValue->next;
                }
            }
            // ��ȡ��һ��Ԫ��
            obj = obj->next;
        }
    }
}

static void parse_array_in_array(cJSON *root)
{
    cJSON *item = NULL;
    char *v_str = NULL;
    double v_double = 0.0;
    /*************** ��ʽһ ***************/
    item = cJSON_GetObjectItem(root, "education");
    if (item != NULL) {
        int size = cJSON_GetArraySize(item);	// ��ȡ�������С

        for (int i = 0; i < size; i++) {
            cJSON *arr = cJSON_GetArrayItem(item, i);		// �������	[ "Сѧ", "����" ]

            if (arr != NULL && arr->type == cJSON_Array) {
                int arrSize = cJSON_GetArraySize(arr);

                for (int j = 0; j < arrSize; j++) {
                    cJSON *arr2 = cJSON_GetArrayItem(arr, j);	// �ٽ�һ�������Ϳ��Եõ����������Ԫ����

                    if (arr2 != NULL && arr2->type == cJSON_String) {
                        v_str = arr2->valuestring;
                        printf("education = %s\n", v_str);
                    }
                }
            }
        }
    }

    /*************** ��ʽ�� ***************/
    item = cJSON_GetObjectItem(root, "education");
    if (item != NULL) {
        cJSON *arr = item->child;	// ��� [ "Сѧ", "����" ]

        while (arr) {
            if (arr->type == cJSON_Array) {

                cJSON *arrValue = arr->child;	// ��� "Сѧ"
                while (arrValue) {
                    if (arrValue->type == cJSON_String) {
                        char *v_str = arrValue->valuestring;
                        printf("education = %s\n", v_str);
                    }
                    arrValue = arrValue->next;	// ��ȡ��һ��Ԫ��
                }
            }
            // ��ȡ��һ��
            arr = arr->next;
        }
    }
}

static void parse_object_in_object(cJSON *root)
{
    cJSON *item = NULL;
    char *v_str = NULL;
    double v_double = 0.0;
    int v_int = 0;
    /*************** ��ʽһ ***************/
    char *arrStr[] = { "serialOne", "serialTwo" };		// ������ǰ������Ҫ�����Ķ�����������Ϳ���ʹ��forѭ�����н�����

    item = cJSON_GetObjectItem(root, "languages");
    if (item != NULL) {
        cJSON *val = NULL;
        int size = sizeof(arrStr) / sizeof(char *);

        // ͨ������ָ�����飬���ÿ������ļ����ڽ��н��������������ʹ��forѭ���������Ǿ�����ʵʵ��д���뽫ȫ������������ϣ�
        for (int i = 0; i < size; i++) {
            cJSON *obj1 = cJSON_GetObjectItem(item, arrStr[i]);

            if (obj1 != NULL && obj1->type == cJSON_Object) {

                val = cJSON_GetObjectItem(obj1, "language");
                if (val != NULL && val->type == cJSON_String) {
                    v_str = val->valuestring;
                    printf("language = %s\n", v_str);
                }

                val = cJSON_GetObjectItem(obj1, "grade");
                if (val != NULL && val->type == cJSON_Number) {
                    v_int = val->valueint;
                    printf("grade = %d\n", v_int);
                }
            }
        }
    }

    /*************** ��ʽ�� ***************/
    // �ڲ�֪������ʲô������� �� ��֪���ж���Ԫ�ص�����¿���
    item = cJSON_GetObjectItem(root, "languages");
    if (item != NULL) {
        // ��ȡ��languages��ĵ�һ����Ԫ��
        cJSON *obj = item->child;	// Ҳ���ǣ�"serialOne": { "language": "����", "grade": 10 }

        while (obj) {
            if (obj->type == cJSON_Object) {

                // ��ȡ����Ԫ�ص���Ԫ��
                cJSON *value = obj->child;	// Ҳ���ǣ�{ "language": "����", "grade": 10 }

                while (value) {
                    if (value->type == cJSON_String) {
                        printf("%s = %s\n", value->string, value->valuestring);

                    } else if (value->type == cJSON_Number) {
                        printf("%s = %d\n", value->string, value->valueint);
                    }
                    // ͨ��next�������ɻ�ȡ�����Ԫ����
                    value = value->next;
                }
            }

            // �����һ����Ԫ��
            obj = obj->next;
        }
    }
}


void json_obj_parse(cJSON *read_root){
    if(read_root==NULL) return;

    bool v_bool = false;
    parse_key(read_root);
    parse_object(read_root);
    parse_array(read_root);
    parse_object_in_array(read_root);
    parse_array_in_array(read_root);
    parse_object_in_object(read_root);
}