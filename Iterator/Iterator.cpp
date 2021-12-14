#include <iostream>

/*迭代器模式:
角色:
1. 抽象迭代器iterator
2. 具体迭代器
3.抽象聚合类 aggregate
4.具体聚合类 concreteAgregate
5. client
*/

/*
思考UML图:
1.  抽象iterator 提供迭代器的基本方法,例如getNext, hasMore,等
2. 抽象aggregate 提供创建迭代器的接口 createIterator
3. 具体的集合aggregate只是依赖具体的迭代器,

*/


int main()
{
    std::cout << "Hello World!\n";
}

