#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

long factorial(long n);

int main(int argc, char *argv[])
{
	chrono::steady_clock::time_point startTime;
	long long endTime;
	long long timeTotal = 0;
	long number = stol(argv[1], nullptr, 0);
	long runs = stol(argv[2], nullptr, 0);
	long threads = stol(argv[3], nullptr, 0);
	long calcsPerThread = 1000000000 / threads;
	cout << "\nCalculating factorial of " << argv[1] << " 1000000000 times";
	for (long k = 0; k < runs; k++) {
		startTime = chrono::steady_clock::now();
		thread thread1(factorial, calcsPerThread);
		thread thread2(factorial, calcsPerThread);
		thread thread3(factorial, calcsPerThread);
		thread thread4(factorial, calcsPerThread);
		thread thread5(factorial, calcsPerThread);
		thread thread6(factorial, calcsPerThread);
		thread thread7(factorial, calcsPerThread);
		thread thread8(factorial, calcsPerThread);
		thread thread9(factorial, calcsPerThread);
		thread thread10(factorial, calcsPerThread);
		thread thread11(factorial, calcsPerThread);
		thread thread12(factorial, calcsPerThread);
		thread thread13(factorial, calcsPerThread);
		thread thread14(factorial, calcsPerThread);
		thread thread15(factorial, calcsPerThread);
		thread thread16(factorial, calcsPerThread);
		thread1.join();
		thread2.join();
		thread3.join();
		thread4.join();
		thread5.join();
		thread6.join();
		thread7.join();
		thread8.join();
		thread9.join();
		thread10.join();
		thread11.join();
		thread12.join();
		thread13.join();
		thread14.join();
		thread15.join();
		thread16.join();
		endTime = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - startTime).count();
		cout << "\nTime to complete run " << k << " was: \n Milliseconds: " << endTime / 1000000 << "\n Seconds: " << endTime / 1000000000;
		timeTotal += endTime;
	}
	long long outputTimeTotal = timeTotal / runs;
	cout << "\n===========================================================================";
	cout << "\nTOTAL TIMES WERE: \n MILLISECONDS: " << timeTotal / 1000000 << "\n SECONDS: " << timeTotal / 1000000000;
	cout << "\n\nAVERAGE FOR " << runs << " RUNS IS: \n MILLISECONDS: " << outputTimeTotal / 1000000 << "\n SECONDS: " << outputTimeTotal / 1000000000 << "\n";
}

long factorial(long n)
{
	int res = 1, i;
	for (i = 2; i <= n; i++)
		res *= i;
	return res;
}