#include "iostream"
#include "thread"
#include "string"
#include "chrono"
#include "cctype"


int TypingSpeed = 15; 		//deafult typing speed

class AI{
	private:
        std::string intro {
            "Hello, I am Chatty Math, your mathematical assistant!\n\n"
            "You can ask me to perform basic arithmetic operations like addition, subtraction,"
            "multiplication, and division on numbers. Just provide the numbers and the operation,"
            "and I'll give you the result.\n\nIMPORTANT!\n"
            "=>Remember to separate the numbers and the operator with spaces for accurate results.\n"
            "=>If you're specifying multiple numbers, please limit it to 2 at the Maximum.\n"
            "=>Keep in mind that I can't handle complex expressions with parentheses or more than two numbers.\n\n"
            "Let's get started! How can I assist you today?"
        };
		std::string userMessage;
		std::string split1, split2, split3, split4, split5, split6, split7, split8, split9, split10,
                    split11, split12, split13, split14, split15, split16, split17, split18, split19,
                    split20;

        int operation, countStart, splitMax;
        float val1=0, val2=0;
        bool val1_is_empty {true}, val2_is_empty {true};
        bool numError {false}, operatorError {false}, wordError {false}, numRequired {false};		
		



    



    void out(std::string theString){                //Chat GPT like output
        for(auto i : theString){
            std::this_thread::sleep_for(std::chrono::milliseconds(TypingSpeed));
            std::cout<<i;
        }
    }








    void assignNum(int start, int length){              //seperating values for easy operatioins
        std::string temp = userMessage.substr(start, length);
        if (val1_is_empty){
            val1 = std::stof(temp);
            val1_is_empty = false;
        }
        else if(val2_is_empty){
            val2 = std::stof(temp);
            val2_is_empty = false;
            numRequired = true;
        }
        else {
            numError = true;            //Max numbers reached
            numRequired = true;
        }
    }









    void assignWord(int start, int length){                 //Creating a dictionary for easy search
        std:: string temp = userMessage.substr(start, length);
        if (split1.empty()){
        split1 = temp;
        splitMax = 1;           //SplitMax is used to know how many split indexes have data
        }
        else if (split2.empty()){
        split2 = temp;
        splitMax = 2;
        }
        else if (split3.empty()){
        split3 = temp;
        splitMax = 3;
        }
        else if (split4.empty()){
        split4 = temp;
        splitMax = 4;
        }
        else if (split5.empty()){
        split5 = temp;
        splitMax = 5;
        }
        else if (split6.empty()){
		split6 = temp;
        splitMax = 6;				
		}
		else if (split7.empty()){
		split7 = temp;
        splitMax = 7;
		}
		else if (split8.empty()){
		split8 = temp;
        splitMax = 8;
		}
		else if (split9.empty()){
		split9 = temp;
        splitMax = 9;
		}
		else if (split10.empty()){
		split10 = temp;
        splitMax = 10;
		}
		else if (split11.empty()){
		split11 = temp;
        splitMax = 11;
		}
		else if (split12.empty()){
		split12 = temp;
        splitMax = 12;
		}
		else if (split13.empty()){
		split13 = temp;
        splitMax = 13;
		}
		else if (split14.empty()){
		split14 = temp;
        splitMax = 14;
		}
		else if (split15.empty()){
		split15 = temp;
        splitMax = 15;
		}
		else if (split16.empty()){
		split16 = temp;
        splitMax = 16;
		}
		else if (split17.empty()){
		split17 = temp;
        splitMax = 17;
		}
		else if (split18.empty()){
		split18 = temp;
        splitMax = 18;
		}
		else if (split19.empty()){
		split19 = temp;
        splitMax = 19;
		}
		else if (split20.empty()){
		split20 = temp;
        splitMax = 20;
		}
        else{
            wordError = true;       //Max word length reached
        }
    }







