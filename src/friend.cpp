//
// Created by liulei on 2023/3/10.
//
#include "all.h"
//友元具有单向性，B是A的朋友，B可以访问A的私有成员，但A不能访问B的私有成员。
//友元不具有传递性，B是A的朋友，A是C的朋友，B不上C的朋友，即B不能访问C的私有成员
//友元函数放在public或者private均可
//Diver是Car的友元类，可以通过ModifyCar对Car的价格进行修改
//originPriceCount函数是Boss和Diver的友元函数，可以获取司机和boss车的原始总价
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
    friend class Driver;  //声明 Driver 为友元类
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
    int origin_car_price=0; //汽车原始价格
};

class Driver
{
public:
    Car *bossCar;
    Car myCar;

    Driver(Car *bossCar, const Car &myCar) : bossCar(bossCar), myCar(myCar) {}

    void ModifyCar()  //改装汽车
    {
        bossCar->price += 1000;  //因Driver是Car的友元类，故此处可以访问其私有成员
        myCar.price +=3000;
    }

    void setOriginCarPrice(int originCarPrice) {
        origin_car_price = originCarPrice;
    }
    friend int originPriceCount(Boss boss, Driver driver);
private:
    int origin_car_price=0; //汽车原始价格
};

int originPriceCount(Boss boss, Driver driver) {
    return boss.origin_car_price+driver.origin_car_price;
}


//给这些车辆赋初值，分配老板的车给司机
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