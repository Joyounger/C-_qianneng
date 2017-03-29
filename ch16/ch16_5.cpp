// ch16_5.cpp
// 不恰当的虚函数


//程序的运行结果，关键是因为不恰当的虚函数，没有构成多态，而使编译看作为先期编联。有一种例外，如果基类中的虚函数返回一个基类指针或返回一个
//基类的引用，子类中的虚函数返回一个子类的指针或子类的引用，则C++将其视为同名徐函数而进行迟后编联。*/
// 输出
// this is base calss
// this is sub calss


#include <iostream>

using namespace std;

 class Base {
     public:
        virtual Base* afn() {
            cout << "this is base calss" << endl;
            return this;
        }
 };

 class SubClass: public Base {
     public:
        virtual SubClass* afn() {
            cout << "this is sub calss" << endl;
            return this;
        }      
 };


 void test(Base& x)
 {
     Base* b;
     b=x.afn();
 }

 int main()
 {
     Base bc;
     SubClass sc;


     test(bc);

     test(sc);   
 }
