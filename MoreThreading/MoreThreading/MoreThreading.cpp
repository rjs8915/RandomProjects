#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <future>

#include "FibCalculator.h"

using namespace std;

void PrintInfo(int info, mutex* mtx)
{
	mtx->lock();
	cout << "Thread #" << info << endl;
	mtx->unlock();
}

int main()
{
	//vector<thread> infoThreads;
	//mutex mtx;
	//for (int i = 0; i < 50; i++)
	//{
	//	infoThreads.push_back(thread(PrintInfo, i, &mtx));
	//}
	//
	//for (int i = 0; i < infoThreads.size(); i++)
	//{
	//	infoThreads[i].join();
	//}
	//
	//FibCalculator fibCalc;
	//vector<thread> fibThreads;
	//
	//for (int i = 0; i < 45; i++)
	//{
	//	fibThreads.push_back(thread(&FibCalculator::PrintFibNumber, fibCalc, i, &mtx));
	//}
	//
	//for (int i = 0; i < fibThreads.size(); i++)
	//{
	//	fibThreads[i].join();
	//}


	promise<int> promiseObject;
	future<int> futureObject = promiseObject.get_future();
	
	thread futuresThread([&]() {
			cout << "Inside Thread" << endl;
			this_thread::sleep_for(3s);

			promiseObject.set_value(25);

			this_thread::sleep_for(2s);
			cout << "Done with thread" << endl;
	});
	
	cout << "Waiting for thread to return future value" << endl;
	cout << futureObject.get() << endl;
	
	futuresThread.join();



	auto myLambda = [](float num)
	{
		this_thread::sleep_for(2s);
		cout << "inside my lambda. num = " << num << endl;
		this_thread::sleep_for(2s);
	};

	thread myThread(myLambda, 41.3);
	cout << "Started thread" << endl;
	myThread.join();




	cout << "Bottom of Main" << endl;
}