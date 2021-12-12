#include <iostream>

/*
���󹤳���4�������: 
�����Ʒ(AbstractProducts)
�����Ʒ(ConcreteProducts)
���󹤳�(AbstractFactory)
���幤��(ConcreteFactory)
*/

/*
    ������ 
    1. ����ԭ�ͻ����ƷA �� ��ƷB
    2. ��������ƷA1, A2 ��B1, B2
    3. ������󹤳�,�ṩ����A,B��ԭ�ͷ���
    4. ������幤��C, ʵ������A1, B1�ķ���
    5. ������幤��D, ʵ��ʤ��A2, B2�ķ���
    6. �ͻ��˵��ù���
*/

//����A��������Ʒ
class BaseProductA
{
public:
    virtual void PrintProductName() = 0;
};

//����B������Ʒ

class BaseProductB
{
public:
    virtual void PrintProductName() = 0;
};


//����A��ľ����ƷA1, ��A2
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



//����B��ľ����ƷB1��B2
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





//������󹤳�,����������Ĳ�ͬ���͵Ĳ�Ʒ
class AbstractFactory
{
public:
    virtual BaseProductA* CreateProductA() = 0;
    virtual BaseProductB* CreateProductB() = 0;
};

//������幤��C
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


//������幤��D
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
    //���ó��󹤳��ķ���������ز�Ʒ

    //�������幤��C
    AbstractFactory* factoryC = new ConcreteFactoryC();
    //�������幤��D
    AbstractFactory* factoryD = new ConcreteFactoryD();

    //���ù���C������ƷA
    BaseProductA* productCA = factoryC->CreateProductA();
    productCA->PrintProductName();
    //���ù���C������ƷB
    BaseProductB* productCB = factoryC->CreateProductB();
    productCB->PrintProductName();


    //���ù���D������ƷA
    BaseProductA* productDA = factoryD->CreateProductA();
    productDA->PrintProductName();

    //���ù���D������ƷB
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