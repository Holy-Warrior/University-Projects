#include "iostream"
#include "string.h"
#include "thread"	//Thread and chrono used for delay in the process
#include "chrono"
#include "conio.h"
#include "windows.h"

void loading(){			// Simulate a loading bar
	char load_empty[] ="{______________________________________________________________}";
	char load_full[] = "{##############################################################}";
	std::cout<<"\n\nPROCESSING\n";
	std::cout<<load_empty<<"\r";
	for(auto i : load_full){
		std::cout<<i;
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}

}

void emoji(){
std::cout <<
"@@@@@@@@@@@@@@%%%#######%@@@@%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl <<
"@@@@@@@@@%*++===--==--::::-:::---===+##*****##%@@@@@@@@@@@@" << std::endl <<
"@@@@@@@%*+++++*##***+--:-------------::.:--:.:::::=*@@@@@@@@" << std::endl <<
"@@@@@@#++++*#**####**+=:::::=.        ::---::::.    .=%@@@@@" << std::endl <<
"@@@@@*++++*+*###*+++++=:.    -        :-.      .-     .%@@@@" << std::endl <<
"@@@@*++++++**+*+*###%%%%%#+:.:       .+-               *@@@@" << std::endl <<
"@@@#**++++++++#@@@@@@@@@**#%%+:      :+++#%%%%%#+.     .#@@@" << std::endl <<
"@@%%%%#+++#%#*@@@%%%%%%%@%#*#@%=:  -#%@@@@@@%#%%#-::::.:--+%" << std::endl <<
"*+*#%%@@%%##*+++=--+%+. .-+#%#*=:  .=#@%%#+-.     .:::.---==" << std::endl <<
"+%@#*+*%#+*#%@%%%%#**+-..-+++++=:    -@*+=--=*+--+#**#%#++.*" << std::endl <<
"*@%*++*#@@@@%#**+++++++++++++++===+*###*++==:     -%@%#*++=+" << std::endl <<
"*@%**%@@@@%#%%@@%#**++++++********%@@%%#+++=:       :*@@@%+:" << std::endl <<
"+%@%+**#%@%*++**#%@@@@%#*+*+****+*@@#+*#%%%#=.       -@@@@%=" << std::endl <<
"**%@*+++*@@%#*++++#@@%%@@@%%#***++%@@#%%%%%%*=-==-::=%@%#*:.:--." << std::endl <<
"****+++++*@@@@%##*#@%*++*###%@@@%%%@@#**+++++++%@@@@@%-.    ...=" << std::endl <<
"**+++++++*%@@%%@@@@@@#+++++++*#@@%%@@@@@@@@%%%@@@@@@%****#%%@@%*" << std::endl <<
"@#+++++++#@@#**%@@@@@@%%#**+#@%*++++*+++#@%#%@@@@@@@@#%#+++@%:" << std::endl <<
"@@#++++++*%@#*%@%%%%%%%@%#*++=#@%+++++++%@=.   .*@=      *@+." << std::endl <<
"@@@%+++++++#@@#*@@##%@@@@@@@@@%*+++++++=:*@- .....*@#====#@*=-" << std::endl <<
"@@@@%*++++++*%@@@@%*++++*#%%@@@@@@@%%%%##%@#+++**#@%**+*#%%@%%" << std::endl <<
"@@@@@@#*+++++++*%@@%*++++++++%@###%@@@@@@@@@@@@@@@@@@@@@@@@@%" << std::endl <<
"@@@@@@@@%*++++++++++*#%@@%#%@@*+++++++=:*@- .....*@#====#@*=-" << std::endl <<
"@@@@@@@@@@@#*##**+***++++*#%@@@##**++++=-#@-      *%:   -%%." << std::endl <<
"@@@@@@@@@@@@@%####**####*++++**#%@@@@%%##@@=.....-%%:..=%@+=" << std::endl <<
"@@@@@@@@@@@@@@@@%#**#######***++++*##%%%%%%%@@@@@@@@@@@@@@@%*" << std::endl <<
"@@@@@@@@@@@@@@@@@@@%#**#####%%##**++++++++===+***++===++=:" << std::endl <<
"@@@@@@@@@@@@@@@@@@@@@@@%#***######%%##******+=-:::::...::." << std::endl <<
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#*++**##%#########+=----=--::" << std::endl <<
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#*++++++++***#*+==-=+++=" << std::endl <<
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%##***+++++==:.  .     " << std::endl <<
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%##*+=-:..    " << std::endl <<
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#*+=-:." ;


}

