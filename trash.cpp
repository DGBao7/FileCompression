#include <iostream>

using namespace std;

void swap(int a , int b)
{
    int bf = a;
    a = b;
    b = bf;
}

int main() 
{   
    int i = 5;
    int j = 10;
    std::cout << i << " " << j;

    std::cout << "\n";
    swap(i , j);
    std::cout << i << " " << j;
}