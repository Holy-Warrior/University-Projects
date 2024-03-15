using namespace std;

//								|||		Sub-main		|||
//input for clock

int clock_input()
{
	while(a[0]==false)
	{
		cout << "\n\nInput the current time in 24 hour [h\m\s] format\n";
		cout << "\nHour : ";cin >> h;
		cout << "\nMinutes : ";cin >> m;
		cout << "\nseconds : ";cin >> s;
		
		if (h<=24 && m<=60 && s<=60)
		{a[0]=true;}
		else{cout << "\n\nthe format was not correct.please type the correct format";}
	}
	if (s==60)
	{s--;}
	return 0;
}

//							|||		Sub-Thread-2		|||
//messages for alarm

void alarm_message()
{
	if (a[2]==false)
	{cout << "\n		Press any key to set an alarm";}
	else if (a[3]==false)
	{cout << "\n 		Enter the time of alarm\n Hours : ";}
	else if (a[4]==false)
	{cout << "\n		Enter the time of alarm\n Hours : " << h1 << "\n Minutes : ";}
	else if (a[5]==false)
	{cout << "\n 		Error! please use the correct format [H\M]\n 	press enter to continue";}
	else if (a[6]==false)
	{cout << "\n		Alarm set!\n  	the alarm will ring at " << h1 << " : " << m1;
	if (h1==h && m1==m)
	{a[6]=true;
	}}
	else if (a[7]==false)
	{cout << "\n		Alarm raised for 5 seconds!\a";
	if (s1<=5)
	s1=s1+1;
	else
	{a[7]=true;}
	
	}
	
}

//								|||		Thread-1		|||
//taking inputs for thread2

void input_console()
{
	start:
	
	getch();
	a[2]=true;
	
	cin >> h1;
	a[3]=true;
	
	cin >> m1;
	a[4]=true;
	
	if (h1<24 && m1<60)
	{a[5]=true;}
	else
	{
		getch();
		a[4]=false;
		a[3]=false;
		a[2]=false;
	}
	
	while (a[7]==false)
	std::this_thread::sleep_for(1s);
	
	for (int i=2; i<=7; i++)
	a[i]=false;
	
	goto start;					//repeater for controler
}



//									|||		Thread-2		|||
//clock working system

int clock_working()
{
	
	while (a[1]==false)
	{
		clrscr();
		
		cout << "Digital clock\n";						//clock current time show
		cout << "	" << h << " : " << m << " : " << s;
		
		alarm_message();								//messages for alarm system
		
		std::this_thread::sleep_for(1s);				//clock seconds control
		s++;
		if (s==60)										//clock needle algorithm
		{
			s=0;
			m++;
			
			if (m==60)
			{
				m=0;
				h++;
				
				if (h==24)
				{
					h=0;
				}
			}
		}
	}
	return 0;
}
