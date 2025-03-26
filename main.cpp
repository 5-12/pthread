#include <thread>
#include <mutex>
#include <iostream>
std::mutex num;
void pr_j(long long int *q)
{
	while (true)
	{
		num.lock();
		(*q)++;
		std::cout << *q << std::endl;
		num.unlock();
	}
}
void print_o(long long int *q)
{
	while (true)
	{

		num.lock();
		(*q)++;
		std::cout << *q << std::endl;
		num.unlock();
	}
}
int main(void)
{
	long long int num=0;
	std::thread t1(pr_j, &num);
	std::thread t2(print_o, &num);
	t1.join();
	t2.join();

}