class calculator{
	
	private:
		bool activated{false};				
		std::string key{"activate"};	//Activation key here
		
		//Using clear(); to show if the software is activated, also used as shortcut to clean the console
		void clear(){		//The function is used mostly everywhere
			system("cls");
			if (activated == false)
			std::cout<<"===========< You are using Trial software >============"<<std::endl<<std::endl;
		}
		

		//The functions checks if sotware is activated and returns bool accordingly
		bool activator(){
			clear();
			std::string temp, temp2;			//temp for user decision, temp2 user given activation key
			bool return_activated = false;		//This is returned by function
			
			if (activated == false){
				while(true){				//Loop runs only if software not activated
				clear();
				std::cout<<"You are using trial software\n";
				std::cout<<"Would you like to activate the software(yes/no)?\n";
				std::cin>>temp;
				clear();
							//Multiple conditional statements to reduce runtime errors and increase flexibility
				if (temp == "yes" || temp == "y" || temp == "Yes" || temp=="YES" || temp == "true" || temp == "1"){
					std::cout<<"Please enter the activation code\n";
					std::cin>>temp2;
					loading();
					clear();

					if (temp2 == key){
						activated = true;
						return_activated = true;
						std::cout<<"SOFTWARE ACTIVATED\n";
						emoji();
						std::cout<<"\n\nPress any key to continue....";
						getch();
						clear();
						break;			//Exiting loop with return = true
					}
					else{
						std::cout<<"Wrong activation code\n"; 	//Repeating loop
						std::cout<<"\n\nPress any key to continue....";
						getch();
						clear();
					}
				}		//Multiple conditional statements to reduce runtime errors and increase flexibility
				else if(temp == "no" || temp == "n" || temp == "No" || temp=="NO" || temp == "false" || temp == "0"){
					return_activated = false;
					clear();
					break;	//exiting loop, force quit by user, user does not wish to activate
				}
				else{		//If keystrokes not recognized, show errors
					std::cout<<"Error! wrong option selected!";//repeating loop
					std::cout<<"\n\nPress any key to continue....";
					getch();
					clear();
				}
				}//end while loop
			}
			else{//the statement only runs if software already activated
				return_activated = activated;
			}
			
			return return_activated;
		}
		
	public:
		calculator(){	//Deafult constructor
			clear();
			menu();
		}
		
		void menu(){
			clear();
			activator();//If software is not activated, let him go through the activation wizard
			int temp;	//Stores user operation choice
			while(true){
				clear();
				std::cout<<"Select your prefered option\n";
				std::cout<<"1.Addition\n";
				std::cout<<"2.Subtraction\n";
				if (activated == true){	//Print lines if software is activated
					std::cout<<"3.Multiplication\n";
					std::cout<<"4.Division\n";
				}
				else{					//Print lines if software not activated
					std::cout<<"3.Multiplication (ACTIVATION REQUIRED)\n";
					std::cout<<"4.Division (ACTIVATION REQUIRED)\n";
				}
				std::cin>>temp;		//Storing user operation choice
				clear();
				
				float a, b;//This is only declaration
				bool run;

				switch(temp){
					case 1:			//Addition
						run = take(0);				//take(This_is_not_a_premium_only_feature);
						if (run){
							std::cin>>a>>b;
							clear();
							std::cout<<a<<" + "<<b<<" = "<<a+b;

						}
						break;
					
					case 2:			//Subtraction
						run = take(0);
						if (run){
							std::cin>>a>>b;
							clear();
							std::cout<<a<<" - "<<b<<" = "<<a-b;
						}
						break;
					
					case 3:			//Multiplication
						run = take(1);
						if (run){
							std::cin>>a>>b;
							clear();
							std::cout<<a<<" X "<<b<<" = "<<a*b;
						}
						break;
					
					case 4:			//Division
						run = take(1);
						if (run){
							std::cin>>a>>b;
							clear();
							if(b == 0){std::cout<<a<<" / "<<b<<" = "<<"INFINTY";}//print infinity if b is zero
							else{std::cout<<a<<" / "<<b<<" = "<<a/b;}			//else print the division
						}
						break;
					
					default:						//In case the user does not select an option
						std::cout<<"Error! No option selected";
				}
				getch();
			}
		}
		
