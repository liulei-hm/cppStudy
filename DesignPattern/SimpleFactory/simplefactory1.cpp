//
// Created by liulei on 2023/3/23.
//
#include "all.h"

typedef enum productType {
    TypeA,
    TypeB,
    TypeC
} productTypeTag;//���ֻ��һ��˵����ǩ

class Product {
public:
    virtual void getName() = 0; //���麯��
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
    //Product *a = new Product(); //�������޷�ʵ����
    Product *pro = Factory::createProduct(TypeA);
    pro->getName();
    return 0;
}

