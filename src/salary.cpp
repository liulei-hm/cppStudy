//
// Created by liulei on 2023/3/7.
//
//const��*��Ϊ���γ�����ָ��ָ����ǳ���
//const��*�ұ�����ָ�룬��ָ��
//���е�const����ֻ�ܵ���������const����
//Clock(Clock &c);//�������캯��,������ӣ����������Զ�����һ���������캯������˼Ӳ��Ӷ�����ֱ��ʹ�á�
/*
ĳ��˾�о�������Ա��Сʱ���ȶ�����Ա�������ܼ���н������Աÿ�µ�н800Ԫ��
Ȼ���������ɣ�ÿ����1����Ʒ��ȡ���������5%��Сʱ����Сʱ����н��ÿ����Ա�������������֤�ŵ����ݡ�
Ϊ�����⣬�Ѹ�����Ա�Ĺ�����Ϣ����ɻ���Employee��������Ա��̳и���Ĺ��ܡ�
*/
#include <iostream>
#include <string>
using namespace std;
class Employee{
public:
    Employee(string Name ,string id) : name(Name), Id(id){  }
    string getName() const { return name; }			        //��������
    string getID() const { return Id; }			            //�������֤��
    virtual float getSalary() const { return 0.0; }			//����нˮ
    virtual void print() const {		                    //������������֤��
        cout<<"����: "<<name<<"\t\t ���: "<<Id<<endl;
    }
private:
    string name;
    string Id;
};

class Manager:public Employee{
public:
    Manager(string Name,string id,int week):Employee(Name,id){
        WeeklySalary=week*1000;
    }
    float getSalary() const { return WeeklySalary; }	//��ȡ�������н
    void print() const {			                    //��ӡ�������������֤����н
        cout<<"����"<<getName()<<"\t\t ���: "<<getID()
            <<"\t\t �ܹ���: "<<getSalary()<<endl;
    }
private:
    float WeeklySalary;					            //��н
};

class SaleWorker:public Employee{
public:
    SaleWorker(string name,string id,int profit,int x):Employee(name,id){
        workerMoney=baseMoney+x*0.05*profit;
    }
    float getSalary() const {
        return workerMoney;
    }
    void print() const {
        cout<<"����Ա��"<<getName()<<"\t\t ���: "<<getID()
            <<"\t\t �ܹ���: "<<getSalary()<<endl;
    }
private:
    float baseMoney=800.0;
    float workerMoney;
};

class HourWorker:public Employee{
public:
    HourWorker(string name,string id,int h):Employee(name,id){
        TotalMoney=h*hourMoney;
    }
    float getSalary() const {
        return TotalMoney;
    }
    void print() const {
        cout<<"Сʱ����"<<getName()<<"\t\t ���: "<<getID()
            <<"\t\t �ܹ���: "<<getSalary()<<endl;
    }
private:
    float hourMoney=100.0;
    float TotalMoney;
};

int main(){
    cout<<"�����빤���ܣ�";
    int week;
    cin>>week;
    Manager m("С��","11111111",week);
    m.print();
    cout<<"��������������";
    int profit;
    cin>>profit;
    cout<<"���������ۼ�����";
    int x;
    cin>>x;
    SaleWorker s("С��","222222",profit,x);
    s.print();
    cout<<"�����빤��Сʱ��";
    int hour;
    cin>>hour;
    HourWorker h("С��","333333",hour);
    h.print();
    return 0;
}