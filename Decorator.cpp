#include <iostream>

using namespace std;

class Component
{
public:
	virtual ~Component() = 0;

	virtual void doStaff() = 0;
};

Component::~Component() {};

class ConComponent : public Component
{
public:
	virtual void doStaff() override
	{
		cout << "Hello from ConComponent" << endl;
	}
};

class Decorator : public Component
{
protected:
	Component* component_;

public:
	Decorator(Component* comp) : component_(comp)
	{

	}

	virtual void doStaff() override
	{
		cout << "DECORATED 1 STAFF" << endl;
		component_->doStaff();
	}

	~Decorator()
	{
		delete component_;
	}
};

class ConDecorator1 : public Decorator
{
public:
	ConDecorator1(Component* comp) : Decorator(comp)
	{

	}

	virtual void doStaff() override
	{
		cout << "DECORATED SECONDLY STAFF" << endl;
		Decorator::doStaff();
	}
};