#include <iostream>
#include <string>
/*
建造者模式有四个角色:
1. 抽象建造者 Builder
2. 具体建造者 ConcreteBuilder
3. 指挥官 Director
4. 产品 Product
*/

/*
UML图关系分析
1. 抽象建造者定义了相关的原型和模板, 即BuildePartA(), BuildePartB()这样
然后还提供了getResult(), 即构造建造产品的这个接口
2. 具体建造者是继承于抽象建造者, 是其的实现, 因此是 ----|> 的关系
3. 指挥官 调用 具体建造者创建Product
4. 具体建造者和 product是关联的关系,因为 Product在函数调用完毕的时候就完成了,耦合联系没有那么强

*/

//定义Product
class Product
{
public:
	Product():partA(""), partB(""), partC("")
	{ 
	}

	void getProductInfo()
	{
		std::cout << "PartA =" << partA << ", PartB = " << partB << ", PartC = " << partC << std::endl;
	}

	void setPartA(std::string & a)
	{
		partA = a;
	}

	void setPartB(std::string& b)
	{
		partB = b;
	}

	void setPartC(std::string& c)
	{
		partC = c;
	}

private:
	std::string partA;
	std::string partB;
	std::string partC;
};


//定义抽象建造者Builder
class Builder
{
public:
	Builder() : product(nullptr)
	{
		
	}

	void createProduct()
	{
		if (nullptr == product)
		{
			product = new Product();
		}
	}
		
	virtual void buildPartA() = 0;
	virtual void buildPartB() = 0;
	virtual void buildPartC() = 0;
	Product* getResult()
	{
		return product;
	}
protected:
	Product* product;
};

//定义具体建造者类
class ConcreteBuilder : public Builder
{
public:
	void buildPartA()
	{
		std::string s = "A";
		product->setPartA(s);
		std::cout << "创建产品A的部分!" << std::endl;
	}
	void buildPartB()
	{
		std::string s = "B";
		product->setPartB(s);
		std::cout << "创建产品B的部分!" << std::endl;
	}
	void buildPartC()
	{
		std::string s = "C";
		product->setPartC(s);
		std::cout << "创建产品C的部分!" << std::endl;
	}
};

class Director
{
public:
	Director() : pBuilder(nullptr)
	{
	}

public:
	void SetBuilder(Builder* pb)
	{
		pBuilder = pb;
	}
	Product* Construct()
	{
		if (nullptr != pBuilder)
		{
			//创建原始的产品的指针
			pBuilder->createProduct();
			//分别为这个产品创建不同的模块
			pBuilder->buildPartA();
			pBuilder->buildPartB();
			pBuilder->buildPartC();
			//返回创建好的产品
			return pBuilder->getResult();
		}
		return nullptr;
	}
private:
	Builder* pBuilder;
};



int main()
{
	//创建具体的建造类
	ConcreteBuilder* cBuilder = new ConcreteBuilder();
	//创建director
	Director* director = new Director();
	director->SetBuilder(cBuilder);
	Product* product = director->Construct();
	product->getProductInfo();

	delete cBuilder;
	delete director;
	delete product;

	system("pause");
}

