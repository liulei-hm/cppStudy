//
// Created by liulei on 2022/12/5.
//

#ifndef CPPTHING_OVERRIDE_H
#define CPPTHING_OVERRIDE_H
#include <iostream>
using namespace std;
class Point{
private:
    int x;
    int y;
public:
    Point(int a=0,int b=0){x=a;y=b;};

    friend ostream& operator<<(ostream &out,Point &p);
    friend Point operator+(int a,Point p1);
    friend Point operator+(Point p1,Point p2);
    friend Point operator+(Point p1,int a);
    //Point operator+(Point p);

    Point operator++();
    Point operator++(int d);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);
};
#endif //CPPTHING_OVERRIDE_H
