#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

enum enchoose { stone = 1, paper = 2, scissors = 3 };

int read(string message)
{
	int num;
	do
	{
		cout << message << endl;
		cin >> num;

	} while (num > 11 || num < 0);

	return num;
}

string theWenner(int playr, int computer)
{
	enchoose choose;
	if (playr == enchoose::paper && computer == enchoose::stone)
	{
		return "playr";
	}

	else if (playr == enchoose::stone && computer == enchoose::scissors)
	{
		return "playr";
	}

	else if (playr == enchoose::scissors && computer == enchoose::paper)
	{
		return "playr";
	}

	else if (computer == enchoose::paper && playr == enchoose::stone)
	{
		return "computer";
	}

	else if (computer == enchoose::stone && playr == enchoose::scissors)
	{
		return "computer";
	}

	else if (computer == enchoose::scissors && playr == enchoose::paper)
	{
		return "computer";
	}

	else
	{
		return "No wonner";
	}
}

void colour(string ownner)
{
	if (ownner == "computer")
	{
		cout << "\a";
		system("color 4F");
	}

	else if (ownner == "playr")
	{
		system("color 2F");
	}

	else
	{
		system("color 6F");
	}
}

int randy()
{
	int randomNum = rand() % (3 - 1 + 1) + 1;

	return randomNum;
}

string coorect(int num)
{
	enchoose choose;

	if (num == enchoose::paper)
	{
		return "paper";
	}

	else if (num == enchoose::scissors)
	{
		return "scissors";
	}

	else if (num == enchoose::stone)
	{
		return "stone";
	}
}

int counter_the_wenner(string weenner, string weenr_counter)
{
	int weenr_counter2 = 0;

	if (weenner == weenr_counter)
	{
		weenr_counter2++;
	}

	return weenr_counter2;
}

void levels_of_the_game(int rounds, int& counter_playr, int& counter_computer, int& counter_drow)
{
	//int computer_choose = randy();
	int playr_choose;

	for (int i = 0; i < rounds; i++)
	{

		cout << "ROUND[" << i + 1 << "] Bigines :\n";
		cout << "what is your choose : [1] = stone : [2] =paper : [3] =scissors: ";
		cin >> playr_choose;
		int computer_choose = randy();
		string weenr = theWenner(playr_choose, computer_choose);
		colour(weenr);
		cout << "\n----------------------- Round [" << i + 1 << "]------------------------\n";
		cout << "playr choice : " << coorect(playr_choose) << endl;
		cout << "computer choice: " << coorect(computer_choose) << endl;
		cout << "Round wenner : " << weenr << endl;
		cout << "--------------------------------------------------------------------\n\n";
		counter_playr += counter_the_wenner(weenr, "playr");
		counter_computer += counter_the_wenner(weenr, "computer");
		counter_drow += counter_the_wenner(weenr, "No wonner");
	}
}

string theFinalWenner(int counter_playr, int counter_computer, int  counter_drow)
{
	if (counter_playr > counter_computer)
	{
		return "playr";
	}

	else if (counter_computer > counter_playr)
	{
		return "computer";
	}

	else
	{
		return "No wenner";
	}
}

void print_the_final_shape(int count, int counter_playr, int counter_computer, int counter_drow)
{
	cout << "\t\t\t-------------------------------------------------------------\n\n";
	cout << "\t\t\t------ ++++ GAME OVER ++++ ------------------------------\n\n";
	cout << "\t\t\t-------------------------------------------------------------\n\n";

	cout << "\t\t\tthe Game Rond : [" << count << "]" << endl;
	cout << "\t\t\tthe playr round : [" << counter_playr << "]" << endl;
	cout << "\t\t\tthe computer round : " << counter_computer << endl;
	cout << "\t\t\tthe drow round :[" << counter_drow << "]" << endl;
	cout << "\t\t\tthe final wenner : " << theFinalWenner(counter_playr, counter_computer, counter_drow) << endl;

	cout << "\t\t\t-------------------------------------------------------------\n\n";
	cout << "\t\t\t------ ++++ GAME OVER ++++ ---------------------------------\n\n";
	cout << "\t\t\t-------------------------------------------------------------\n\n";
}

void the_finishe(int counter_playr, int counter_computer, int counter_drow)
{
	char continuee;
	do
	{
		int count = read("please enter how round you want : ");
		levels_of_the_game(count, counter_playr, counter_computer, counter_drow);
		print_the_final_shape(count, counter_playr, counter_computer, counter_drow);
		counter_playr = 0;
		counter_computer = 0;
		counter_drow = 0;
		cout << "\n\n\t\t\tdo you want to play ageain enter y or Y if you dont enter N :";
		cin >> continuee;

		if (continuee == 'y' || continuee == 'Y')
		{
			system("cls");
		}

	} while (continuee != 'N');
}

int main()
{
	srand((unsigned)time(NULL));
	int counter_playr = 0;
	int counter_computer = 0;
	int counter_drow = 0;

	the_finishe(counter_playr, counter_computer, counter_drow);

	return 0;
}