    void splitter(){               //Breaking the users given string and saving in a logical form
        for (int j = 0; j < userMessage.size(); j++){
            auto i = userMessage[j];
            if (isspace(i)){continue;}        //Blank space skip
            if (i == '!'){break;}
            if (isdigit(i)){                  //Digits checker
                countStart = j;
                while (true){
                    j++;
                    if (j >= userMessage.size()){break;}
                    i = userMessage[j];
                    if (i == '!'){break;}     //---Line ending checker

                    if (isdigit(i) || i=='.'){continue;}
                    else {break;}
                }
                assignNum(countStart, j - countStart);    //Saving the float 
            }
            if(isalpha(i)){                   //Characters checker
                countStart = j;
                while (true){
                    j++;
                    if (j >= userMessage.size()) {break;}

                    i = userMessage[j];
                    if (i == '!'){break;}     //---Line ending checker

                    if (isalpha(i)){continue;}
                    else {break;}
                }
                assignWord(countStart, j - countStart);      //Saving the words 
            }
            else if (i=='*' || i=='/' || i=='+' || i=='-'){      //Operator checker
                assignWord(j, 1);               //Saving operator 
            }
        }
    }








    bool decider(std::string temp){                           //Checks if the given string is present
        if (temp == split1 && splitMax >= 1){return true;}
        if (temp == split2 && splitMax >= 2){return true;}
        if (temp == split3 && splitMax >= 3){return true;}
        if (temp == split4 && splitMax >= 4){return true;}
        if (temp == split5 && splitMax >= 5){return true;}
        if (temp == split6 && splitMax >= 6){return true;}
        if (temp == split7 && splitMax >= 7){return true;}
        if (temp == split8 && splitMax >= 8){return true;}
        if (temp == split9 && splitMax >= 9){return true;}
        if (temp == split10 && splitMax >= 10){return true;}
        if (temp == split11 && splitMax >= 11){return true;}
        if (temp == split12 && splitMax >= 12){return true;}
        if (temp == split13 && splitMax >= 13){return true;}
        if (temp == split14 && splitMax >= 14){return true;}
        if (temp == split15 && splitMax >= 15){return true;}
        if (temp == split16 && splitMax >= 16){return true;}
        if (temp == split17 && splitMax >= 17){return true;}
        if (temp == split18 && splitMax >= 18){return true;}
        if (temp == split19 && splitMax >= 19){return true;}
        if (temp == split20 && splitMax >= 20){return true;}
        else{return false;}
    }








    void operationDecider(){                        // Simplifies the commands by checking for the operations required
        if (numError == false && wordError == false){
            if (decider("add") || decider("Add") || decider("ADD") || decider("addition") || decider("Addition") || decider("sum") || decider("Sum") || decider("SUM") || decider("+")){
                operation = 1;
            }
            else if (decider("sub") || decider("Sub") || decider("SUB") || decider("subtract") || decider("Subtract") || decider("subtraction") || decider("Subtraction") || decider("minus") || decider("Minus") || decider("-")){
                operation = 2;
            }
            else if (decider("multiply") || decider("Multiply") || decider("multi") || decider("Multi") || decider("MULTI") || decider("times") || decider("Times") || decider("TIMES") || decider("*")){
                operation = 3;
            }
            else if(decider("div") || decider("Div") || decider("DIV") || decider("divide") || decider("Divide") || decider("/")){
                operation = 4;
            }
            else{
                operatorError = true;
            }
        }
        else{
            operation = 0;
        }
    }









