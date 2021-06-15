#include <iostream>

using namespace std;

class ComplicatedObject
{
public:
	virtual void doStuff() = 0;

	virtual ~ComplicatedObject() {};
};

class AnotherComplicatedObject
{
public:
	virtual void doAnotherStuff() = 0;

	virtual ~AnotherComplicatedObject() {};
};

class ConComplicatedObject : public ComplicatedObject
{
public:
	virtual void doStuff() override
	{
		cout << "Stuff" << endl;
	}
};

class ConAnotherComplicatedObject : public AnotherComplicatedObject
{
public:
	virtual void doAnotherStuff() override
	{
		cout << "Another Stuff" << endl;
	}
};

class Facade
{
private:
	ComplicatedObject* _obj1;
	AnotherComplicatedObject* _obj2;

public:
	Facade(ComplicatedObject* obj1, AnotherComplicatedObject* obj2)
	{
		_obj1 = obj1;
		_obj2 = obj2;
	}

	void doAction()
	{
		_obj1->doStuff();
		_obj2->doAnotherStuff();
	}

	~Facade()
	{
		delete _obj1;
		delete _obj2;
	}
};

/*
	Facade* facade = new Facade(new ConComplicatedObject, new ConAnotherComplicatedObject);

	facade->doAction();
*/