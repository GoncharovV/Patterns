#include <memory>

using namespace std;

class Singleton
{
public:

	static shared_ptr<Singleton> instance()
	{
		static shared_ptr<Singleton> inst(new Singleton);

		return inst;
	}

	Singleton(const Singleton& obj) = delete;

	Singleton& operator=(const Singleton& obj) = delete;

	~Singleton() {}

private:
	Singleton() {};
};