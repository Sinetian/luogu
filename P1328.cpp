#include <iostream>
using namespace std;

int game[5][5] = {0,0,1,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,1,1,0,0,0};
int a[300] , b[300];

int main()
{
	int n , na , nb;
	cin >> n >> na >> nb;
	for(int i = 0; i < na; i++)
		cin >> a[i];
	for(int i = 0; i < nb; i++)
		cin >> b[i];
	int scorea = 0 , scoreb = 0;
	for(int i = 0; i < n; i++)
	{
		scorea += game[a[i % na]][b[i % nb]];
		scoreb += game[b[i % nb]][a[i % na]];
	}
	cout << scorea << " " << scoreb << endl;
	return 0;
}