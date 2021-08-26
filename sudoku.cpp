//数独解法实现

#include <iostream>
 
using namespace std;
 
void get_valid(int **p, int row, int col, char* valid) 
{
    for (int i = 0; i < 9; i++)
        valid[p[row][i]] = 1;
 
    for (int i = 0; i < 9; i++) 
        valid[p[i][col]] = 1;
 
    int rowTemp = row - row % 3;
    int colTemp = col - col % 3;
    for (int k = 0; k < 9; k++)
        valid[p[rowTemp + k / 3][colTemp + k % 3]] = 1;
}
 
int sudoku(int **p, int depth) 
{
    if (depth == 0) {
        return 0;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (p[i][j] == 0) {
                char check[10] = { 0 };
                get_valid(p, i, j, check);
                for (int k = 1; k <= 9; k++) {
                    if (check[k] == 0)
                    {
                        p[i][j] = k;
                        depth = sudoku(p, depth -1);
                        if (depth == 0)
                            return 0;
                        p[i][j] = 0;
                        depth++;
                    }
                    if (k == 9)
                        return depth;
                }
            }
        }
    }
    return depth;
}
 
int main()
{
    int a[9][9] = { { 0, 9, 5, 0, 2, 0, 0, 6, 0 },
    { 0, 0, 7, 1, 0, 3, 9, 0, 2 },
    { 6, 0, 0, 0, 0, 5, 3, 0, 4 },
    { 0, 4, 0, 0, 1, 0, 6, 0, 7 },
    { 5, 0, 0, 2, 0, 7, 0, 0, 9 },
    { 7, 0, 3, 0, 9, 0, 0, 2, 0 },
    { 0, 0, 9, 8, 0, 0, 0, 0, 6 },
    { 8, 0, 6, 3, 0, 2, 1, 0, 5 },
    { 0, 5, 0, 0, 7, 0, 2, 8, 3 } };
 
    int **p = (int **)malloc(9 * sizeof(int *));
    for (int i = 0; i < 9; i++) {
        p[i] = a[i];
    }
 
    int depth = 0;
    for (int i = 0; i < 9 * 9; i++) {
        //cin >> p[i / 9][i % 9]; //为了测试方便，不获取输入，直接代码中填写
        if (p[i / 9][i % 9] == 0) depth++;
    }
 
    sudoku(p, depth);
 
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
 
    free(p);
    return 0;
}
