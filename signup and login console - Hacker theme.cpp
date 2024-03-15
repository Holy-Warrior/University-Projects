#include "iostream"
#include "string"
#include "thread"
#include "chrono"
#include "conio.h"
#include "windows.h"


void loading(std::string message, int delay=20){		// Simulate a loading bar
char load_empty[] ="{______________________________________________________________}";
char load_full[] = "{##############################################################}";
std::cout<<"\n\n" << message << "\n";
std::cout<<load_empty<<"\r";
for(auto i : load_full){
    std::cout<<i;
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}
}


void moveUP(int move_up_this_times){              // Move the cursor to the begining of previous line
// Move the cursor up one line
    int count = 0;
    while(count != move_up_this_times){
        std::cout << "\x1b[A";
        count++;
    }

    // Move the cursor to the beginning of the line
    std::cout << "\r";
}



class server{
    std::string current_user ="-";
    std::string current_password ="-";
    std::string user[100];
    std::string password[100];
    int count=-1;

    bool user_found, correct_password;

    void cls(bool serverStatus=1, bool loadingData=0){  // The information on the top


        std::string info_server;
        if(serverStatus){
        info_server="online     ";
        system("color 2");
        }else{info_server="offline    ";system("color 4");}

        std::string info_loader;
        if(loadingData){
        info_loader="loading     ";
        }else{info_loader="loaded      ";}

        system("cls");
        std::cout<<"    Server  : "<<info_server<<"|  Data       : "<<info_loader<<"|  current-user : "<<current_user<<std::endl<<
              "    cookies : disabled   |  connection : secure      |  Users  : "<<count+1<<" / 100"<<std::endl<<
              "   ________________________________________________________________________"<<std::endl<<std::endl;
    }

    public:

    void current_user_logged_in(){
        cls(1,1);
        loading("Signing you in");
        cls();
        std::cout<<"You have logged in";
        getch();
        std::cout<<"\rPress any key to logout\n";
        getch();
        cls(1,1);
        loading("Logging out");
        current_user = "-";
        current_password = "-";
        cls();

    }

    void login(){
        while(true){
        cls();
        std::cout<<"\n"<<"Write <exit> to exit\n"<<
                    " __________________________________"<<std::endl<<
                    "|              Sign in             |"<<std::endl<<
                    "|----------------------------------|"<<std::endl<<
                    "|  user name :                     |"<<std::endl<<
                    "|  password  :                     |"<<std::endl<<
                    "|                                  |"<<std::endl<<
                    "|__________________________________|";
        moveUP(3);
        std::cout<<"|  user name : ";std::cin>>current_user;
        if (current_user == "exit"){
            current_user ="-";
            break;
        }
        std::cout<<"|  password  : ";std::cin>>current_password;


        user_found = false;           // Check user in database
        correct_password = false;
        for(int i=0; i<=count && count!=-1; i++){
            if(current_user == user[i]){
                user_found = true;

                if(current_password == password[i]){                // Check if password is correct
                correct_password = true;
                }
                break;
            }
        }

        if (user_found == true && correct_password == true){
            current_user_logged_in();
            break;
        }
        else if(user_found == true && correct_password == false){
            std::cout<<"|       Wrong password!\n\n\n";
            system("color 6");
            system("pause");
            system("color 2");
        }
        else{
            current_user = "-";
            std::cout<<"|       User not found!\n\n\n";
            system("color 6");
            system("pause");
            system("color 2");
        }
        }
        
    }


    void signup(){
        while(true){
        cls();
        std::cout<<"\n"<<"Write <exit> to exit\n"<<
                    " __________________________________"<<std::endl<<
                    "|              Sign up             |"<<std::endl<<
                    "|----------------------------------|"<<std::endl<<
                    "|  user name :                     |"<<std::endl<<
                    "|  password  :                     |"<<std::endl<<
                    "|                                  |"<<std::endl<<
                    "|__________________________________|";
        moveUP(3);
        std::cout<<"|  user name : ";std::cin>>current_user;
        if (current_user == "exit"){
            current_user ="-";
            break;
        }
        std::cout<<"|  password  : ";std::cin>>current_password;


        user_found = false;           // Check user in database
        for(int i=0; i<=count && count!=-1; i++){
            if(current_user == user[i]){
                user_found = true;
                break;
            }
        }

        if (user_found == true){
            std::cout<<"|       User name is taken!\n\n\n";
            system("color 6");
            system("pause");
            system("color 2");
        }
        else{
            count++;
            user[count] = current_user;
            password[count] = current_password;
            current_user_logged_in();
            break;
        }
        }
    }


    void shutdownServer(){
        std::string temp, temp2;
        while(true){
        cls();
        system("color 9");
        std::cout<<"Admin permissions required\n"<<
                   "Admin user name     : \n"<<
                   "Admin user password : ";
        
        moveUP(1);
        std::cout<<"Admin user name     : ";std::cin>>temp;
        std::cout<<"Admin user password : ";std::cin>>temp2;

        if(temp == "admin"){
            if(temp2 == "admin"){
                cls();
                loading("Server Shutting Down");
                cls(0,0);
                break;
            }
        }
        else{
            cls();
            system("color 6");
            std::cout<<"Access denined!\n\n";
            system("pause");
        }
        }

    }
/*
menu looks like this:

choose an option, use [w] to move up, [s] to move down, [Enter] to select
==>    login
       signup
       shutdown server

*/

    int menu(){
        int hover=1;
        char move, enterkey=13;
        
        while(true){
            
            cls();
            std::cout<<"choose an option, use [w] to move up, [s] to move down, [Enter] to select\n";

            if(hover==1){std::cout<<"==>	login\n";}
            else{std::cout<<"   	login\n";}

            if(hover==2){std::cout<<"==>	signup\n";}
            else{std::cout<<"   	signup\n";}

            if(hover==3){std::cout<<"==>	shutdown server\n";}
            else{std::cout<<"   	shutdown server\n";}

            std::cout<<"\n";
            move = getch();

            if(move == 'w' || move == 'W'){
            	hover--;
            	if(hover==0)
            	hover=3;
		    }
		    else if(move == 's' || move == 'S'){
		    	hover++;
		    	if(hover==4)
		    	hover=1;
		    }
		    else if(move == enterkey){
                cls();
		    	return hover;
		    }
        }
    }
    
    server(){
        bool repeat_while;
        int selection;
        while(true){
        cls(0,1);
        loading("starting server");
        cls();

        do{
            repeat_while = false;
            selection = menu();
            switch(selection){
                case 1:login(); repeat_while = true;break;
                case 2:signup(); repeat_while = true;break;
                case 3:shutdownServer();break;
        }
        }while(repeat_while);
        
        std::cout<<"Press any key to start the server";
            getch();
        }
        
    }

};


void f11key(){			//Pressing to maximize the window
	// Send F11 key press
    keybd_event(VK_F11, 0, 0, 0);
    // Send F11 key release
    keybd_event(VK_F11, 0, KEYEVENTF_KEYUP, 0);
}


int main(){
    
    f11key();
    server obj;

return 0;
}