//
// Created by liulei on 2023/3/10.
//
#include "all.h"
//��Ԫ���е����ԣ�B��A�����ѣ�B���Է���A��˽�г�Ա����A���ܷ���B��˽�г�Ա��
//��Ԫ�����д����ԣ�B��A�����ѣ�A��C�����ѣ�B����C�����ѣ���B���ܷ���C��˽�г�Ա
//��Ԫ��������public����private����
//Diver��Car����Ԫ�࣬����ͨ��ModifyCar��Car�ļ۸�����޸�
//originPriceCount������Boss��Diver����Ԫ���������Ի�ȡ˾����boss����ԭʼ�ܼ�
class Driver;
class Car
{
public:
    explicit Car(int price) : price(price) , name("weilai") {}
    int getPrice() const {
        return price;
    }

private:
    int price;
    string name = "byd";
    friend class Driver;  //���� Driver Ϊ��Ԫ��
};

class Boss
{
public:
    Boss(const Car &car) : car(car) {}

    void setOriginCarPrice(int originCarPrice) {
        origin_car_price = originCarPrice;
    }
    friend int originPriceCount(Boss boss, Driver driver);
    Car car;
private:
    int origin_car_price=0; //����ԭʼ�۸�
};

class Driver
{
public:
    Car *bossCar;
    Car myCar;

    Driver(Car *bossCar, const Car &myCar) : bossCar(bossCar), myCar(myCar) {}

    void ModifyCar()  //��װ����
    {
        bossCar->price += 1000;  //��Driver��Car����Ԫ�࣬�ʴ˴����Է�����˽�г�Ա
        myCar.price +=3000;
    }

    void setOriginCarPrice(int originCarPrice) {
        origin_car_price = originCarPrice;
    }
    friend int originPriceCount(Boss boss, Driver driver);
private:
    int origin_car_price=0; //����ԭʼ�۸�
};

int originPriceCount(Boss boss, Driver driver) {
    return boss.origin_car_price+driver.origin_car_price;
}


//����Щ��������ֵ�������ϰ�ĳ���˾��
void allocateCar(Boss &boss,int boss_car_price,Driver &driver,int driver_car_price){
    Car bossCar(boss_car_price);
    boss.car = bossCar;
    boss.setOriginCarPrice(boss_car_price);

    Car myCar(driver_car_price);
    driver.myCar = myCar;
    driver.bossCar = &boss.car;
    driver.setOriginCarPrice(driver_car_price);

}
int main(){
    Boss boss(Car(0));
    Driver driver = Driver(nullptr, Car(0));

    allocateCar(boss,8000,driver,4000);
    driver.ModifyCar();
    cout << driver.myCar.getPrice() << endl;    //7000
    cout << driver.bossCar->getPrice() << endl; //9000
    cout << boss.car.getPrice() << endl;        //9000

    cout << "originPrice:" <<originPriceCount(boss,driver) << endl; //12000

    return 0;
}