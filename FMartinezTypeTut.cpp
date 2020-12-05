#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <unistd.h>
using namespace std;

/*

Function that has no inputs and produces a random string. This string is not the output.
 This is the string that will be compared with the user's input. 

*/
string GenerateString() 
{
string typestring;
srand(time(0));
char converter;

int letters;
int probability; 
int wildGenerator;
for (int i = 1; i <= 5; i++)
{
	probability =  1 + rand() % 10;
	if (probability < 9)
	{
		do
		{
		 letters =  65 + rand() % (122 + 1 - 65);
		}while((letters < 97 && letters > 90));
		converter = (char)letters;
		typestring.push_back(converter);
		
		
	}
	else
	{
		 wildGenerator = 1 + rand() % 2;
		 switch(wildGenerator)
		 {
			 case 1:
				 typestring.push_back('0');
				 
				 break;
			 case 2:
				 typestring.push_back('*');
			    
				 break;
		 }
	}
}return typestring;
}
/*
This is a function where the input is the generated string and it then changes all the * and
0 into [%-!] and [0-9] respectively. This the string that the user will see in the game.
*/
string outputstring(string stringinput)
{
	string newstring;
	char wildsym = '*';
	char wildnum = '0';
	string newwildsym = "[%-!]";
	string newwildnum = "[0-9]";
	
	for (int i = 0; i < stringinput.length(); i++)
	{
		if(stringinput[i]== '*')
		{
			
			stringinput.replace(i,1, newwildsym);
			i = i+4;
			
			
		}
		else if(stringinput[i]== '0')
		{
			stringinput.replace(i,1, newwildnum);
			i = i+4;
			
		}
	}
	newstring = stringinput;
	

return newstring;	
}

/*
This is a function where the inputs are the string that was randomly generated with the * and 0 and the string that the user inputted.
This Function outsputs an integer, which is the total spelling penalty for spelling errors between the string generated and the users inputted string.
*/


int offset( string string_generated,  string userInput)
{
	int spellpenalty = 0;

	 for(int i = 0; i < string_generated.length(); i++) 
	 {		 
				 
					
				if(string_generated[i] != userInput[i])
				{	
					if(string_generated[i] == '*')  
					{
						if(isalnum(userInput[i]))
							spellpenalty = spellpenalty + abs((42 - (int)userInput[i]));
					
							
						
						
					}
					else if(string_generated[i] == '0')
					{	
						if(!isdigit(userInput[i]))
							spellpenalty = spellpenalty + abs((48 - (int)userInput[i]));
					}	
					else
						spellpenalty = spellpenalty + abs(((int)string_generated[i] - (int)userInput[i]));
				}
				 
						 
	}
return spellpenalty;
}

int main()
{

int score = 2000;
while(score > 0 && score < 5000)    //stops when the player has 0 or less points or 5000 or greater.
{
	string str = GenerateString();  //generated string that has * and 0
	
	string output = outputstring(str);  //new string that converted * and 0 to [%-!] and [0-9] in str
	string input;   //string that the user will input
	int count = 0;
	 cout << "Your current points " << score << ", just type -> " << output << ':' << " ";
	 auto start = chrono::steady_clock::now(); //time measuring start in milliseconds
	cin >> input;
	auto end = chrono::steady_clock::now();     //time measuring end
	auto mili_elapsed_secs = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	int time_penalty = mili_elapsed_secs - 10000; 
	int spell_penalty = offset(str, input); //points that will be deducted from difference in input and str;
	int total_penalty = spell_penalty + time_penalty;
	 
	cout << mili_elapsed_secs << " milliseconds, you ";
	if(time_penalty  > 0) //message if you failed time penalty
	{
		cout << "*failed* it within the interval of 10000...\n";
		score = score - time_penalty;
		count++;
	}
	else
		cout << " made it within the interval of 10000...\n";
		
	if(spell_penalty > 0) //chooses the output message if you had a spell penalty 
	{
		
		if (count ==1) // if you also had time penalty
		{
			cout<< "String offset is " << spell_penalty << ", your total penalty is " << total_penalty << "...\n";
			score = score - spell_penalty;
		}
		if(count == 0)
		{	
			cout<< "String offset is " << spell_penalty << ", your total penalty is " << spell_penalty  << "...\n";
			score = score - spell_penalty;
		}
		
		
	}
	
	if(!(time_penalty  > 0) && !(spell_penalty > 0)) // if no penalties then your score increases by 500.
		score = score + 500;
			
}		 
	cout << "Bye...";
	
	return 0;
}
