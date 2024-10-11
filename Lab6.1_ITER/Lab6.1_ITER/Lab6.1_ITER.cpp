#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <iomanip>

using namespace std;

void generateA(int a[], int k, int min, int max);
void printA(int a[], int k);
void processA(int a[], int k, int& count, int& sum);

int main()
{
    const int k = 24;
    int a[k];
    int count = 0;
    int sum = 0;

    generateA(a, k, -55, 15);
    cout << "a=";
    printA(a, k);
    processA(a, k, count, sum);
    cout << "count: " << count << endl;
    cout << "sum: " << sum << endl;
    cout << "modified:\n";
    printA(a, k);

    return 0;
}

void generateA(int a[], int k, int min, int max)
{
    std::srand(std::time(0));
    for (int i = 0; i < k; ++i)
    {
        a[i] = std::rand() % (max - min + 1) + min;
    }
}

void printA(int a[], int k)
{
    for (int i = 0;i < k;++i)
    {
        cout << std::setw(4) << a[i];
    }
    cout << std::endl;
}

void processA(int a[], int k, int& count, int& sum)
{
    count = 0;
    sum = 0;
    for (int i = 0; i < k; ++i)
    {
        if (a[i] < 0 || a[i] % 2 == 0)
        {
            sum += a[i];
            count++;
            a[i] = 0;
        }
    }
}