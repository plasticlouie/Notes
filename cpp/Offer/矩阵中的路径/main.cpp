/*
题目描述
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，
但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
      bool *visited = new bool[rows*cols];

      // Initializ all points to invisited
      for(int i=0 ; i<rows*cols ; i++)
      {
        visited[i] = false;
      }

      // Start from each location
      for(int row=0 ; row<rows ; row++)
      {
        for(int col=0 ; col<cols ; col++)
        {
          if(hasPath_core(matrix, rows, cols, row, col, 0, str, visited))
          {
            delete[] visited;
            return true;
          }
        }
      }
      delete[] visited;
      return false;
    }

    bool hasPath_core(char *matrix, int rows, int cols, int row, int col, int index, char *str, bool *visited)
    {
      /*
      matrix: an array with length [rows*cols]
      row: current row index
      col: current col index
      index: current char index of the given string (str)
      */
      if(str[index]=='\0'){return true;}

      if(row>=0 && row<rows && col>=0 && col<cols &&
        matrix[row*cols+col]==str[index] &&
        visited[row*cols+col]==false)
      {
        bool has_path = false;
        visited[row*cols+col] = true;
        has_path = hasPath_core(matrix, rows, cols, row+1, col, index+1, str, visited) ||
                   hasPath_core(matrix, rows, cols, row-1, col, index+1, str, visited) ||
                   hasPath_core(matrix, rows, cols, row, col+1, index+1, str, visited) ||
                   hasPath_core(matrix, rows, cols, row, col-1, index+1, str, visited);
       if(!has_path)
       {
         visited[row*cols+col] = false;
       }
       return has_path;
      }
      return false;

    }
};
