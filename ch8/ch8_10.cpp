#include <iostream>


using namespace std;

void mystrcpy(char* dest, const char* src)
{
    //while(*dest++ = *src++);
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
}9


int main()
{
    char a[20] = "how are you!";
    char b[20];
    mystrcpy(a, b);
    cout << b << endl;
}
