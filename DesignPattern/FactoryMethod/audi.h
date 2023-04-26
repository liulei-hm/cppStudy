//
// Created by liulei on 2023/4/25.
//

#ifndef CPPTHING_AUDI_H
#define CPPTHING_AUDI_H
#include <string>
#include <iostream>
#include "car.h"
class Audi : public Car {
public:
    Audi(std::string name_) : Car(name_) {}

    void show() {
        std::cout << "got an Audi car:" << name << std::endl;
    }
};
#endif //CPPTHING_AUDI_H
