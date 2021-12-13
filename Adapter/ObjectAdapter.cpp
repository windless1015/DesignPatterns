#include <iostream>

/*
����������: ֻ�ʺ� java ����c#���ֵ�һ�̳е�����
����: adapter �̳�����  target �� adaptee
��ɫ: target, adptee, adapter
*/


//����target ������
class Target
{
public:
	Target() {};
	virtual ~Target() {};
	virtual void targetProcess() = 0;
};


//����adaptee, ԭ���Ľӿ�
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

//����adapter, �̳� target, ����Adapter�� Adaptee��Ϊһ����Ա����
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

	//��д targetProcess ����, ��ʵ�ǵ�����Adaptee�ķ���,ͳһ��һ�½ӿ�
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
	//��Targetģ�崴��adapter�Ķ���
	Target* target = new Adapter();
	target->targetProcess();
	delete target;
	system("pause");
	return 0;
}

