#include <bits/stdc++.h>
using namespace std;

// brute force appraoch
// T.c. :- O( (N * M ) * (N + M)) + O(N * M)
// S.C. :- O(1)

vector<vector<int>> markZero(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int k = 0; k < matrix.size(); k++)
                {
                    if (matrix[k][j] != 0)
                        matrix[k][j] = -1;
                }

                for (int k = 0; k < matrix[0].size(); k++)
                {
                    if (matrix[i][k] != 0)
                        matrix[i][k] = -1;
                }
            }
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

// better force appraoch
// T.c. :- O( (N * M ) + O(N * M)
// S.C. :- O(N + M)

vector<vector<int>> markZero_better(vector<vector<int>> &matrix)
{
    vector<int> row(matrix.size(), 0), col(matrix[0].size(), 0);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 1)
            {
                // for row
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {

            if (row[i] == 1 || col[j] == 1)
                matrix[i][j] = 1;
        }
    }

    return matrix;
}

// better force appraoch
// T.c. :- O( (N * M ) + O(N * M)
// S.C. :- O(1)

vector<vector<int>> markZero_optimal(vector<vector<int>> matrix)
{
    int col0 = 1;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;

                if (j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }

    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] != 0)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
    }

    if(matrix[0][0] == 0)
    {
        for(int j = 0; j<matrix[0].size(); j++)
        {
            matrix[0][j] = 0;
        }
    }


    if(col0 == 0)
    {
        for(int i = 0; i<matrix.size(); i++)
        {
            matrix[0][i] = 0;
        }
    }
    
    return  matrix;
}
int main()
{

    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 0, 7},
                                  {8, 9, 4, 6},
                                  {8, 4, 5, 0}};

    // vector<vector<int>> ans = markZero(matrix);

    // vector<vector<int>> ans = markZero_better(matrix);

     vector<vector<int>> ans = markZero_optimal(matrix);

    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}