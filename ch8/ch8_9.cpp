// ch8_9.cpp

#include <iostream>
#include <stdlib.h>
//#include <alloc.h>  TC和BC中用的头文件

using namespace std;

int main()
{
    int arraysize;
    int *array;
    cout << "please input a number of array elements:\n";
    cin >> arraysize;
    
    if ((array = new int[arraysize]) == NULL) {
        cout << "can't allocate";
        exit(1);
    }

    for (int count = 0;  count < arraysize; count++)
        array[count] = count * 2;
    
    for (int count = 0;  count < arraysize; count++)
        cout << array[count] << " ";
    
    cout << endl;

    delete [] array;

}