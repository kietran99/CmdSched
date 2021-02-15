#include "cspch.h"

//#include "BaseTask.h"
//#include "BaseSchedule.h"
//#include "CommandMux.h"

//#include "task.h"
//#include "input-reader.h"
#include "schedule.h"
#include "command-executor.h"

//using namespace CmdSched;

class B
{
public:	
	B() : y(1) {}

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

//class Application
//{
//public:
//	Application()
//		: cmdMux(&schedule)
//	{		
//		Start();
//		Update();
//	}
//
//	void Start()
//	{
//		std::vector<Core::BaseTask> tasks = CreateTestTasks();
//		for (int i = 0; i < tasks.size(); i++)
//		{
//			schedule.AddTask(std::move(tasks[i]));
//		}
//		
//		schedule.ShowAllTasks();		
//	}
//
//	void Update()
//	{
//		bool isRunning = true;
//
//		while (isRunning)
//		{
//			cmdMux.RequestCommand();
//		}
//	}
//private:
//	std::vector<Core::BaseTask> CreateTestTasks()
//	{
//		std::vector<Core::BaseTask> res;
//		Core::BaseTask task{ "Test", { 1, 29, 5, 12, 2020 } };
//		res.push_back(Core::BaseTask("Test 0", { 1, 29, 5, 12, 2020 }));
//		res.push_back(Core::BaseTask("Test 1", { 23, 44, 6, 12, 2020 }));
//		res.push_back(Core::BaseTask("Test 2", { 14, 23, 8, 12, 2020 }));
//		return res;
//	}
//
//private:
//	Core::BaseSchedule schedule;
//	Command::CommandMux cmdMux;
//};

int main()
{
	//Application app;
	/*auto maybeCommandData = Command::ReadInput(std::cin);
	maybeCommandData
		.Match(
			[](auto err) { std::cout << err.msg; },
			[](auto cmdData) { std::cout << cmdData; }
	);*/
	Core::Schedule schedule{};
	Command::Add(schedule, { "Clean the House", "15", "02", "2021" });
	Command::Show(schedule, {});
	Command::Add(schedule, { "Write some Code", "20", "04", "2021" });
	Command::Show(schedule, {});
	Command::Add(schedule, { "Eat Chocolate", "29", "02", "2024" });
	Command::Show(schedule, {});
}