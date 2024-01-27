#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the character array: ";
    cin >> n;

    char* a = new char[n];
    cout << "Enter the characters in the array: ";
    for(int i=0; i<n; i++)
        cin >> a[i];

    int numSubsets = pow(2,n);
    char** subsets = new char*[numSubsets];
    for(int i=0; i<numSubsets; i++)
        subsets[i] = new char[n];

    for(int i=0; i<numSubsets; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i & (1 << j))
                subsets[i][j] = a[j];
            else
                subsets[i][j] = '-';
        }
    }

    cout << "All subsets: " << endl;
    for(int i=0; i<numSubsets; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(subsets[i][j] != '-')
                cout << subsets[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=0; i<numSubsets; i++)
        delete[] subsets[i];
    delete[] subsets;
    delete[] a;

    return 0;
}
