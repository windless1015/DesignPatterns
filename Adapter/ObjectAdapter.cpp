#include <iostream>

/*
对象适配器: 只适合 java 或者c#这种单一继承的语言
核心: adapter 继承两个  target 和 adaptee
角色: target, adptee, adapter
*/


//定义target 抽象类
class Target
{
public:
	Target() {};
	virtual ~Target() {};
	virtual void targetProcess() = 0;
};


//定义adaptee, 原来的接口
class Adaptee
{
public:
	Adaptee() {};
	~Adaptee() {};

	void specificProcess()
	{
		std::cout << "This is specific prcocess!" << std::endl;
	}
};

//定义adapter, 继承 target, 这里Adapter把 Adaptee作为一个成员变量
class Adapter : public Target
{
public:
	Adapter():pAdaptee(nullptr)
	{
		pAdaptee = new Adaptee();
		std::cout << "create Adaptee" << std::endl;
	};
	~Adapter() {
		if (pAdaptee)
			delete pAdaptee;
	};

	//重写 targetProcess 方法, 其实是调用了Adaptee的方法,统一了一下接口
	void targetProcess()
	{
		pAdaptee->specificProcess();
		std::cout << "call  specificProcess method!" << std::endl;
	}

private:
	Adaptee* pAdaptee;
};






int main()
{
	//用Target模板创建adapter的定义
	Target* target = new Adapter();
	target->targetProcess();
	delete target;
	system("pause");
	return 0;
}

