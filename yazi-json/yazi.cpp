//
// Created by liulei on 2023/3/28.
//

#include <fstream>
#include <sstream>
#include <chrono>
#include "json.h"
using namespace yazi::json;

void test_constructor(){
    Json v1;
    Json v2 = true;
    Json v3 = 123;
    Json v4 = 1.23;
    Json v5 = "hello world";
    Json v6(123) ; //�������캯������Ϊexplicit Json(int value);��ֻ������ʽ���ã���ʽ����Json v3 = 123;������
}
void test_operator_override(){
    Json v1;
    Json v2 = true;
    Json v3 = 123;
    Json v4 = 1.23;
    Json v5 = "hello world";
    bool b = v2;
    int i = v3;
    double d = v4;
    string s = v5;
}
void test_operator_array(){
    Json arr;
    arr[0] = true;
    arr[1] = 123;

    arr.append(1.23);
    arr.append("hello world");

    cout << arr.str() << endl;

    bool b = arr[0];
    int i = arr[1];
    double d = arr[2];
    string s = arr[3];
    arr.clear();
}

void test_object(){
    Json obj;

    obj["bool"] = true;
    obj["int"] = 23;
    obj["double"] = 1.23;
    obj["str"] = "hello world";

    cout << obj.has("int") << endl;
    obj.remove("int");
    cout << obj.has("int") << endl;
    cout << obj.str() << endl;
    obj.clear();
}

void test_array_it(){
    Json arr;
    arr[0] = true;
    arr[1] = 123;

    arr.append(1.23);
    arr.append("hello world");

    cout << arr.has(1) << endl;
    arr.remove(1);
    for(auto it=arr.begin();it!=arr.end();it++)
    {
        cout << (*it).str() << endl;
    }
    arr.clear();
}

void test_object_array(){
    Json arr;
    arr[0] = true;
    arr[1] = 123;

    arr.append(1.23);
    arr.append("hello world");

    Json obj;

    obj["bool"] = true;
    obj["int"] = 23;
    obj["double"] = 1.23;
    obj["arr"] = arr;

    //arr.clear(); ����ͷ������飬��������⣬ǳ����
    cout << obj.str() << endl;
    obj.clear();
    //arr.clear(); ����ظ��ͷ�Ҳ������⣬ǳ����
}
void test_parser(){
//    const string &str_null = "null";
    Json v;
//    v.parse(str_null);
//
//    const string &str_bool = "false";
//    v.parse(str_bool);
//    cout << v.str() << endl;
//
//    const string &str_int = "-2333";
//    v.parse(str_int);
//    cout << v.str() << endl;
//
//    const string &str_double = "-2333.33";
//    v.parse(str_double);
//    cout << v.str() << endl;
//
//    const string &str_string = "\"hello world\"";
//    v.parse(str_string);
//    cout << v.str() << endl;
//
//    const string &str_array = "[true,111,323,\"dasd\",32.33,null]";
//    v.parse(str_array);
//    cout << v.str() << endl;

    const string &str_object = "{\"a\": 1,\"b\": 2,\"c\": 5}";
    v.parse(str_object);
    cout << v.str() << endl;

}

const char *FILE_NAME = "cJSON/test.json";

void test_json(){
    fstream fin(FILE_NAME);
    stringstream ss;
    ss << fin.rdbuf();
    const string &str = ss.str();

    Json v;
    v.parse(str);
    cout << v.str() << endl;

    int age = v["age"];
    cout << age << endl;

    string interest = v["interest"]["basketball"];
    cout << interest << endl;

    string color = v["color"][0];
    cout << color << endl;

    string like_game = v["like"][0]["game"];
    cout << like_game << endl;

    string language = v["languages"]["serialOne"]["language"];
    cout << language << endl;

    bool vip = v["vip"];
    cout << vip << endl;

}
using namespace  std::chrono;

void test_time(){
    auto start = high_resolution_clock::now();
    test_json();
    auto end = high_resolution_clock::now();
    duration<double> diff = end - start;
    cout << "time: " << diff.count() * 1000<< "ms" << endl;
}

void test_move_copy(){
    fstream fin(FILE_NAME);
    stringstream ss;
    ss << fin.rdbuf();
    const string &str = ss.str();

    Json v;
    v.parse(str);
    cout << v.str() << endl;

    int age = v["age"];
    cout << age << endl;

    string interest = v["interest"]["basketball"];
    cout << interest << endl;

    Json v_copy = v;
    cout << v_copy.str() << endl;
}
int main(int argc, char *argv[]) {
    test_move_copy();
    return 0;
}