		bool take(bool premium_feature){
			clear();
			bool taking_values = true;
			if (premium_feature)//if this is a premium feature, ask activator, if not, skip next line
			taking_values = activator();
			
			if(taking_values)
			std::cout<<"Give two values\n";
			
			return taking_values;
		}
};


void f11key(){						//Pressing to maximize the window
	// Send F11 key press
    keybd_event(VK_F11, 0, 0, 0);
    // Send F11 key release
    keybd_event(VK_F11, 0, KEYEVENTF_KEYUP, 0);
}

void intro()						//my introduction
{
	std::cout << "        ^: ~?777?????????????7777777777~ :^       \n"<<
	"      .7Y?.YBBBBBBBPPPBBBGGPYY5PGGGGGGGJ:J5!      \n"<<
	"      ^5J^ 5BBBBBBY!~!5BBGP?!~!5PPPPPPGY !Y5:     \n"<<
	"     .JJ~  5BBBBBBG5Y5GBBGPPYY5PPPPPPPGY  !Y7     \n"<<
	"     ^P7  .PBBGPGGBBBBBGP55PGGPPP55PPPGY  .J5.    \n"<<
	"     ~J!  .PB5?7?YBBBG577~77YPP5?77?PPGY  .7J:    \n"<<
	"     !7!.  5BPYJYPBBBB57!~!!YPPPJ?JYPPGY  :7?^    \n"<<
	"     :J7   YBBBBBBBBGPY?7?7?J5PPGPPPPPGJ  :??     \n"<<
	"      7?!  ?BBBBBGPYJJ??77?JJJJY5PPPPPG7 .!J~     \n"<<
	"      .J7! ^BBBG5JJ?JJ?!!~!?JJJJJJ5PPPP^.7?7.     \n"<<
	"       ^JJ  JPYJ?JJJJJJ??7?JJJJJJJJJYPJ:?Y?:      \n"<<
	"   ^!.  .!!J:7JJJJJJJJJ7!!7?JJJJJJJJJ!~J?~  .!^   \n"<<
	" .::55!:. ^~::7JJJJJJJJ7!!!?JJJJJJJ?~.^~:.^7P5::. \n"<<
	" .!5PPJ7~:   ..~JJJJJJ7???7?7?JJJJ7:..  ^7J5GP5!. \n"<<
	"   .:J#5777.    :!?JJJ!!!!!7~JJJ7:     7775#J:.   \n"<<
	"     75!^^^::..   .~7?JJJJJJ?7~:    .::^^^!57     \n"<<
	"      .:^~~~!7!~~:.  .:~!!~^....:^~!~~~~~~^:      \n"<<
	"         ..:^^!!7777~~::::::^~!777!!^^::..        \n"<<
	"               ..:^~!!!77777?77~^:.               \n"<<
	"                    ..:::^:::.       "<<
	"\n\n             S U I T  P E S H A W A R\n\n"<<
	"Name: Hamza Bin Zafar "<<
	"\nREG: SU-22-01-002-019"<<
	"\nDeparrtment: B.sc Software Engineering"<<
	"\nProject : Calculator with classes and trial and premium versions\n"<<
	"\nPassword to activate the app : activate\n\n";
}


int main(){
	
	f11key();
	intro();
	getch();

	calculator obj;
	
	
	return 0;
}