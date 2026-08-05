#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int n = 5;

    for (int i = 0; i < n; i ++) 
    {
        for (int j = 0; j < n*n; j ++) 
        {
            for (int k = 0; k < j; k ++) 
            {
                sum ++;
            }
        }
    }

    cout << sum;
}