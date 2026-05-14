class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // validate all rows: O(9n)
         for(int i=0; i<9; i++){
               set<int> sr = {};
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
             if(sr.find(board[i][j]) == sr.end()){
                            sr.insert(board[i][j]); 
                        }

                        else {
                            return false;
                        }
                }
            }
        }

        // validate all columns: O(9n)
        for(int j=0; j<9; j++){
               set<int> sc = {};
            for(int i=0;i<9;i++){
                if(board[i][j] != '.'){
             if(sc.find(board[i][j]) == sc.end()){
                            sc.insert(board[i][j]);
                           
                        }

                        else {
                           
                            return false;
                        }
                }
            }
        }

        // validate all 3*3s
        for(int i=0; i<9; i+=3){
            for(int j=0;j<9;j+=3){
                set<int> s = {};
                for(int a=i;a<i+3;a++){
                    for(int b=j;b<j+3;b++){
                        if(board[a][b] != '.'){
                        if(s.find(board[a][b]) == s.end()){
                            s.insert(board[a][b]);
                           
                        }

                        else {
                            return false;
                        }
                        }
                    }
                }
            }
        }

        return true;
    }
};
