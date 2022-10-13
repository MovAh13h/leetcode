class Operation {
public:
  int row1, row2, col1, col2, val;
  Operation(int r1, int r2, int c1, int c2, int v) {
    row1 = r1;
    row2 = r2;
    col1 = c1;
    col2 = c2;
    val = v;
  }
};

class SubrectangleQueries {
private:
  vector<vector<int>> rect;
  vector<Operation> ops;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
      rect = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
      Operation o(row1, row2, col1, col2, newValue);
      ops.push_back(o);
    }
    
    int getValue(int row, int col) {
      const int opsSize = ops.size();
      int i;
      for (i = opsSize - 1; i >= 0; --i) {
        Operation op = ops[i];
        
        if (row >= op.row1 && row <= op.row2 && col >= op.col1 && col <= op.col2) {
          return op.val;
        }
      }
      
      return rect[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */