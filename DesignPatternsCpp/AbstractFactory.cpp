#include <iostream>

/*
抽象工厂由4部分组成: 
抽象产品(AbstractProducts)
具体产品(ConcreteProducts)
抽象工厂(AbstractFactory)
具体工厂(ConcreteFactory)
*/

/*
    本例中 
    1. 定义原型基类产品A 和 产品B
    2. 定义具体产品A1, A2 和B1, B2
    3. 定义抽象工厂,提供产生A,B的原型方法
    4. 定义具体工厂C, 实现生产A1, B1的方法
    5. 定义具体工厂D, 实现胜场A2, B2的方法
    6. 客户端调用工厂
*/

//定义A类抽象类产品
class BaseProductA
{
public:
    virtual void PrintProductName() = 0;
};

//定义B类抽象产品

class BaseProductB
{
public:
    virtual void PrintProductName() = 0;
};


//定义A类的具体产品A1, 和A2
class ConcreteProductA1 : public BaseProductA
{
public:
    void PrintProductName()
    {
        std::cout << "This is ConcreteProductA1!" << std::endl;
    }
};

class ConcreteProductA2 : public BaseProductA
{
public:
    void PrintProductName()
    {
        std::cout << "This is ConcreteProductA2!" << std::endl;
    }
};



//定义B类的具体产品B1和B2
class ConcreteProductB1 : public BaseProductB
{
public:
    void PrintProductName()
    {
        std::cout << "This is ConcreteProductB1!" << std::endl;
    }
};

class ConcreteProductB2 : public BaseProductB
{
public:
    void PrintProductName()
    {
        std::cout << "This is ConcreteProductB2!" << std::endl;
    }
};





//定义抽象工厂,创建所定义的不同类型的产品
class AbstractFactory
{
public:
    virtual BaseProductA* CreateProductA() = 0;
    virtual BaseProductB* CreateProductB() = 0;
};

//定义具体工厂C
class ConcreteFactoryC : public AbstractFactory
{
public:
    BaseProductA* CreateProductA()
    {
        return new ConcreteProductA1();
    }

    BaseProductB* CreateProductB()
    {
        return new ConcreteProductB1();
    }

};


//定义具体工厂D
class ConcreteFactoryD : public AbstractFactory
{
public:
    BaseProductA* CreateProductA()
    {
        return new ConcreteProductA2();
    }

    BaseProductB* CreateProductB()
    {
        return new ConcreteProductB2();
    }

};



int main()
{
    //利用抽象工厂的方法创建相关产品

    //创建具体工厂C
    AbstractFactory* factoryC = new ConcreteFactoryC();
    //创建具体工厂D
    AbstractFactory* factoryD = new ConcreteFactoryD();

    //利用工厂C创建产品A
    BaseProductA* productCA = factoryC->CreateProductA();
    productCA->PrintProductName();
    //利用工厂C创建产品B
    BaseProductB* productCB = factoryC->CreateProductB();
    productCB->PrintProductName();


    //利用工厂D创建产品A
    BaseProductA* productDA = factoryD->CreateProductA();
    productDA->PrintProductName();

    //利用工厂D创建产品B
    BaseProductB* productDB = factoryD->CreateProductB();
    productDB->PrintProductName();

    delete productCA;
    delete productCB;

    delete productDA;
    delete productDB;

    delete factoryC;
    delete factoryD;

    system("pause");

}