/*Problem statement : According to the file i have received with name frontend but the problem is of DSA

You are given an N × N matrix in which every cell is colored black or white. Columns are numbered from 0
to N-1 (from left to right). This coloring is represented by a non-empty array of integers A. If the K-th
number in the array is equal to X then the X lowest cells in the K-th column of the matrix are black. The
rest of the cells in the K-th column are white. The task is to calculate the side length of the biggest black
square (a square containing only black cells).Write a function:class Solution { public int solution(int[] A);
}that, given an array of integers A of length N representing the coloring of the matrix, returns the side
length of the biggest black square.

test cases are in image format : refer to PDF of question
*/

// Here is my solution for this DSA problem
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // Function to calculate the side length of the biggest black square
    int solution(const vector<int>& A) {
        int n = A.size();
        vector<int> heights(n, 0);
        stack<int> s;
        int maxSize = 0;

        for (int i = 0; i < n; i++) {
            // Process elements in the stack when the current element is smaller
            while (!s.empty() && A[i] < A[s.top()]) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                int side = min(width, height);
                maxSize = max(maxSize, side);
            }
            s.push(i);
            heights[i] = A[i];
        }

        // Process remaining elements in the stack
        while (!s.empty()) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? n : n - s.top() - 1;
            int side = min(width, height);
            maxSize = max(maxSize, side);
        }

        return maxSize;
    }
};

int main() {
    Solution solution;

    // Test cases
    cout << solution.solution({1, 2, 5, 3, 1, 3}) << endl; // expected Output a/c to question should be: 2
    cout << solution.solution({3, 3, 3, 5, 4}) << endl;    // expected Output a/c to question should be: 3
    cout << solution.solution({6, 5, 5, 6, 2, 2}) << endl; // expected Output a/c to question should be: 4

    return 0;
}