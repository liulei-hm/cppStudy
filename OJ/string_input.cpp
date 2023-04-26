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
    //输出
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
    while(ss >> word) { //每次输出一个单词到word
        words.push_back(word);
    }
    //输出
    cout << "-----splitString_istringstream_begin-----" << endl;
    for(string x : words) {
        cout << x << endl;
    }
    cout << "-----splitString_istringstream_end-----" << endl;
}

//cout << str.rfind(' ') << endl;  //找到最后一个空格的位置
//      cout << isdigit('a');
//      cout << isalpha('4');
//      cout << islower('a');  isupper('a'); s[] =  tolower s[] =  toupper

//大小写互换
void Atoa(){
    char c = getchar();  //获取一个字符
    c = c^32;
    cout << c ;
}


void scanfstring(){
    //scanf读入字符串数组并存入string里
    char str[100];
    std::string s;
    scanf("%s", str); // 读取字符串
    s = str; // 将字符数组转换为字符串
    std::cout << s << std::endl; // 输出字符串

    //sscanf读入字符串转数值
    long n;
    // 转换成整数
    n = strtol(str, nullptr, 10);
    // 输出结果
    printf("The number is %ld\n", n);

    //sscanf读入字符串转数值
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

    // 输出结果
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}