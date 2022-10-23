#include<bits/stdc++.h>
using namespace std;

string tictactoe(vector<vector<int> >& moves) {
	char board[3][3];
	int turn = 0;
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			board[i][j] = '.';
		}
	}
	

	
	for(int i = 0;i<moves.size();i++){
		int x = moves[i][0];
		int y = moves[i][1];
		if(turn%2 == 0){
			board[x][y] = 'X';
		}
		else board[x][y] = 'O';
		turn++;
		
	}
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	
	    if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')return "A";
        if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')return "A";
        if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')return "A";
        if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')return "A";
        if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')return "A";
        if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')return "A";
        if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')return "A";
        if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')return "A";
        // for the winning chance of B 
        if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')return "B";
        if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')return "B";
        if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')return "B";
        if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')return "B";
        if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')return "B";
        if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')return "B";
        if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')return "B";
        if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')return "B";
        if(moves.size() == 9 ) return "Draw";
        return "Pending";
        
}

int main(){
	
	vector<vector<int> >moves;
	int mvs;
	cin >> mvs;
	for(int i = 0;i<mvs;i++){
		vector<int>temp;
		for(int j = 0;j<2;j++){
			int m;cin >> m;
			temp.push_back(m);
		}
		moves.push_back(temp);
	}
	

	
//	for(int i = 0;i<mvs;i++){
//		for(int j = 0;j<2;j++){
//			cout << moves[i][j] <<" ";
//		}
//		cout << endl;
//	}
	
	cout << tictactoe(moves);
	
	return 0;
}
