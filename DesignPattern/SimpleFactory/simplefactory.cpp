//
// Created by liulei on 2023/3/15.
//
#include "all.h"
class Operation{
public:
    virtual double getResult() = 0;

    double _numA;
    double _numB;
};

class OperationADD:public Operation{
private:
    double getResult() override {
        double result = 0;
        result = _numA + _numB;
        return result;
    }
};
class OperationSUB:public Operation{
private:
    double getResult() override {
        double result = 0;
        result = _numA - _numB;
        return result;
    }
};
class OperationMUL:public Operation{
private:
    double getResult() override {
        double result = 0;
        result = _numA * _numB;
        return result;
    }
};
class OperationDIV:public Operation{
private:
    double getResult() override {
        double result = 0;
        try
        {
            if(_numB==0)
                throw "error";
            result = _numA / _numB;
        }
        catch(char *str)
        {
            cout << str << endl;
        }
        return result;
    }
};

class OperationFactory{
public:
    static Operation* createOperate(char operate)
    {
        Operation *operation = nullptr;
        switch (operate) {
            case '+':
                operation = new OperationADD();
                break;
            case '-':
                operation = new OperationSUB();
                break;
            case '*':
                operation = new OperationMUL();
                break;
            case '/':
                operation = new OperationDIV();
                break;
            default:
                break;
        }
        return operation;
    }
};
//简单工程方法缺点：用户需要扩展操作，比如求根操作，则需要修改工厂中的case
//               违反了开闭原则：对扩展开放、对修改关闭
int main()
{
    Operation *oper = OperationFactory::createOperate('/');
    oper->_numA = 3;
    oper->_numB = 4;
    cout << oper->getResult();
    return 0;
}