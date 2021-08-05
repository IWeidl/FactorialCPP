#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

long factorial(long& n);
void func1(long n);
void func2(long n);

int main(int argc, char *argv[])
{
	chrono::steady_clock::time_point startTime;
	long long endTime;
	long long timeTotal = 0, fact;
	long number = stol(argv[1], nullptr, 0);
	long runs = stol(argv[2], nullptr, 0);
	cout << "\nCalculating factorial of " << argv[1] << " 1000000000 times";
	for (long k = 0; k < runs; k++) {
		startTime = chrono::steady_clock::now();
		thread thread1(func1, number);
		thread thread2(func2, number);
		thread1.join();
		thread2.join();
		endTime = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - startTime).count();
		cout << "\nTime to complete run " << k << " was: \n Milliseconds: " << endTime / 1000000 << "\n Seconds: " << endTime / 1000000000;
		timeTotal += endTime;
	}
	long long outputTimeTotal = timeTotal / runs;
	cout << "\n===========================================================================";
	cout << "\nTOTAL TIMES WERE: \n MILLISECONDS: " << timeTotal / 1000000 << "\n SECONDS: " << timeTotal / 1000000000;
	cout << "\n\nAVERAGE FOR " << runs << " RUNS IS: \n MILLISECONDS: " << outputTimeTotal / 1000000 << "\n SECONDS: " << outputTimeTotal / 1000000000 << "\n";
}

long factorial(long& n)
{
	int res = 1, i;
	for (i = 2; i <= n; i++)
		res *= i;
	return res;
}
void func1(long n)
{
	for (long j = 0; j < 500000000; j++)
	{
		factorial(n);
	}
}
void func2(long n)
{
	for (long j = 0; j < 500000000; j++)
	{
		factorial(n);
	}
}