#include <iostream>
#include <string>
/*
单例构造的要点:
1. 构造函数私有
2. 静态成员指针
3. 提供静态获取instance的接口
*/

/*
单例模式的 懒汉式 (Lazy) 和 饿汉式 (Hungry)
Lazy: 在 getInstance的时候才创建
Hungry: 类生成的时候就创建
主要区别: 类对象构造时机不一样
*/



class SingletonLazy
{
private:
	SingletonLazy() {};

public:
	static SingletonLazy* getInstance()
	{
		if (nullptr == _instance)
		{
			_instance =  new SingletonLazy();
		}
		return _instance;
	}

private:
	static SingletonLazy* _instance;
};

//类外定义静态成员变量
SingletonLazy* SingletonLazy::_instance = nullptr;


class SingletonHungry
{
private:
	static SingletonHungry* _instance;

private:
	SingletonHungry() {};

public:
	static SingletonHungry* getInstance()
	{
		return _instance;
	}

};

//类外定义静态成员变量
SingletonHungry* SingletonHungry::_instance = new SingletonHungry();

int main()
{


	SingletonLazy* p = SingletonLazy::getInstance();
	std::cout << p << std::endl;

	SingletonHungry* t = SingletonHungry::getInstance();
	std::cout << t << std::endl;

	system("pause");
}




