//
// Created by liulei on 2023/4/25.
//

#ifndef CPPTHING_BMWFACTORY_H
#define CPPTHING_BMWFACTORY_H
#include "car.h"
#include "factory.h"
#include "bmw.h"

// 宝马汽车工厂，负责生产宝马汽车
class BmwFac : public Factory {
public:
    Car *createCar(std::string name) {
        return new Bmw(name);
    }
};


#endif //CPPTHING_BMWFACTORY_H
