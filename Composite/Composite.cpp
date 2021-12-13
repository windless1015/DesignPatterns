#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <vector>
/*
    组合模式的三种角色:
    1. component  抽象组件,提供基本的抽象方法
    2. leaf  叶子组件,没有子对象的叶子节点, 
    3. composite 组合组件, 里面可以包含composite 或者 leaf 节点
*/

/*
重点: 
1. 把对象当作一个树形结构, 回想UML类图, component 作为抽象类, leaf是 component的一个子类, composite也是其一个子类
但是composite可以挂载composite或者leaf, 所以 composite可以跟 component是一个聚合关系(因为component是父类,代表了两种子类)
2. component 里面提供了访问子节点的方法的叫做透明模式,因为 leaf和composite都可以继承这些方法如 add, remove, getChild等
component只提供了基本通用方法的叫做安全模式,因为leaf获取不到 add rmv getChild这些方法, 获取了也无意义,叶子节点是端点,不应该有这些方法
3. composite 组件中有一个 数组list或者array保存component, 因为它可以有叶子leaf 也可以有复合组件composite, composite里面需要实现add remove getChild这些函数
*/

/*
resource: 我觉得 这个里面的例子也挺好
https://www.youtube.com/watch?v=c0aq8x4HnIE&ab_channel=PekingUniversityMooc-%E6%AC%A2%E8%BF%8E%E8%AE%A2%E9%98%85-%E5%8C%97%E4%BA%AC%E5%A4%A7%E5%AD%A6%E5%85%AC%E5%BC%80%E8%AF%BE-
*/

//定义componet 抽象组件, 它是对一般 节点的抽象
class Component
{
public:
    /***************************************************/
    virtual ~Component() {};            //------------------>  这里一定要写虚继承, 否则后面delete 的时候会出现内存泄露
    /**************************************************/
    virtual void operate() = 0;
};

//定义leaf组件, 继承自Component, 是端点节点
class LeafA : public Component
{
public:
    void operate()
    {
        std::cout << "This is a leafA!" << std::endl;
    }
};

class LeafB : public Component
{
public:
    void operate()
    {
        std::cout << "This is a leafB!" << std::endl;
    }
};

class LeafC : public Component
{
public:
    void operate()
    {
        std::cout << "This is a leafC!" << std::endl;
    }
};

class Composite : public Component
{
public:
    Composite() {}
    ~Composite()
    {
        for (int i = 0; i < cmpList.size(); i++)
        {
            delete cmpList[i];
            cmpList[i] = nullptr;
        }
        cmpList.clear();
    }

    void operate()
    {
        std::cout << "This is composite!" << std::endl;
        for (int i = 0; i < cmpList.size(); i++)
        {
            cmpList[i]->operate();
        }
        
    }

    void add(Component* comp) 
    {
        cmpList.push_back(comp);
    }

    void remove(Component* comp)
    {
        for (auto it = cmpList.begin(); it != cmpList.end(); it++)
        {
            if (*it == comp)
            {
                cmpList.erase(it);
            }
        }
    }

    Component* getChild(int idx)
    {
        if (idx > -1 && idx < cmpList.size())
        {
            return cmpList[idx];
        }
        return nullptr;
    }

private:
    std::vector<Component*> cmpList;
};




int main()
{
    //创建一个根节点
    Composite*root = new Composite();
    //创建叶子节点,假设 有1个leafA和 1个leafB 和1个 leafC
    LeafA *la = new LeafA();
    LeafB *lb = new LeafB();
    LeafC *lc = new LeafC();

    //把这个root下面的叶子节点添加, 
    root->add(la);
    root->add(lb);
    root->add(lc);

    //再创建一个composite的节点
    Composite* ca = new Composite();

    ////再添加到root里面
    root->add(ca);

    //假设这个ca的 composite下面有一个LeafA和一个LeafB
    LeafA* la2 = new LeafA();
    LeafB* lb2 = new LeafB();
    ca->add(la2);
    ca->add(lb2);

    //至此所有的结构已经构建成功了,这时候就需要遍历打印所有的节点,
    root->operate();


    delete root;
    _CrtDumpMemoryLeaks();  //开始没有写虚继承,  virtual ~Component() {}; 导致总有内存泄漏的问题
    system("pause");
}

