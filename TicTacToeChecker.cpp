#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

/*enum class Player
{
	White=-1,
	Black=1,
	Empty=0
};*/
/*
	Takes board as argument and returns integer that represents
	color of winner 1 is BLACK, -1 is WHITE.
	0 represents empty cell of board. (Optional all cells must be full.)
*/
int TTTwinner(const vector<vector<int> >& board){

	const int SIZE = board.size();
	int i,j,sum1=0,sum2=0,sum3=0,sum4=0;
	//cout<<"SIZE is: "<<SIZE<<endl;

	for(i=0;i<board.size();i++){
		for(j=0;j<board[i].size();j++){
			sum1+=board[i][j];
			sum2+=board[j][i];
		}
		//cout<<"In  "<<i<<". loop sum1: "<<sum1<<" sum2: "<<sum2<<endl;
		if(sum1==SIZE || sum2==SIZE)
			return 1;
		else if (sum1==-SIZE || sum2==-SIZE )
			return -1;
		sum1=sum2=0; // tekrar 0 yapmazsan nasil dogru sonucu versin!!
		sum3+=board[i][i];
		sum4+=board[i][SIZE-i];
		//cout<<"In "<<i<<". loop sum3: "<<sum3<<" sum4: "<<sum4<<endl;
	}

	if(sum3==SIZE || sum4==SIZE)
			return 1;
	else if (sum3==-SIZE || sum4==-SIZE )
		return -1;

	return 0;
}

void fillRandomly(vector<vector<int> >& v){
	srand(time(0));	//Seeds random generator with time(0) function
	for(int i=0;i<v.size();i++)
		for (int j = 0; j < v[0].size(); ++j)
			v[i][j]=rand()%3-1;
}
/*
void fillRandomlyAll(vector<vector<int> >& v){
	srand(time(0));	//Seeds random generator with time(0) function
	for(int i=0;i<v.size();i++)
		for (int j = 0; j < v[0].size(); ++j){			
			int cell=0;
			while(cell==0){
				cell=rand()%3-1;
			}
			v[i][j]=cell;
		}
}
*/
void printVector(const vector<vector<int> >& v){
	for(int i=0;i<v.size();i++){
		for (int j = 0; j < v[0].size(); ++j){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	vector<vector<int> > v(4,vector<int>(4,0)); //4x4 2D vector generated with constructor
	fillRandomly(v);
	printVector(v);
	int result=TTTwinner(v);
	if(result==1)
		cout<<"Black wins..."<<endl;
	else if(result==-1)
		cout<<"White wins..."<<endl;
	else
		cout<<"No one wins..."<<endl;

	return 0;
}