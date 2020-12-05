#include <iostream>
#include <string>
#include <vector>
using namespace std;



int RandomGenerator(int lowerBound, int upperBound)
{
	srand(time(0));
	int num = lowerBound + rand() % upperBound;
	return num;
}

void print(vector<string> vect)
{
	for (int i = 0; i < vect.size(); i++)
		cout << vect[i];
}

int main();
{
int score = 5000;
vector<string> typrstring;



int letters = 93;
for (int i = 1; i <= 5; i++)
{
	int probability = RandomGenerator(0, 100);
	if (probability < 80)
	{
		while (letter < 97 && letter > 90)
		{
			int letters = RandomGenerator(65, 122);
		}
		typrstring.push_back((char)letters);
	}
	else
	{
		 int wildGenerator = RandomGenerator(1, 2)
		 Switch(wildGenerator)
		 {
			 case 1
				 typrstring.push_back("[0 - 9]");
			 case 2
				 typrstring.push_back("[% - !]");
		 }
	}
}

 cout << "Your current points " << score << ", just type -> ";
 print(typestring)
 cout << '\n';
 
return 0;
}

