/*-----------------------------------------------------------------------------
 *
 * File: threads.cpp
 * Author: Brian Ankeny
 * Platform: Beaglebone Black
 * Eclipse Luna Service Release 2 (4.4.2)
 * This project provides a method of running multiple threads on the Beaglebone Black using c++11's thread library
 *
 *compile using the following : "g++ -std=c++11 -pthread file_name.cpp"
 *-----------------------------------------------------------------------------
*/

#include <stdio.h>
#include <iostream>
#include <thread>

using namespace std;

int iStatus1 = 0,
	iStatus2 = 0,
	iStatus3 = 0,
	iStatus4 = 0;

void Test1()
{
	cout << "Thread 1 started" << endl;

	while(1)
	{
		cout << "Thread 1 still running" << endl;
		usleep(1000000);			//Sleep for 1000ms
	}
	cout << "Thread 1 stopped" << endl;
}

void Test2()
{
	cout << "Thread 2 started" << endl;

	while(1)
	{
		cout << "Thread 2 still running" << endl;
		usleep(1000000);			//Sleep for 1000ms
	}
	cout << "Thread 2 stopped" << endl;
}

void Test3()
{
	cout << "Thread 3 started" << endl;

	while(1)
	{
		cout << "Thread 3 still running" << endl;
		usleep(1000000);			//Sleep for 1000ms
	}
	cout << "Thread 2 stopped" << endl;
}

int main(int argc, char** argv)
{
  cout << "hello world" << endl;
//  thread t([](){ cout << "hello from thread!" << endl; });
//  t.join();

  //Create thread for RS232 comms with LTM
  std::thread t1(Test1);

  	std::cout << "in main" << std::endl;

  	//Create thread for TCP socket server comms with other BeagleBone Black - serve data
  	std::thread t2(Test2);

  	//Create thread for TCP socket client comms with other BeagleBone Black -request data
  	std::thread t3(Test3);

//  	//Create thread for TCP socket client comms with other BeagleBone Black -request data
//  	iStatus1 = std::thread t4(Test4);
//  	t4.join();


  	while(1)
  	{
  		cout << "main still running" << endl;
  				usleep(1000000);			//Sleep for 1000ms
  	}

 // 	t1.join();
  //	t2.join();
  //	t3.join();


  return 0;
}
