/*
题目描述
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
      bool visited[rows*cols];
      int i, j;
      for(i=0 ; i<rows*cols ; i++)
        visited[i] = false;
      return movingCount_core(rows, cols, 0, 0, threshold, visited);

    }
    int movingCount_core(int rows, int cols, int row, int col, int threshold, bool *visited)
    {
      int count = 0;
      if(row>=0 && row<rows && col>=0 && col<cols &&
         visited[row*cols+col]==false && is_valid(threshold, row, col))
      {
        visited[row*cols+col] = true;
        count = movingCount_core(rows, cols, row-1, col, threshold, visited) +
                movingCount_core(rows, cols, row+1, col, threshold, visited) +
                movingCount_core(rows, cols, row, col-1, threshold, visited) +
                movingCount_core(rows, cols, row, col+1, threshold, visited) + 1;
      }
      return count;
    }
    bool is_valid(int threshold, int row, int col)
    {
      int sum = compute_bits(row) + compute_bits(col);
      return sum<=threshold;
    }
    int compute_bits(int x)
    {
      int sum = 0;
      while(x>0)
      {
        sum += x % 10;
        x /= 10;
      }
      return sum;
    }
};
