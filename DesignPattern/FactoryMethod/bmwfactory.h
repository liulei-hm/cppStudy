//
// Created by liulei on 2023/4/25.
//

#ifndef CPPTHING_BMWFACTORY_H
#define CPPTHING_BMWFACTORY_H
#include "car.h"
#include "factory.h"
#include "bmw.h"

// ������������������������������
class BmwFac : public Factory {
public:
    Car *createCar(std::string name) {
        return new Bmw(name);
    }
};


#endif //CPPTHING_BMWFACTORY_H
