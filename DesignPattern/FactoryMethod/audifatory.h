//
// Created by liulei on 2023/4/25.
//

#ifndef CPPTHING_AUDIFATORY_H
#define CPPTHING_AUDIFATORY_H
#include "car.h"
// 奥迪汽车工厂，负责生产奥迪汽车
class AudiFac : public Factory {
public:
    Car *createCar(string name) {
        return new Audi(name);
    }
};

#endif //CPPTHING_AUDIFATORY_H
