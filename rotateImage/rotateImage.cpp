#include <vector>
/**
 * Intuitive solution: draw out the matrix and realize you are switching the top left w top right,
 * top right w bottom right, bottom right w bottom left, and bottom left w top left while the is done in 
 * O(n), it does not rely on mathematics. Another solution is doing matrix operations, i.e.
 * transopose (swapping MxN to NxM)and reverse(mirroring so swap left w right). while this 
 * is technically worse time complexity O(2n), it involves mathematics and the algorithms used
 * can be reused in other places/problems. 
*/
class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0, matrixEnd = matrix.size()-1; matrixEnd > j; ++j, --matrixEnd)
            {
                std::swap(matrix[i][j], matrix[i][matrixEnd]);
            }
        }
        int Top = 0, Right = matrix.size()-1;
        for(int Bottom = matrix.size()-Top-1;Top <= Bottom; ++Top, --Right)
        {
            int temp = Bottom;
            for(int Left = 0; Left < Right; ++Left, --temp)
            {
                std::swap(matrix[Top][Left], matrix[temp][Right]);
            }
        }
    }
};