// Backtracking

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 1st Program
// void printPermutations(string &str, int i)
// {
//     if (i >= str.length())
//     {
//         cout << str << " ";
//         return;
//     }
//     for (int j = i; j < str.length(); j++)
//     {
//         swap(str[i], str[j]);
//         printPermutations(str, i + 1);
//         swap(str[i], str[j]);
//     }
// }

bool isSafe(int maze[][4], int row, int col, int srcx, int srcy, int newx, int newy, vector<vector<bool>> &visited)
{
    if ((newx >= 0 && newx < row) && (newy >= 0 && newy < col) && maze[newx][newy] == 1 && visited[newx][newy] == false)
    {
        return true;
    }
    return false;
}
void printAllPath(int maze[][4], int row, int col, int srcx, int srcy, string &output, vector<vector<bool>> &visited)
{
    if (srcx == row - 1 && srcy == col - 1)
    {
        cout << output << "\n";
        return;
    }

    // UP
    int newx = srcx - 1;
    int newy = srcy;
    if (isSafe(maze, row, col, srcx, srcy, newx, newy, visited))
    {
        visited[newx][newy] = true;
        output.push_back('U');
        printAllPath(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }
    // Down
    newx = srcx + 1;
    newy = srcy;
    if (isSafe(maze, row, col, srcx, srcy, newx, newy, visited))
    {
        visited[newx][newy] = true;
        output.push_back('D');
        printAllPath(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }
    // Right
    newx = srcx;
    newy = srcy + 1;
    if (isSafe(maze, row, col, srcx, srcy, newx, newy, visited))
    {
        visited[newx][newy] = true;
        output.push_back('R');
        printAllPath(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }
    // Left
    newx = srcx;
    newy = srcy - 1;
    if (isSafe(maze, row, col, srcx, srcy, newx, newy, visited))
    {
        visited[newx][newy] = true;
        output.push_back('L');
        printAllPath(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }
}

int main()
{
    // 1st Program
    //  string str = "abc";
    // int i = 0;
    // printPermutations(str, i);

    // 2nd Program
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 1}};
    int row = 4;
    int col = 4;
    int srcx = 0;
    int srcy = 0;
    string output = "";
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    if (maze[0][0] == 0)
    {
        cout << "No path exits" << endl;
    }
    else
    {
        visited[srcx][srcy] = true;
        printAllPath(maze, row, col, srcx, srcy, output, visited);
    }
    return 0;
}