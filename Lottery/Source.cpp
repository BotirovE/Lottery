#include <iostream>
#include <string>
#include <ctime>
using namespace std;
//Node for players
struct Player{
	int combination[6];
	//long long int key;
	string name = "empty";
	Player* next= NULL;
};
//array of prime numbers to generate unique keys
int prime[50] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,31, 37, 41, 43, 47, 53, 59, 61, 67, 71,73, 79, 83, 89, 97, 101, 103, 107, 109, 113,127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229};


#include "Hashtable.h"
int main()
{
	srand((unsigned int)time(NULL));
	//list of players
	Player player[30];//it might be any number like: 15 000 000
	for (int i = 0; i < 30; i++)
	{
		player[i].name = (char)(i+49);
		for (int j = 0; j < 6; j++)
		{
			player[i].combination[j] = rand() % 50;
		}
	cout << "Player " << player[i].name << " combination " << player[i].combination[0] << " " << player[i].combination[1] << " " << player[i].combination[2] << " " << player[i].combination[3] << " " << player[i].combination[4] << " " << player[i].combination[5] << endl;
	}
	// put list of players into hashtable
	Hashtable hashtable(player);
    //enter the winning combination
	int winning_combination[6];
	cout << " Enter the winning combination - " << endl;
	for (int i = 0; i < 6; i++)
		cin >> winning_combination[i];
	//Find this combination from hashtable
	hashtable.findwinners(winning_combination);


	return 0;
}