//
// Created by liulei on 2023/4/13.
//
#include "all.h"

using namespace std;

/* ��ֵ����ʾ��Ѱַ���Ǳ������ڴ��У�����ȷ�е�ַ������ȡ��ַ�����з��ʣ��޸ĵȲ����ı��ʽ(����)��
 *      ����ȡ��ַ&��ֵ�������a,�ַ�������"hello",++x,
 *
 * ��ֵ����ʾ�ɶ�����Ѱַ���Ǳ������ڴ��У����߼Ĵ����У���֪��Ҳ�޷������ȷ�е�ַ���ڵõ�������ʽ���������ٵ���ʱ���ʽ��
 *      ����ȡ��ַ&��ֵ,һ������ٵģ�����ʱ����x++,���ʽa+b
 *
 * ��������ֵΪ��ֵ��������ֵΪָ�����ͻ��������͵Ĳ���ʱ������static��ȫ�ֱ���ʱ����������ֵΪ��ֵ��
 * ��������ֵΪ��ֵ��������ֵΪ�����ڲ�����ľֲ�����ʱ����������ֵΪ��ֵ����Ϊ�����ڲ��ñ����ѱ����١�
 *
 * ��ֵ����(����ֵ������)��&a=b  ������ֵ���ã�const &a=1
 * ��ֵ����(����ֵ������)��int &&b = 3 + 4 ; ��ʾ�������ڵ���û���ڵ�ֵ���ƶ�����c++11
 *         ��Ҫ�����ǽ�����������Ϊ��������ֵ����ʱ����ȿ������⣬�Լ������֮��Ŀ��ٸ���
 *
 * https://zhuanlan.zhihu.com/p/598564624
 * �ƶ�����:std::move()   int a;//��ֵ   int &&b = std::move(a);
 *  move�����ǿ��Խ�һ����ֵת������ֵ���ã��Ӷ����Ե���C++11�Ŀ������캯����
 *  ������C++11�е��ƶ����캯�����������ֵ���ã���˵�������ֵʱ���޷����ø��ƶ����캯������Ҫ����move����ֵת������ֵ���á�
 *
 * ����ת��std::forward()
 *  ����ת����ָ�ں���ģ���У���ȫ����ģ��Ĳ������ͣ����������ݸ���ǰ����ģ���е�����һ��������
 *  ��ˣ�Ϊ��ʵ������ת��������ʹ����������֮�⣬��Ҫ�õ�std::forward��C++11�������ڴ��εĹ����б��������ԭ���������ԡ�
 *  ������ֵ�����ڴ��ݹ����о��ܹ�������ֵ�����ԡ�
 *  ֻҪ����ֵ���ã��ɵ�ǰ�����ٴ��ݸ������������ã�Ҫ������ֵ���ԣ�����ʵ������ת����
 *
 *https://blog.csdn.net/m0_59938453/article/details/125858335?spm=1001.2101.3001.6650.12&utm_medium=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-12-125858335-blog-114479140.pc_relevant_3mothn_strategy_and_data_recovery&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~CTRLIST~Rate-12-125858335-blog-114479140.pc_relevant_3mothn_strategy_and_data_recovery&utm_relevant_index=16
 * */

void test_yinyong(){
    //int &a = 1;//����1����ֵ��a����ֵ���ã��޷�ֱ�ӳ�ʼ������Ҫ����ֵ��ʼ����
    int b = 1; //��ȷ��b����ֵ������ֵ���ã����Ա���ֵ��
    int const &c = 1;//��ȷ��c�ǳ�����ֵ���ã���ֵ���԰󶨵�����ֵ���ã�
    int &&d = 1;//��ȷ������C++11�е���ֵ���ã�dΪ��ֵ��
}
class Move_Copy
{
public:
    int *p;
    std::map<string,Move_Copy> *m_object;
    std::vector<int> v;
    Move_Copy()
    {
        p=new int;
        *p = 0;
        m_object = new std::map<string,Move_Copy>();
        cout << " default constructor" << endl;
    };
    Move_Copy(const Move_Copy &other)
    {
        p = new int;
        m_object = new std::map<string,Move_Copy>(*(other.m_object));
        *(p) = *(other.p);//Ϊ��������µ��ڴ棬��ʹ��Դ�����е�ֵ�������¹���
        v = other.v;   //�������
        cout << " copy constructor" << endl;
    }

    Move_Copy(Move_Copy &&other)  noexcept // �ƶ����캯������������ֵ����
    {
        p = other.p; // ֱ�Ӵ���ֵ�����С�͵ȡ����Դ
        other.p = nullptr; //����ֵ�����е���Դָ����Ϊ��ָ�룬�����ظ��ͷ��ڴ�
        m_object = other.m_object;
        other.m_object = nullptr;
        v = std::move(other.v);
        cout << " move constructor" << endl;
    }

    Move_Copy &operator[](const string &key){
        return (*m_object)[key];
    };

