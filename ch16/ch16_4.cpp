// ch16_4.cpp
// 不恰当的虚函数
/*calling test(bc)
in base calss, int x = 1
in base calss, int x = 2
calling test(sc)
in base calss, int x = 1
in base calss, int x = 2

subclass类继承了base中的void fn（int x），尽管标识为virtual，但它在基类与子类中都指的是同一个成员函数
subclass又自己定义了一个成员，但没有设计同一函数的多种行为，即没有涉及多态，编译看见b.fn(i)的调用，分析到
fn（i）只有在base类中定义的一个版本，无论是基类对象还是子类对象，调用的都是base：：fn,不存在多态，也就无需迟后编联
接下来编译又看见b.fn(f)的调用，分析到子类对象也是基类对象，所以在test(Base& b)中，b是作为base类对象被匹配的，
b.fn(f);只在base类中寻求匹配，除非所匹配的函数是多态的才考虑调用b的对象类型中的徐函数。编译在先期编联时，成功将
fn（f）通过类型隐士转换，匹配了Base::fn(int).如果不能进行隐士转换而匹配，将以编译报错来回答。作为先期编联，b是base类对象，
编译绝对不会去尝试寻求和子类的fn（float）匹配。
程序的运行结果，关键是因为不恰当的虚函数，没有构成多态，而使编译看作为先期编联。有一种例外，如果基类中的虚函数返回一个基类指针或返回一个
基类的引用，子类中的虚函数返回一个子类的指针或子类的引用，则C++将其视为同名徐函数而进行迟后编联。*/

#include <iostream>

using namespace std;

 class Base {
     public:
        virtual void fn(int x) {
            cout << "in base calss, int x = " << x << endl;
        }
 };

 class SubClass: public Base {
     public:
        virtual void fn(float x) {
            cout << "in base calss, int x = " << x << endl;
        }      
 };


 void test(Base& b)
 {
     int i = 1;
     b.fn(i);
     float f = 2.0;
     b.fn(f);
 }

 int main()
 {
     Base bc;
     SubClass sc;

     cout << "calling test(bc)\n";
     test(bc);
     cout << "calling test(sc)\n";
     test(sc);   
 }
