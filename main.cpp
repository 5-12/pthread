#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>
#include <queue>
std::queue<int> test[1000];
std::mutex mu;
//std::atomic<int>test[100];
std::atomic<bool>max{ false };
std::atomic<bool>nome{ false };
std::condition_variable cv;
void in(void)
{
	while (true)
	{
		std::unique_lock<std::mutex> ;
	}
}
void out(void)
{
	while (true)
	{
		
	}
	
}
int main(void)
{
	std::thread in_pr(in);
	std::thread out_pr(out);
	in_pr.join();
	out_pr.join();
}