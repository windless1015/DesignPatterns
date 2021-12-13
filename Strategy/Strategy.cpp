#include <iostream>

/*
策略模式
角色
上下文环境: context, 
抽象策略类: IStrategy
具体策略族: StrategyA, StragegyB, ...
*/

//定义抽象策略类
class IStrategy
{
public:
    IStrategy() {};
    virtual ~IStrategy() {};

    virtual void algorithm() = 0;
};

//定义两个具体策略类
class StrategA : public IStrategy
{
public:
    StrategA() {};
    ~StrategA() {};
    void algorithm()
    {
        std::cout << "Implement Strategy A method!" << std::endl;
    }
};

class StrategB : public IStrategy
{
public:
    StrategB() {};
    ~StrategB() {};
    void algorithm()
    {
        std::cout << "Implement Strategy B method!" << std::endl;
    }
};

//定义上下文环境类 context
class Context
{
public:
    Context() {
    };
    ~Context() {
        if (m_iStrategy)
        {
            delete m_iStrategy;
        }
    };

    void SetStrategy(IStrategy* s)
    {
        m_iStrategy = s;
    }
    void algorithm()
    {
        m_iStrategy->algorithm();
    }

private:
    IStrategy* m_iStrategy;
};




int main()
{
    //创建上下文类
    Context* con = new Context();

    //定义具体策略
    IStrategy* stratA = new StrategA();
    IStrategy* stratB = new StrategB();
    con->SetStrategy(stratA);
    con->algorithm();

    con->SetStrategy(stratB);
    con->algorithm();


    delete con;
    system("pause");
    return 0;
}
