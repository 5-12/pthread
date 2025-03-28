#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>
#include <queue>
#include <condition_variable>
//std::queue<int> test[1000];
std::mutex mu;
std::vector<int>test;
std::condition_variable cv;
bool ok = { false };
//std::condition_variable cv;
void in(void)
{
    std::unique_lock<std::mutex> lock(mu);
	//std::condition_variable cv;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "add " << i << std::endl;
		test.push_back(i);
	}
	ok = true;
	cv.notify_one();
	return;
}
void out(void)
{
	std::unique_lock<std::mutex> lock(mu);
	int time_put=0;
	cv.wait(lock ,[] {return ok;});
	for (int i = 0; i < 10; i++)
	{
		std::cout << "pull" << i << std::endl;
		test.pop_back();
	}
	return;
}
int main(void)
{
	std::thread in_pr(out);
	std::thread out_pr(in);
	in_pr.join();
	out_pr.join();

}