    //�ڶ�һ���Ѿ����ڵĶ�����и�ֵ����ʱ�����������Զ�Ϊ�ö������Ĭ�ϵĿ�����ֵ�������copy assignment operator������������Ὣ�Ҳ�����ֵ���Ƶ��������С�
    //�ص㣺���ǣ����һ���ඨ�����ƶ����캯�����ƶ���ֵ���������ô�������Ͳ����Զ�����Ĭ�ϵĿ������캯���Ϳ�����ֵ������ˣ��ͻ�ɾ�����ǣ���Ҫ�ֶ��ṩ��
    Move_Copy& operator=(const Move_Copy& other) {
        if (this != &other) {
            delete p;
            delete m_object;
            p = new int(*other.p);
            m_object = new std::map<string, Move_Copy>(*other.m_object);
            //����һ��vector���и�ֵ����ʱ��vector�ĸ�ֵ���������������vector�����ݣ�Ȼ���ұ�vector�����ݸ��Ƶ���ߡ�
            //��Ҳ��ζ���ڽ���vector�ĸ�ֵ����ʱ�����vector�������ᱻ�ͷţ���˿��Խ����vector���������ã�������Ҫ���·����ڴ�
            v = other.v;  //ֱ�Ӹ�ֵ����
        }
        cout << " operator = copy assignment constructor" << endl;
        return *this;
    }
    Move_Copy& operator=(Move_Copy &&other)  noexcept {
        if (this != &other) {
            delete p;
            delete m_object;
            p = other.p; // ֱ�Ӵ���ֵ�����С�͵ȡ����Դ
            other.p = nullptr; // ����ֵ�����е���Դָ����Ϊ��ָ�룬�����ظ��ͷ��ڴ�
            m_object = other.m_object;
            other.m_object = nullptr;
            v = other.v;
            cout << " operator = move assignment constructor" << endl;
        }
        return *this;
    }

    ~Move_Copy()
    {
        delete p;
        delete m_object;
        //Ϊʲôû��v?�ڶ�������ʱ��C++ ���Զ����ö����ڲ���Ա�������������������� std::vector ���͵ĳ�Ա�������������������Զ��������ڲ�������ڴ档
        //��ˣ�����Ҫ�ڶ���������������ֶ���� std::vector �ڲ������ݣ���Ϊ�������������Զ�����
    };
};

void test_copy(){
    /**�������캯�� ��� ****/
    Move_Copy t1;
    Move_Copy t2(t1);
    Move_Copy t3 = t1;

    /**�ƶ����캯�� �ٶȸ��� ****/
    //��C++11�У�������ʹ����ֵ������Ϊ���캯���Ĳ���ʱ�����������Զ�ѡ���ƶ����캯��������������ʽ��ָ��ʹ���ƶ����캯�������������Զ������жϡ�
    Move_Copy t4 = std::move(t1);  //�����ƶ����캯���������=�ţ���ʵ��ʵ���Ͽ�����ʼ����copy initialization����һ����ʽ�����Ǹ�ֵ����
    Move_Copy t5;
    t5 = std::move(t4);            //�����ƶ������=����������ʱ�Ѿ����ǳ�ʼ���������޷������ƶ����캯��
}

Move_Copy fun(){
    Move_Copy a;
    *a.p = 4;
    return a;
}
void test_func(){
    /* t6�Ĺ���ʹ�����ƶ����캯�����ں���fun()�У�a��һ���ֲ��������������������ʱ�������١�
    ����������ʱ��������������һ����ʱ����ֵ���󣬲����ֲ�����a����Դת�Ƹ������ʱ����ֵ����
    ����ʱ��ֵ���󱻷��ص����õ�ʱ����������ʹ���ƶ����캯��������ʱ��ֵ�������Դ�ƶ���t6�����С�**/
    Move_Copy t6 = fun();
    cout << *t6.p << endl; //4
    /*Ϊʲôû�д�ӡ��move constructor������Ϊ�ڸó����У�fun()�������ص�Move_Copy����ᱻֱ�Ӹ�ֵ��t6����˱���������з���ֵ�Ż���Return Value Optimization, RVO����
     * ֱ�ӽ�a��������t6������ڴ�ռ��У������ǽ�a�����ȹ���������ƶ����쵽t6�����С��������Ա������Ķ�������ƶ���������ߴ����ִ��Ч�ʡ�
     * ��Ϊû�н����ƶ����죬���Գ����в�û�д�ӡ"move constructor"��*/
}

/**���캯�����õļ��ֳ���
 *  Example obj1(5);    // ����һ�� Example ���͵Ķ��󣬵��ù��캯��
    Example obj2 = 10;  // ����һ�� Example ���͵Ķ��󣬵��ù��캯��
    Example *obj3 = new Example(15);  // ��̬����һ�� Example ���͵Ķ��󣬵��ù��캯��
    Example ex1; // ����Ĭ�Ϲ��캯��
    Example ex2 = ex1; // ���ÿ������캯��
    Example ex3(ex1); // ���ÿ������캯��
    Example ex4; // ����Ĭ�Ϲ��캯��
    ex4 = ex1; // ���ÿ�����ֵ���������
    Example ex3 = std::move(ex1); // ��ʼ��ʱ�������ƶ����캯��
    ex2 = ex3; // ���ÿ�����ֵ���������
    ex2 = std::move(ex3); // �����ƶ���ֵ���������
 * */
void func(Move_Copy &t1){
    cout << "��ֵ����" << endl;
}
void func(Move_Copy &&t1){
    cout << "��ֵ����" << endl;
}
//��ֵ���ñ�����ʵ����ֵ
void test_Rightyinyong(Move_Copy &&t1){
    //func(std::forward<Move_Copy>(t1));
    func(t1);
}

//����ʱ�����cmake�йرձ������Ż�
int main(){
    Move_Copy t1;
    test_Rightyinyong(std::move(t1));
    return 0;
}