    void AIOutput(){
        if (numError || wordError || operatorError){        //Messages to inform the user if any type of error occurs
                 if (numError == true && wordError == true && operatorError == true){out("\nI apologize but maximum length for typing a sentence is 20, maximum numbers you can do operations on is 2. Additionally, i coulld not spot any operation(i.e. Add, Subtract, Multiply, divide) that was needed to be done.");}
            else if (numError == true && wordError == true && operatorError == false){out("\nI apologize but maximum length for typing a sentence is 20, maximum numbers you can do operations on is 2.");}
            else if (numError == true && wordError == false && operatorError == true){out("\nI apologize but the number of maximum values that you can do operation on is 2. Additionally, i coulld not spot any operation(i.e. Add, Subtract, Multiply, divide) that was needed to be done.");}
            else if (numError == true && wordError == false && operatorError == false){out("\nI apologize but the number of maximum values that you can do operation on is 2. You cannot do operations on more than 2 values.");}
            else if (numError == false && wordError == true && operatorError == true){out("\nI apologize but maximum length for typing a sentence is 20. Additionally, i coulld not spot any operation(i.e. Add, Subtract, Multiply, divide) that was needed to be done.");}
            else if (numError == false && wordError == true && operatorError == false){out("\nI apologize but the maximum word length is 20 words per chat. You cannot type more than 20 words.");}
            else if (numError == false && wordError == false && operatorError == true){out("\nI apologize but you need to specify what operations you would like to do with your numbers provided, i.e. Add, Subtract, Multiply or divide.");}
            else if (numError == false && wordError == false && operatorError == false){out("\nAn unexpected error occured. I am apologize for any inconvenience caused.");}
        }
        else if (operation == 1){              //Addition
            out("The Addition of the number ");
            std::cout<<val1;
            out(" and the number ");
            std::cout<<val2;
            out(" results to ");
            std::cout<< val1 + val2;
            out("\nIf you have any other problems, feel free to ask.");
        }
        else if (operation == 2){           //Subtraction
            out("The subtraction of the number ");
            std::cout<<val1;
            out(" and the number ");
            std::cout<<val2;
            out(" results to ");
            std::cout<< val1 - val2;
            out("\nIf you have any other problems, feel free to ask.");
        }
        else if (operation == 3){           //Multiplication
            out("The multiplication of the number ");
            std::cout<<val1;
            out(" and the number ");
            std::cout<<val2;
            out(" results to ");
            std::cout<< val1 * val2;
            out("\nIf you have any other problems, feel free to ask.");
        }
        else if (operation == 4){           //Division
            out("The division of the number ");
            std::cout<<val1;
            out(" and the number ");
            std::cout<<val2;
            out(" results to ");
            if (val2 == 0){             //Division safety, instead of program crash and no value it gives a relevant answer
                out("INFINITY.");
            }
            else{std::cout<< val1 / val2;}      //Proceeding output if no division by 0
            out("\nIf you have any other problems, feel free to ask.");
        }
        else{       // Message if somehow no option is selected
            out("There was an unexpected error while deciding the answer. I apologize for any inconvenience caused.");
        }
    }







    void dataReset() {
		val1 = 0;
		val2 = 0;
		val1_is_empty = true;
		val2_is_empty = true;
		numError = false;
		operatorError = false;
		wordError = false;
		numRequired = false;
		operation = 0;
		splitMax = 0;
		split1 = "";
		split2 = "";
		split3 = "";
		split4 = "";
		split5 = "";
		split6 = "";
		split7 = "";
		split8 = "";
		split9 = "";
		split10 = "";
		split11 = "";
		split12 = "";
		split13 = "";
		split14 = "";
		split15 = "";
		split16 = "";
		split17 = "";
		split18 = "";
		split19 = "";
		split20 = "";
    }









    void AIProcess() {       //Splitting into multiple functions for easiness
        splitter();             //Splitting the user input into multiple words and save as a dictionary for logical processing
        operationDecider();     //Using the dictionary to find required operation
        AIOutput();             //After logics are in clear form, give the most desirable output
        dataReset();            //Reset all values to deafult before interacting with the user
    }
        
        
    public:

    
    AI() {                   //Constructor with infinite loop
        std::cout<< "       Chatty Math AI Assistant\n"<<
        "       Developed in c++\n" <<
        "       Developed by Hamza Bin Zafar\n"<<
        "       Roll.no SU-22-01-002-019\n"<<
        "       2nd semester Student of Sarhad University\n"<<
        "===================================={Chatty Math AI}==============================\n";
        out(intro);
        while(true){
        	std::cout<<"\n===================================={User}==========================================\n";
            std::getline(std::cin, userMessage);
            userMessage += "!"; //This addition is to prevent any errors while reading the statement, where !is used for defining the end of the statement
            std::cout<<"\n====================================={Chatty Math AI}==============================\n";
            AIProcess();
        }
    }
    

};





int main(){             //Main with class initialization
	
	TypingSpeed = 15;
	system("color 47");
    AI session1;

    return 0;
}


