//
// Created by liulei on 2023/3/16.
//
#include "all.h"
#include "car.h"
#include "factory.h"
#include "bmwfactory.h"
#include "audifatory.h"


int main() {
    unique_ptr<Factory> bmwfty(new BmwFac());
    unique_ptr<Factory> audifty(new AudiFac());
    unique_ptr<Car> p1(bmwfty->createCar("X6"));
    unique_ptr<Car> p2(audifty->createCar("A8"));
    p1->show();
    p2->show();

    unique_ptr<Car> audiR8((new AudiFac)->createCar("R8"));
    audiR8->show();
    return 0;
}



