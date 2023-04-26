//
// Created by liulei on 2023/4/25.
//

#ifndef CPPTHING_CAR_H
#define CPPTHING_CAR_H
#include <string>
#include <utility>

// 系列产品
class Car {
public:
    Car(std::string name_) : name(std::move(name_)) {}

    virtual void show() = 0;

protected:
    std::string name;
};

#endif //CPPTHING_CAR_H
