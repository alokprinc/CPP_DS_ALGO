#include <iostream>
using namespace std;
// checking position where rat can go or not

bool isSafe(int **mazeArr, int x, int y, int n)
{
    if (x < n && y < n && mazeArr[x][y] == 1)
    {
        return true;
    }
    return false;
}


bool ratInMaze(int **mazeArr, int x, int y, int n, int **solArr)
{

    if (x == n - 1 && y == n - 1)
    {
        solArr[x][y] = 1;
        return true;
    }

   // if rats mavement is safe the we will move to right and down check we got the solution or not. 
    if (isSafe(mazeArr, x, y, n))
    {
        solArr[x][y] = 1;

           //if we do not find solution we will backtrack and come back to previous position and set value zero again 

        if (ratInMaze(mazeArr, x + 1, y, n, solArr))
        {
            return true;
        }
        if (ratInMaze(mazeArr, x, y + 1, n, solArr))
        {
            return true;
        }
        solArr[x][y] = 0; // backtracking //
        return false;
    }
    return false;
}

int main()
{

    int n;
    cin >> n;

    // dymamically alocating memory to a 2D Array

    int **mazeArr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        mazeArr[i] = new int[n]; /// Memory Allocation ///
    }

    // Providing Input//
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mazeArr[i][j];
        }
    }

    //  Making solution Array //

    int **solArr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solArr[i] = new int[n];

        //Providing Input in Solution Array //
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
        }
    }

    if (ratInMaze(mazeArr, 0, 0, n, solArr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArr[i][j]<<" ";
            } cout<<endl;
        }
    }
}


// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1