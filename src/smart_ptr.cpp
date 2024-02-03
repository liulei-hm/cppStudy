//
// Created by liulei on 2023/4/14.
//
#include "all.h"
//1��auto_ptrһ�㲻��ʹ�ã���c++98�汾�����ṩ������ָ�룬��ָ�������ߵ������ȡ�Ĵ�ʩ�ǹ���Ȩת�Ƶ�˼�룬
//Ҳ����ԭ���󿽱����¶����ʱ��ԭ����ͻᱻ����Ϊnullptr����ʱ��ֻ���¶���ָ��һ����Դ�ռ䡣

//2��unique_ptr��c++11�汾�����ṩ������ָ��,��ֱ�ӽ��������캯���͸�ֵ���غ���������(��Ϊprivate��=delete)������ˣ���������п����͸�ֵ��
//unique_ptr ֮���Խ�������֣�����Ϊ��ֻ��ָ��һ�����󣬼�����ָ����������ʱ��֮ǰ��ָ��Ķ���ᱻ�ݻ١�
//��Σ��� unique_ptr ����������ʱ��ָ��Ķ���Ҳ�ᱻ�Զ��ݻ٣���������Աʵ�����Զ��ͷŵĹ��ܡ�

//3��ΪʲôҪ���ÿ������캯����
//(1)ǳ�������⣬Ҳ���������ᵽ�Ķ���������
//(2)�Զ����˻����������Ŀ������캯��������������󿽱�ʱ��������������Ŀ�����û�е����Զ���Ļ��࿽�����ǵ���Ĭ�ϵĻ��࿽����
//����������ɲ���ȫ��������ֶ�����������ʱ����Ϊ������������Զ���Ļ������������Ĭ�ϵ�ǳ������

//4��share_ptr��c++11�汾���е�����ָ�룬shared_ptr����������ָ�����ָ��ͬһ����Դ�������ܹ���֤�������Դֻ�ᱻ�ͷ�һ�Σ����򲻻��������
//���õ������ü���ԭ����ʵ�ֶ��shared_ptr����֮�乲����Դ��
//(1)shared_ptr���ڲ���ά����һ�����ü�����������¼�÷���Դ������������
//(2)��һ��shared_ptr��������ʱ���������������������������ھͻὫ�ü�����1��
//(3)������ü�����Ϊ0�����ʾ�Լ������һ��ʹ�ø���Դ��shared_ptr���󣬱����ͷ���Դ��
//(4)������ü�������0����˵���Լ���������������ʹ�ã������ͷŸ���Դ��������������ͳ�ΪҰָ�롣
//(5)���ü�����������¼��Դ�������ж��ٸ�ָ��ָ�����Դ����

//5��shared_ptr������
//(1)�ǻ������ݽṹ��û�����⣬�����ڻ��νṹ�У����������г���ѭ���������⡣
//(2)�ӳ��˶�����������ڣ���������һ����������ʵҲδ�ܴﵽ�ͷ��ڴ��Ч��

//6��weak_ptr����ָ��shared_ptr�����Ҳ���ı�shared_ptr�����ü�����һ�����һ��shared_ptr������ʱ������ͻᱻ�ͷš����ڽ��ѭ����������
//share_ptr��ѭ������https://blog.csdn.net/sjp11/article/details/123899141
//���磺��˫�������нڵ�Ҳ����Ϊshare_ptrʱ�������pre��next��ѭ�����ã�����������ü�������Ϊ0���޷��ͷ�ָ��Ķ���,��weak_ptr.cpp
struct ListNode{
    weak_ptr<ListNode> next;
    weak_ptr<ListNode> pre;
};
//ʹ��weakptr���ʶ�����Ҫ��lock�Ȼ�ȡһ����ʱ��shared_ptr
//if (auto sptr = wptr.lock()) {
//    // ʹ�� shared_ptr ���ʶ���
//    std::cout << "Object value: " << sptr->value << std::endl;
//} else {
//    // weak_ptr ָ��Ķ����Ѿ����ͷ�
//    std::cout << "Object has been deleted" << std::endl;
//}

class A
{
public:
    int *p;
    A()
    {
        p=new int(4);
        cout << "A default constructor" << endl;
    };
    ~A()
    {
        delete p;
        cout << "A destructor" << endl;
    };
};

void test_unique_ptr(){
    //�����ʼ��
    unique_ptr<int> up1(new int(8)); // ����һ��ָ��int�Ͷ����ָ�룬ɾ����ȱʡΪdelete
    unique_ptr<int[]> up2(new int[10]); // ָ��һ��10��Ԫ�ص�int�����飬ɾ����ȱʡΪdelete[]

    //make_unique��ʼ����c++14
    unique_ptr<double> up3 = make_unique<double>(1.88);    //unptr2��ָ��һ��double�Ͷ���valΪ1.88��unique_ptr����ָ��
    auto up4 = make_unique<float>(1.98f);    //unptr4��ָ��һ��float�Ͷ���valΪ1.98f��unique_ptr����ָ��

    unique_ptr<string> ptr1 = make_unique<string>("I Love China!");
    cout << "*ptr1 = "<< *ptr1 << endl;
    //�������д��붼�Ǵ���ģ���Ϊunique_ptr��֧����Щ�����͸�ֵ�����ָ��Ĳ�����
    //unique_ptr<string> ptr2(ptr1);
    //unique_ptr<string> ptr3 = ptr1;
    //unique_ptr<string> ptr4;
    //ptr4 = ptr1;

    {
        unique_ptr<A> pA = make_unique<A>();
    }//����ָ�������򣬶����Զ��ͷ�

    unique_ptr<string> ptr2(std::move(ptr1));
    //cout << "*ptr1" << *ptr1 << endl; //���������캯����ptr1���ڴ����Ȩ���ƶ�������������ptr2
    cout << "*ptr2 = " << *ptr2 << endl;

}

void test_share_ptr(){
    {
        shared_ptr<A> pB;
        {
            shared_ptr<A> pA = make_unique<A>();
            pB = pA;
            cout << pA.get() << endl;  //����ָ��ָ��ĵ�ַ��ͬ
            cout << pB.get() << endl;  //����ָ��ָ��ĵ�ַ��ͬ
            cout << "���ü�����" << pB.use_count() << endl;
        } //��һ��shared_ptr��������ʱ���������������������������ھͻὫ�ü�����1
        cout << "���ü�����" << pB.use_count() << endl;
    }//�������������ü�����Ϊ0�������Զ��ͷ�
}
int main(){
    //test_share_ptr();
    int a = 4;
    int &&c = std::move(a); // ok
    cout << a;
    return 0;
}