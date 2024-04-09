#include <vector>
//Leetcode easy. Intution: there will always be enough sandwiches for each student.
//since the student is the one that dictactes which sandwiches will be eaten, iterate
//through them first. If count reaches 0 for 1 of the sandwiches, return remainder, else return 0;
class Solution {
public:
    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
        int circles = 0;
        int squares = 0;
        for(int student: students)
        {
            if(student == 0)
                ++circles;
            else
                ++squares;
        }
        for(int sandwich: sandwiches)
        {
            if(sandwich == 0 && circles == 0)
                return squares;
            if(sandwich == 1 && squares == 0)
                return circles;
            if(sandwich == 0 && circles > 0)
                --circles;
            else if(sandwich  == 1 && squares > 0)
                --squares;
        }
        return 0;
    }
};