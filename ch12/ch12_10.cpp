//ch12_10.cpp


#include <iostream>
#include <string.h>

using namespace std;


int nextStudentId = 0;

class StudentID
{
    public:
        StudentID() {
            value = ++nextStudentId;
            cout << "assing strdent id" << value <<endl;
        }
        ~StudentID() {
             --nextStudentId;
             cout << "destructing strdent id" << value <<endl;
         }
    
    protected:
        int value;
};

class Student
{
    public:
        Student(char* pName = "noName") {
            cout << "constructing student0" << pName << endl;
            strcpy(name, pName);
            name[sizeof(name) - 1] = '\0';
            name[sizeof(name) - 1] = '\0';
        }
        
    protected:
        char name[20];
        StudentID id;
};


int main()
{
    Student s("randy");
}
        