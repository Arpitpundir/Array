#include <bits/stdc++.h>
using namespace std;
bool findEle(vector<vector<int>> mat, int ele)
{
    int n = mat.size();
    int m = mat[0].size();
    int i = 0, j = m - 1;
    while (i >= 0 && j >= 0 && i < n && j < m)
    {
        if (mat[i][j] == ele)
        {
            return true;
        }
        else if (ele > mat[i][j])
        {
            i++;
        }
        else if (ele < mat[i][j])
        {
            j--;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            mat[i].push_back(temp);
        }
    }
    int ele;
    cin >> ele;
    if (findEle(mat, ele))
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}
