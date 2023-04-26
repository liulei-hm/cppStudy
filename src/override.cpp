//
// Created by liulei on 2022/12/5.
//

#include "override.h"


/*Point Point::operator+(Point p) {
    Point t;
    t.x = this->x + p.x;
    t.y = this->y + p.y;
    return t;
}*/
/***********************二元运算符重载**************************/
ostream& operator<<(ostream &out,Point &p)
{
    cout << "x:" << p.x << " " <<"y:" << p.y << endl;
    return out;
}

Point operator+(Point p1,Point p2) {
    Point t;
    t.x = p1.x + p2.x;
    t.y = p1.y + p2.y;
    return t;
}

Point operator+(int a,Point p1) {
    Point t;
    t.x = p1.x;
    t.y = p1.y + a;
    return t;
}
Point operator+(Point p1,int a) {
    Point t;
    t.x = p1.x;
    t.y = p1.y + a;
    return t;
}
/***********************一元运算符重载**************************/
Point Point::operator++() {
    this->x++;
    this->y++;
    return *this;
}
//这里加入参(鸡肋)主要是为了和上面的函数区分
Point Point::operator++(int d) {
    Point t = *this; //把++之前的对象给t
    this->x++;
    this->y++;
    //要返回增加之前的对象才满足p++的特性
    return t;
}


void Point::setX(int x) {
    Point::x = x;
}

int Point::getY() const {
    return y;
}

void Point::setY(int y) {
    Point::y = y;
}

int Point::getX() const {
    return x;
}
struct G
{
    virtual void func(int);
};

struct H: G
{
    void func(int) override;
};


int main(){
    Point point1(3,2);
    point1++;
    return 0;
}

