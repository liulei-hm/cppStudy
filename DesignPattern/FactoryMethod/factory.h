//
// Created by liulei on 2023/4/25.
//

#ifndef CPPTHING_FACTORY_H
#define CPPTHING_FACTORY_H
#include <iostream>
#include "car.h"

// 基类（包含纯虚函数，不能实例化对象）
class Factory {
public:
    virtual Car *createCar(std::string name) = 0;
};


#endif //CPPTHING_FACTORY_H
