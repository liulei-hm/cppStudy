//
// Created by liulei on 2023/4/25.
//

#ifndef CPPTHING_BMW_H
#define CPPTHING_BMW_H
#include <string>
#include <iostream>
#include "car.h"

class Bmw : public Car {
public:
    Bmw(std::string name_) : Car(name_) {}

    void show() {
        std::cout << "got an BMW car:" << name << std::endl;
    }
};

#endif //CPPTHING_BMW_H
