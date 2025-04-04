#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);
        
        for (int i = 0; i < 9; i++) 
        {
            for (int j = 0; j < 9; j++) 
            {
                char num = board[i][j];
                if (num == '.') continue; 

                int index = (i / 3) * 3 + (j / 3); 

               
                if (rows[i].count(num) || cols[j].count(num) || boxes[index].count(num)) 
                {
                    return false;
                }

                
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[index].insert(num);
            }
        }
        return true;
    }
};
