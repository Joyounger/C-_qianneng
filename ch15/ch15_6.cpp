// ch15_6.cpp
// 一个静态函数访问对象中成员的方法：

#include <iostream>
#include <string.h>

class Student {
    public:
        Student(char* pName);
        ~Student();
        static Student* findname(char* pName);
    protected:
        static Student* pFirst;
        Student* pNext;
        char name[40];
};

Student* Student::pFirst = 0;
Student::Student(char* pName); {
    stncpy(name, pName);
    name[sizeof(name)-1] = '\0';
    pNext = pFirst;
    pFirst = this;
}

Student::~