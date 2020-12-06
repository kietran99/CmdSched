#include "cspch.h"
#include "BaseTask.h"
#include "BaseSchedule.h"
using namespace CmdSched;

class B
{
public:	

	B(int y) : y(y)
	{
		std::cout << "Param Constructing B\n";
	}

	B(const B& other) 
		: y(other.y)
	{
		std::cout << "Copying B\n";
	}

	B(B&& other) noexcept
		: y(other.y)
	{
		printf("Moving B\n");
	}	

	void setY(int y) { this->y = y; }

	int getY() { return y; }

	~B()
	{
		std::cout << "Destroying B\n";
	}
private:
	int y;
};

class A
{
public:	
	A(int x, const B& b) : x(x), b(b)
	{
		std::cout << "Constructing A\n";
	}

	A(const A& other) : x(other.x), b(other.b)
	{
		std::cout << "Copying A\n";
	}

	A(int x, B&& b) : x(), b(std::move(b))
	{
	}

	~A()
	{
		std::cout << "Destroying A\n";
	}

	void setX(int x) { this->x = x; }

	//void setB(const B& b) { this->b = b; }
	
	void logB() 
	{ 
		std::cout << b.getY() << std::endl;
	}
private:
	int x;
	B b;
};

class C
{
public:
	C(const B& b)
	{
		vect.push_back(b);
		std::cout << "Constructing C\n";
	}

	C(B&& b)
	{
		vect.push_back(std::move(b));
		std::cout << "Constructing C\n";
	}

	void push(const B& b) { vect.push_back(b); }

	void printAt(int idx) { std::cout << vect[idx].getY() << std::endl; }
private:
	std::vector<B> vect;
};

std::vector<Core::BaseTask> CreateTestTasks()
{
	std::vector<Core::BaseTask> res;
	res.push_back(Core::BaseTask("Test 0", { 1, 29, 58, 12, 5, 2020 }));
	res.push_back(Core::BaseTask("Test 1", {10, 44, 23, 12, 6, 2020}));
	res.push_back(Core::BaseTask("Test 2", {23, 23, 14, 12, 6, 2020}));
	return res;
}

int main()
{		
	{
		Core::BaseSchedule schedule;
		std::vector<Core::BaseTask> tasks = CreateTestTasks();
		for (int i = 0; i < tasks.size(); i++)
		{
			schedule.AddTask(std::move(tasks[i]));
		}
		std::cout << schedule << std::endl;
	}
	
	std::cin.get();
}