//
// Created by liulei on 2023/3/21.
//

#include "all.h"

void mysplit(string str){
    vector<string> words;
    int j=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==' ')
        {
            words.push_back(str.substr(j,i-j));
            j=i+1;
        }
    }
    words.push_back(str.substr(j,str.size()-j));
    //���
    cout << "-----mysplit_begin-----" << endl;
    for(string x : words) {
        cout << x << endl;
    }
    cout << "-----mysplit_end-----" << endl;
}

void splitString_strtok(string &str)
{
    char* s = new char[str.size() + 1];
    strcpy(s, str.c_str());
    char* p = strtok(s, " ");
    vector<string> words;
    while(p) {
        words.push_back(p);
        p = strtok(NULL, " ");
    }
    cout << "-----splitString_strtok_begin-----" << endl;
    for(string x : words) {
        cout << x << endl;
    }
    cout << "-----splitString_strtok_end-----" << endl;
}

void splitString_istringstream(string &str){
    istringstream ss(str);
    vector<string> words;
    string word;
    while(ss >> word) { //ÿ�����һ�����ʵ�word
        words.push_back(word);
    }
    //���
    cout << "-----splitString_istringstream_begin-----" << endl;
    for(string x : words) {
        cout << x << endl;
    }
    cout << "-----splitString_istringstream_end-----" << endl;
}

//cout << str.rfind(' ') << endl;  //�ҵ����һ���ո��λ��
//      cout << isdigit('a');
//      cout << isalpha('4');
//      cout << islower('a');  isupper('a'); s[] =  tolower s[] =  toupper

//��Сд����
void Atoa(){
    char c = getchar();  //��ȡһ���ַ�
    c = c^32;
    cout << c ;
}


void scanfstring(){
    //scanf�����ַ������鲢����string��
    char str[100];
    std::string s;
    scanf("%s", str); // ��ȡ�ַ���
    s = str; // ���ַ�����ת��Ϊ�ַ���
    std::cout << s << std::endl; // ����ַ���

    //sscanf�����ַ���ת��ֵ
    long n;
    // ת��������
    n = strtol(str, nullptr, 10);
    // ������
    printf("The number is %ld\n", n);

    //sscanf�����ַ���ת��ֵ
    char str1[] = "123";
    int num;
    sscanf(str1, "%d", &num);
    printf("%d\n", num);

}


vector<int> parseIntArray(string str) {
    vector<int> nums;
    size_t start = 1, end = 1;
    while (start < str.size()) {
        end = str.find(",", start);
        if(end==string::npos){
            end = str.find("]", start);
        }
        string numStr = str.substr(start, end - start);
        start = end + 1;
        if (numStr == "null") {
            nums.push_back(-1);
        } else {
            cout << numStr << endl;
            nums.push_back(stoi(numStr));
        }
    }
    return nums;
}


int main() {
//    string str;
//    getline(cin,str);  //hhh sss dsa weweea
//
//    splitString_istringstream(str);
    //scanfstring();

    string str = "[1,2,3,null,null,4,5]";
    vector<int> nums = parseIntArray(str);

    // ������
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}