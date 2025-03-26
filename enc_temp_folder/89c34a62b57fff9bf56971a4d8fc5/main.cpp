#include <thread>
#include <mutex>
#include <iostream>
std::mutex num;
std::atomic<bool>stop_tag = { false };
void pr_j(long long int *q)
{
	while (true)
	{
		std::lock_guard<std::mutex>lock(num);
		(*q)++;
		std::cout << *q << std::endl;
		if (stop_tag.load() == true)
		{
			return;
		}
	}
}
void print_o(long long int *q)
{
	while (true)
	{
		std::lock_guard<std::mutex>lock(num);
		(*q)++;
		std::cout << *q << std::endl;
		if(stop_tag.load() == true)
		{
			return;
		}
	}
}
void stops()
{
	int a = 0;
	while (a != 10000000000)
	{
		++a;
	}
	stop_tag.store(true);
}
int main(void)
{
	long long int nums=0;
	std::thread t1(pr_j, &nums);
	std::thread t2(print_o, &nums);
	std::thread t3(stops);
	t1.join();
	t2.join();
	t3.join();

}
