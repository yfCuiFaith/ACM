#include<iostream>
#include<cstdio>
using namespace std;
int main()
{   
    int n(0);
    int arr[100][100], flag[100][100][100];
    
	cin >> n;
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < n; j++)
    		scanf("%d", &arr[i][j]);
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            flag[i][j][j] = arr[i][j];
            for(int k = j + 1; k < n; k++)
            {
                flag[i][j][k] = flag[i][j][k - 1] + arr[i][k];
            }
        }
    }
    
	int max(0), temp(0);
    for(int j = 0; j < n; j++)
    {
        for(int k = j; k < n; k++)
        {
            temp = 0;
            for(int i = 0; i < n; i++)
            {
                temp += flag[i][j][k];
                if(temp < 0)
                    temp = 0;
                else if(temp > max)
                    max = temp;
            }
        }
    }
    cout << max << endl;
    return 0;
}

