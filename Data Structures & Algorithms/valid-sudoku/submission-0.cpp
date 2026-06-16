class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            vector<int> hash(9,0);
            // checking for duplicates in columns
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(hash[board[i][j]-'1']==1){
                        return false;
                    }
                    hash[board[i][j]-'1']=1;
                }
            }
            // checking for rows in rows
            vector<int>hashrow(9,0);
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    if(hashrow[board[j][i]-'1']==1){
                        return false;
                    }
                    hashrow[board[j][i]-'1']=1;
                }
            }

        }
        // Check all nine 3x3 boxes
        for (int box = 0; box < 9; box++) {
            vector<int> hash(9, 0);
            int rowStart = (box / 3) * 3;  // 0, 0, 0, 3, 3, 3, 6, 6, 6
            int colStart = (box % 3) * 3;  // 0, 3, 6, 0, 3, 6, 0, 3, 6

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char c = board[rowStart + i][colStart + j];
                    if (c != '.') {
                        if (hash[c - '1'] == 1) return false;
                        hash[c - '1'] = 1;
                    }
                }
            }
        }        
        return true;

    }
};
