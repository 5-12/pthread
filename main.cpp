#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>
std::vector<int> test[1000];
std::mutex mu;
std::atomic<int>test[100];
void in(void)
{
	std::unique_lock<std::mutex> mu;

}
void out(void)
{
	std::unique_lock<std::mutex> mu;

}
int main(void)
{
	;
}