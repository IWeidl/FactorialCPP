#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
using namespace std;

void factorial(long number, long calcs);

int main(int argc, char* argv[])
{
	chrono::steady_clock::time_point startTime;
	long long endTime;
	long long timeTotal = 0;
	long number = stol(argv[1], nullptr, 0);
	long runs = stol(argv[2], nullptr, 0);
	int numThreads = stoi(argv[3], nullptr, 0);
	long calcsPerThread = 1000000000 / numThreads;
	std::cout << "\nCalculating factorial of " << argv[1] << " 1000000000 times";

	for (long k = 0; k < runs; k++) {
		startTime = chrono::steady_clock::now();
		vector<thread> threads;
		for (int i = 0; i < numThreads; i++) {
			threads.push_back(thread(factorial, number, calcsPerThread));
		}
		for (auto& iter : threads) {
			iter.join();
		}
		endTime = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - startTime).count();
		std::cout << "\nTime to complete run " << k << " was: \n Milliseconds: " << endTime / 1000000 << "\n Seconds: " << endTime / 1000000000;
		timeTotal += endTime;
	}
	long long outputTimeTotal = timeTotal / runs;
	std::cout << "\n===========================================================================";
	std::cout << "\nTOTAL TIMES WERE: \n MILLISECONDS: " << timeTotal / 1000000 << "\n SECONDS: " << timeTotal / 1000000000;
	std::cout << "\n\nAVERAGE FOR " << runs << " RUNS IS: \n MILLISECONDS: " << outputTimeTotal / 1000000 << "\n SECONDS: " << outputTimeTotal / 1000000000 << "\n";
}

void factorial(long number, long calcs)
{
	int res;
	for (long k = 0; k < calcs; k++)
	{
		res = 1;
		for (int i = 2; i <= number; i++)
			res *= i;
	}
}
