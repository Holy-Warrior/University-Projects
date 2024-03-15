#include <iostream>						//input and output
#include <conio.h>						//for getch()
#include <thread>						//multi-tasking and process-delay for clock 
#include <D:\Semester 1\app4\hamza.cpp>	//external file

using namespace std;
bool a[10]={0};								//global values
int h,m,s,h1,m1,s1=0;

#include <D:\Semester 1\app4\running.cpp>		//external file


int main()
{
	intro();								//introduction page from header <hamza>
	cout << "Project for Digital clock with an Alarm system\n\n press any key to start";
	getch();
	clrscr();
	clock_input();							//input for clock
	
	//multi-task execution
	std::thread t1(input_console);				//input and output operations
	std::thread t2(clock_working);				//clock system, messages and main window
	t1.join();
	t2.join();
	
	return 0;
}