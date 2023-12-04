#include<iostream>

using namespace std;

int main()
{
    int array[10], n, item;

    cout << "Enter the size of array: ";
    cin >> n;

    cout << "\nEnter elements in array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "Enter the element at the beginning: ";
    cin >> item;
    n++;
    for (int i = n; i > 0; i--)
    {
        array[i] = array[i - 1];
    }
    array[0] = item;

    cout << "Resultant array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << endl;
    }

    return 0;
}
