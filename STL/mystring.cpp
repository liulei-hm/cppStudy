//
// Created by liulei on 2023/2/26.
//
#include "all.h"
//https://haicoder.net/cpp/cpp-string-find.html


void io(){
    string str1;

    //  ���������
    cout << "�����ַ��� str1:" << endl;
    cin >> str1;
    getchar();
    cout << "str1 is " << str1  << endl;

    //  һ���ж�ȡ
    cout << "�����ַ��� str1:" << endl;
    getline( cin, str1 );//����һ���ַ���string
    cout << "str1 is " << str1 << endl;

    //  �� c�ַ�ת��
    string str2("Hello World!"), str3;
    char   str4[50];

    cout << "���� C �ַ���" << endl;
    scanf("%s",str4);
    str3 = str4;//string str3;  char str4[50]  str3 = str4;  (char[] -->string )

    cout << "str2 is " << str2 << endl;
    cout << "str3 is " << str3 << endl ;

    // char to string ֱ�Ӹ�ֵ
    string str5;
    char a='f';
    str5 = a;
    str5 += a;
    str5.push_back(a);
    cout << "str5:" << str5 << endl;
    a = 's';
    // char to string ����stream
    stringstream sstream;
    sstream << a;
    sstream >> str5 ;  //str5 = sstream.str5()
    // char to string ��乹�캯��
    string str6(1,a);
    str6.push_back(a);

    //  ת���� c_�ַ���  (string -->char [])
    string str15= "Hello World";
    char str16[10];
    strcpy(str16,str15.c_str());//char *strcpy(char* dest, const char *src);
    printf("%s\n", str16 );
}
int main()
{
    //https://blog.csdn.net/nirendao/article/details/111825421
    //io();
    // append �� +
    string str9= "ab";
    str9 = str9 + "cd";
    str9.append("ef");
    cout << str9 << endl;
    cout << "�ַ���str9�ĳ���Ϊ:" << str9.size() << endl;

    // substr �Ӵ���ȡ
    string str6="abcdefg";
    cout << "�ַ���str6:" << str6.substr(0,3) << endl;

    //  �Ƚ������ַ��� string  �Ƚ�(ֱ�� ��С��)����ͬ c�ַ����ȽϹ���
    string str7="abcgg", str8="abd";
    if( str7 < str8 )
        cout << str7 << "  С�� " << str8 << endl;
    else if( str7 > str8 )
        cout << str7 << "  ���� " << str8 << endl;
    else
        cout << str7 << "  ���� " << str8 << endl;

    // find�Ƿ�����Ӵ� �����򷵻��Ӵ���Ŀ�괮�е�һ�γ��ֵ�λ��
    string str12= "I am a student", str13= "student", str14= "aaaaaaa";
    if( str12.find( str13 )!= -1 )
        cout << "Find " << str13  << " at:" << str12.find( str13 ) << endl;
    if( str12.find( str14 )== -1 )
        cout << "Not Find  " << str14 << endl;

    // replace �滻��startpos��ʼ��n1���ַ�Ϊs
    string str15 = "abcdefgh";
    int startpos = 3;
    str15.replace(startpos, 1, "000");
    cout << "str15:"<<str15<<endl;

    //copy
    char buf[128];
    string str16 = "abcdefgh";
    str16.copy(buf,3,3);
    cout << "buf:" << buf[0] << buf[1] << buf[2] << endl;


    //erase  string.erase(pos,n)ɾ����pos��ʼ��n���ַ� string.erase(pos) //ɾ��pos����һ���ַ���pos��string���͵ĵ�������

    string str17 = "abcaeagh";
    string::iterator it = str17.begin();
    while (it != str17.end())
    {
        if(*it=='a')
        {
            it=str17.erase(it);//ɾ�����������itҲɾ������erase�����᷵����һ��������λ��
        }else it++;
    }
    str17.erase(str17.begin()+3);
    cout << "str17:"<<str17<<endl;

    string str18;
    str18 = "123456";
    cout << str18 << endl;

    //����һ��ʹ��substr()
    str18 = str18.substr(0, str18.length() - 1);
    cout << str18 << endl;

    //��������ʹ��erase()
    str18.erase(str18.end() - 1);
    cout << str18 << endl;

    //��������ʹ��pop_back()
    str18.pop_back();
    cout << str18 << endl;

    //�ַ����жϿ�str.empty(),str.length()==0,str.size()==0,str==""
}