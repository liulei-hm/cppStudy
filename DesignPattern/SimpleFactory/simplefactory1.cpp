//
// Created by liulei on 2023/3/23.
//
#include "all.h"

typedef enum productType {
    TypeA,
    TypeB,
    TypeC
} productTypeTag;//这个只是一个说明标签

class Product {
public:
    virtual void getName() = 0; //纯虚函数
};

class ProductA :public Product {
public:
    void getName() override {
        cout << "ProductA" << endl;
    }
};

class ProductB :public Product {
public:
    void getName() override {
        cout << "ProductB" << endl;
    }
};

class ProductC :public Product {
public:
    void getName() override {
        cout << "ProductC" << endl;
    }
};

class Factory {

public:
    static Product* createProduct(productType type) {
        switch (type) {
            case TypeA:
                return new ProductA();
            case TypeB:
                return new ProductB();
            case TypeC:
                return new ProductC();
            default:
                return nullptr;
        }
    }
};


int main()
{
    //Product *a = new Product(); //纯虚类无法实例化
    Product *pro = Factory::createProduct(TypeA);
    pro->getName();
    return 0;
}

