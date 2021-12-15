#include <iostream>

/*  访问者模式:
应用:  数据相对稳定,  访问形式多样
角色: 抽象visitor, 具体visitor, 抽象element, 具体element,对象结构ObjectStructure, client
分析:
抽象Visitor:  为所有具体Visitor提供抽象方法, visitA, visitB, visitC
具体Visitor: 每一个具体的visitor实现自己 对 不同 element访问visit方法,例如 ConcreteVisitorA实现 concreteElementA 和 concreteElementB的方法
抽象Element: 提供accept方法,参数为 Visitor
具体Element: 实现accept方法, 具体表现为 visitor.visitB
对象结构ObjectStructure: 一个容器, 提供管理这些元素Element的方法
*/

class Element;
class ConcreteElementA;
class ConcreteElementB;
class ConcreteElementC;

//抽象visitor
/*为所有具体Visitor提供visit抽象方法, 需要带上具体Element作为参数*/
class Vistor
{
public:
    virtual ~Vistor() {};

    virtual void visitConcreteElementA(ConcreteElementA* cEleA) = 0;  //这个形参参数很重要
    virtual void visitConcreteElementB(ConcreteElementB* cEleB) = 0;
    virtual void visitConcreteElementC(ConcreteElementC* cEleC) = 0;
};

//抽象element
class Element
{
public:
    virtual void accept(Vistor* v) = 0;

};


//具体element
class ConcreteElementA : public Element
{
public:
    ConcreteElementA(const std::string& data) :data(data) {}
    ~ConcreteElementA() {}

    void accept(Vistor* v) override
    {
        v->visitConcreteElementA(this);
    }

    std::string getData()
    {
        return data;
    }
private:
    std::string data;

};

class ConcreteElementB : public Element
{
public:
    ConcreteElementB(const std::string& data) :data(data) {}
    ~ConcreteElementB() {}

    void accept(Vistor* v) override
    {
        v->visitConcreteElementB(this);
    }

    std::string getData()
    {
        return data;
    }

private:
    std::string data;

};

class ConcreteElementC : public Element
{
public:
    ConcreteElementC(const std::string& data) :data(data) {}
    ~ConcreteElementC() {}

    void accept(Vistor* v) override
    {
        v->visitConcreteElementC(this);
    }

    std::string getData()
    {
        return data;
    }

private:
    std::string data;

};



//具体visitor
/*提供本visitor访问各个elements的具体实现*/
class ConcreteVistorA : public Vistor
{
public:
    ConcreteVistorA() {}
    ~ConcreteVistorA() {}

    void visitConcreteElementA(ConcreteElementA* cEleA) override
    {
        std::cout << "VistorA  has visited ConcreteElementA." << std::endl;
        std::cout << "ConcreteElementA data :" << cEleA->getData() << std::endl;
    }

    void visitConcreteElementB(ConcreteElementB* cEleB) override
    {
        std::cout << "VistorA  has visited ConcreteElementB." << std::endl;
        std::cout << "ConcreteElementB data :" << cEleB->getData() << std::endl;
    }

    void visitConcreteElementC(ConcreteElementC* cEleC) override
    {
        std::cout << "VistorA  has visited ConcreteElementC." << std::endl;
        std::cout << "ConcreteElementC data :" << cEleC->getData() << std::endl;
    }

};

class ConcreteVistorB : public Vistor
{
public:
    ConcreteVistorB() {}
    ~ConcreteVistorB() {}

    void visitConcreteElementA(ConcreteElementA* cEleA) override
    {
        std::cout << "VistorB  has visited ConcreteElementA." << std::endl;
        std::cout << "ConcreteElementA data :" << cEleA->getData() << std::endl;
    }

    void visitConcreteElementB(ConcreteElementB* cEleB) override
    {
        std::cout << "VistorB  has visited ConcreteElementB." << std::endl;
        std::cout << "ConcreteElementB data :" << cEleB->getData() << std::endl;
    }

    void visitConcreteElementC(ConcreteElementC* cEleC) override
    {
        std::cout << "VistorB  has visited ConcreteElementC." << std::endl;
        std::cout << "ConcreteElementC data :" << cEleC->getData() << std::endl;
    }

};





//这里没有设置ObjectStructure, 也可以添加一个,本质上其实就是在管理  Elements

int main()
{
    ConcreteElementA elementA("Hello");
    ConcreteElementB elementB("World");

    ConcreteVistorA vistor1;
    ConcreteVistorB vistor2;

    elementA.accept(&vistor1);
    elementA.accept(&vistor2);

    elementB.accept(&vistor1);
    elementB.accept(&vistor2);

    system("pause");
}

