#include <iostream>

/*
外观模式
角色:
外观类 Facade
子系统类 SubSystem
*/


//定义子系统

class ISubSystem
{
public:
	virtual void call() = 0;

};


class SubSystem1 : public ISubSystem
{
public:
	SubSystem1() {};
	~SubSystem1() {};
	void call()
	{
		std::cout << "This is subsystem 1 " << std::endl;
	}

};

class SubSystem2 : public ISubSystem
{
public:
	SubSystem2() {};
	~SubSystem2() {};
	void call()
	{
		std::cout << "This is subsystem 2 " << std::endl;
	}

};

//定义外观类
class Facade
{
public:
	Facade() 
	{
		s1 = new SubSystem1();
		s2 = new SubSystem2();
	};
	~Facade() 
	{
		delete s1;
		delete s2;
	};

	void WrapCall()
	{
		s1->call();
		s2->call();
	}

private:
	SubSystem1* s1;
	SubSystem2* s2;
};




int main()
{
	Facade* f = new Facade();
	f->WrapCall();
	delete f;

	system("pause");
	return 0;
}
