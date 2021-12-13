#include <iostream>

/*
类适配器: 适合可以多重继承的语言,例如c++
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

//定义adapter, 继承 target和adaptee
class Adapter : public Target, private Adaptee
{
public:
	Adapter() {};
	~Adapter() {};

	//重写 targetProcess 方法, 其实是调用了Adaptee的方法,统一了一下接口
	void targetProcess()
	{
		specificProcess();
		std::cout << "call  specificProcess method!" << std::endl;
	}

};






int main()
{
    //用Target模板创建adapter的定义
	Target* target = new Adapter();
	target->targetProcess();
	delete target;
	system("pause");
}

