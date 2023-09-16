class Solution {
public:
    bool dfsTraversal(vector<vector<char>>&board,int row,int col,string word,int pos){
         if(pos == word.length())return true;
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size())return false;
        if(board[row][col]!=word[pos])return false;
       
        else{
            char temp = board[row][col];
            board[row][col] = '.';
            for(int r = row-1;r<=row+1;r++){
                for(int c = col-1;c<=col+1;c++){
                    if(abs(r-row) == 1 && abs(c-col) == 1)continue;
                    if(dfsTraversal(board,r,c,word,pos+1))return true;
                }
            }
            board[row][col] = temp;
            return false;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
       for(int i = 0;i<board.size();i++){
           for(int j = 0;j<board[0].size();j++){
               if(board[i][j] == word[0] && dfsTraversal(board,i,j,word,0)){
                   return true;
               }
           }
       }
       return false;
    }

};