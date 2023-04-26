//
// Created by liulei on 2023/2/26.
//
#include "all.h"
//https://haicoder.net/cpp/cpp-string-find.html


void io(){
    string str1;

    //  输入与输出
    cout << "输入字符串 str1:" << endl;
    cin >> str1;
    getchar();
    cout << "str1 is " << str1  << endl;

    //  一行行读取
    cout << "输入字符串 str1:" << endl;
    getline( cin, str1 );//读入一行字符串string
    cout << "str1 is " << str1 << endl;

    //  与 c字符转换
    string str2("Hello World!"), str3;
    char   str4[50];

    cout << "输入 C 字符串" << endl;
    scanf("%s",str4);
    str3 = str4;//string str3;  char str4[50]  str3 = str4;  (char[] -->string )

    cout << "str2 is " << str2 << endl;
    cout << "str3 is " << str3 << endl ;

    // char to string 直接赋值
    string str5;
    char a='f';
    str5 = a;
    str5 += a;
    str5.push_back(a);
    cout << "str5:" << str5 << endl;
    a = 's';
    // char to string 利用stream
    stringstream sstream;
    sstream << a;
    sstream >> str5 ;  //str5 = sstream.str5()
    // char to string 填充构造函数
    string str6(1,a);
    str6.push_back(a);

    //  转换成 c_字符串  (string -->char [])
    string str15= "Hello World";
    char str16[10];
    strcpy(str16,str15.c_str());//char *strcpy(char* dest, const char *src);
    printf("%s\n", str16 );
}
int main()
{
    //https://blog.csdn.net/nirendao/article/details/111825421
    //io();
    // append 和 +
    string str9= "ab";
    str9 = str9 + "cd";
    str9.append("ef");
    cout << str9 << endl;
    cout << "字符串str9的长度为:" << str9.size() << endl;

    // substr 子串截取
    string str6="abcdefg";
    cout << "字符串str6:" << str6.substr(0,3) << endl;

    //  比较两个字符串 string  比较(直接 大小于)规则同 c字符串比较规则
    string str7="abcgg", str8="abd";
    if( str7 < str8 )
        cout << str7 << "  小于 " << str8 << endl;
    else if( str7 > str8 )
        cout << str7 << "  大于 " << str8 << endl;
    else
        cout << str7 << "  等于 " << str8 << endl;

    // find是否包含子串 包含则返回子串在目标串中第一次出现的位置
    string str12= "I am a student", str13= "student", str14= "aaaaaaa";
    if( str12.find( str13 )!= -1 )
        cout << "Find " << str13  << " at:" << str12.find( str13 ) << endl;
    if( str12.find( str14 )== -1 )
        cout << "Not Find  " << str14 << endl;

    // replace 替换从startpos开始的n1个字符为s
    string str15 = "abcdefgh";
    int startpos = 3;
    str15.replace(startpos, 1, "000");
    cout << "str15:"<<str15<<endl;

    //copy
    char buf[128];
    string str16 = "abcdefgh";
    str16.copy(buf,3,3);
    cout << "buf:" << buf[0] << buf[1] << buf[2] << endl;


    //erase  string.erase(pos,n)删除从pos开始的n个字符 string.erase(pos) //删除pos处的一个字符（pos是string类型的迭代器）

    string str17 = "abcaeagh";
    string::iterator it = str17.begin();
    while (it != str17.end())
    {
        if(*it=='a')
        {
            it=str17.erase(it);//删除迭代器会把it也删除，但erase函数会返回下一个迭代器位置
        }else it++;
    }
    str17.erase(str17.begin()+3);
    cout << "str17:"<<str17<<endl;

    string str18;
    str18 = "123456";
    cout << str18 << endl;

    //方法一：使用substr()
    str18 = str18.substr(0, str18.length() - 1);
    cout << str18 << endl;

    //方法二：使用erase()
    str18.erase(str18.end() - 1);
    cout << str18 << endl;

    //方法三：使用pop_back()
    str18.pop_back();
    cout << str18 << endl;

    //字符串判断空str.empty(),str.length()==0,str.size()==0,str==""
}