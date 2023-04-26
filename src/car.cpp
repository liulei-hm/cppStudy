//
// Created by liulei on 2022/12/3.
//

#include <iostream>
using namespace std;
class car {
public:
    car(int price, int num) : price(price), num(num) {}

    int getPrice() const {
        return price;
    }

    void setPrice(int price) {
        car::price = price;
    }

    int getNum() const {
        return num;
    }

    void setNum(int num) {
        car::num = num;
    }
    void show() const;
private:
    int price;
    int num;
};

class racecar : car{
public:
    racecar(int price, int num, int place, int color) : car(price, num), place(place), color(color) {}
    void show() const;
public:

private:
    int place;
    int color;
};

void car::show() const{
    cout << "价格：" << price << "数量：" << num << endl;
}

void racecar::show() const {
    car::show();
}
