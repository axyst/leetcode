/*
    Input 
    1, 2, 3
    4, 5, 6
    7, 8, 9 


    for-loop 1 
    swap1               swap2               swap3
    1<->3               3<->9              9<->7

    3, 2, 1            9, 2, 1            7, 2, 1
    4, 5, 6    =>      4, 5, 6    =>      4, 5, 6
    7, 8, 9            7, 8, 3            9, 8, 3

    

    for-loop 2 
    swap1              swap2              swap3
    2<->6              6<->8              8<->4

    7, 6, 1            7, 8, 1            7, 4, 1
    4, 5, 2    =>      4, 5, 2    =>      8, 5, 2
    9, 8, 3            9, 6, 3            9, 6, 3
    

    output     
    7, 4, 1,
    8, 5, 2,
    9, 6, 3,
*/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int left = 0;
        int right = n-1;
        while(left<right){
            for(int i=0;i<(right-left);++i){
                swap(matrix[left][left+i], matrix[left+i][right]);
                swap(matrix[left][left+i], matrix[right][right-i]);
                swap(matrix[left][left+i], matrix[right-i][left]);
            }
            ++left;
            --right;
        }
    }
};