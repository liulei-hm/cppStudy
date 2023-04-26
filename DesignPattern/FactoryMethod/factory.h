//
// Created by liulei on 2023/4/25.
//

#ifndef CPPTHING_FACTORY_H
#define CPPTHING_FACTORY_H
#include <iostream>
#include "car.h"

// ���ࣨ�������麯��������ʵ��������
class Factory {
public:
    virtual Car *createCar(std::string name) = 0;
};


#endif //CPPTHING_FACTORY_H
