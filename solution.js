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
// Class to calculate the side length of the biggest black square

// solution of the problem using java script

class Solution {
  constructor() {
    this.maxSize = 0;
  }

  // Function to calculate the side length of the biggest black square
  solution(A) {
    let n = A.length;
    let heights = new Array(n).fill(0);
    let s = [];
    this.maxSize = 0;

    for (let i = 0; i < n; i++) {
      // Process elements in the stack when the current element is smaller
      while (s.length > 0 && A[i] < A[s[s.length - 1]]) {
        let height = heights[s.pop()];
        let width = s.length === 0 ? i : i - s[s.length - 1] - 1;
        let side = Math.min(width, height);
        this.maxSize = Math.max(this.maxSize, side);
      }
      s.push(i);
      heights[i] = A[i];
    }

    // Process remaining elements in the stack
    while (s.length > 0) {
      let height = heights[s.pop()];
      let width = s.length === 0 ? n : n - s[s.length - 1] - 1;
      let side = Math.min(width, height);
      this.maxSize = Math.max(this.maxSize, side);
    }

    return this.maxSize;
  }
}

// Test cases
let solution = new Solution();
console.log(solution.solution([1, 2, 5, 3, 1, 3])); // expected output: 2
console.log(solution.solution([3, 3, 3, 5, 4])); // expected output: 3
console.log(solution.solution([6, 5, 5, 6, 2, 2])); // expected output: 4