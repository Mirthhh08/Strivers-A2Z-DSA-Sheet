#include <bits/stdc++.h>
using namespace std;

// bruteforce appraoch
// T.C. :- O(N*N)
//  S.C. :- O(N*N)
void rotateby90(vector<vector<int>> &matrix)
{
    vector<vector<int>> temp;
    temp = matrix;
    int row = 0;
    int col = 0;
    for (int j = temp[0].size() - 1; j >= 0; j--)
    {
        for (int i = 0; i < temp.size(); i++)
        {
            matrix[row][col++] = temp[i][j];
        }
        row++;
        col = 0;
    }
}

// optimal appraoch
// T.C. :- O(N*N)
// S.C. :- O(1)
void rotateby90_optimal(vector<vector<int>> &matrix)
{
    // transpose the matrix

    for (int i = 0; i < matrix.size() - 1; i++)
    {
        for (int j = i + 1; j < matrix[0].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    int low = 0, high = matrix.size() - 1;

    while (low <= high)
    {
        for (int i = 0; i < matrix[0].size(); i++)
        {
            swap(matrix[low][i], matrix[high][i]);
        }

        low++;
        high--;
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    // rotateby90(matrix);
    rotateby90_optimal(matrix);

    for (auto it : matrix)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }

        cout << endl;
    }
    return 0;
}