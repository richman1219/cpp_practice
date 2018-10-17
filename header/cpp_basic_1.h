/*
 * cpp_basic_1.h
 *
 *  Created on: 2018年10月18日
 *      Author: 其懋
 */

#ifndef HEADER_CPP_BASIC_1_H_
#define HEADER_CPP_BASIC_1_H_

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

/*template*/
template <class T>
class CWin
{
  public:
    T width, height;
  public:
    CWin(T w, T h) :width(w), height(h) {};
};


// test virtual function
class Foo1 {
public:
  virtual void show() { // 虛擬函式
    cout << "Foo1's show" << endl;
  }
};

class Foo2 : public Foo1 {
public:
  virtual void show() { // 虛擬函式
    cout << "Foo2's show" << endl;
  }
};

void showFooByPtr(Foo1 *foo) {
  foo->show();
}

void showFooByRef(Foo1 &foo) {
  foo.show();
}

class myClass
{
public:
   int d[10];

   myClass() {
      cout << "myClass 建構函式!" << endl;
   }

   myClass(myClass& obj) {
      cout << "COPY Constructor!" << endl;
   }

   ~myClass() {
      cout << "myClass 解構函式!" << endl;
   }

   void test()
   {
     printf("test myClass\n");
   }
};

/* polymorphism Difference
 * Overloading(redefinition, static biding, compile time) vs. overriding(virtual function, dynamic biding, run time)
 *
 * pure virtual function(can not used to declare and object, and derived class must have overloading function)
 * vs virtual function(can used to declare a object)
 * */

class virtual_Class
{
public:
   virtual void test()
   {
     printf("test myClass\n");
   }

   void overloading()
   {
     printf("overloading virtual_Class\n");
   }
};

#if 0
/*for the derived class to use if needed*/
void virtual_Class::test()
{
  printf("virtual test\n");
}
#endif


/*
 * inherited from virtual class, then need to define your own funtion instead
 * */
class child_myClass: public virtual_Class
{
public:
  child_myClass() {
     cout << "child_myClass 建構函式!" << endl;
  }

   ~child_myClass() {
      cout << "child_myClass 解構函式!" << endl;
   }

   /*
   void test()
   {
     virtual_Class::test();
     printf("test child_myClass\n");
   }
   */

   void overloading()
   {
     printf("overloading child_myClass\n");
   }


};




void print(myClass x)
{
    for(int i=0; i<10; i++)
        cout << x.d[i] << " ";
    cout << endl;
}



/*==========================================================*/

void test_main_1()
{
  myStrA test;
  printf("size of %d\n", sizeof(myStrA));
  printf("size of %d\n", sizeof(test.v1));
  printf("size of %d\n", sizeof(Data));
  printf("a %d\n", a);

  std::vector<int> num(8);
  num = {1, 3, 1, 1, 4, 4, 4, 4};
  int output = majorityElement(num);
  printf("output %d\n", output);



  Foo1 f1;
  Foo2 f2;

  Foo1 *f1Ptr = &f2;
  // 動態繫結
  cout << "\t[Info] Show Foo By Ptr:" << endl;
  showFooByPtr(&f1);
  showFooByPtr(&f2);
  showFooByPtr(f1Ptr);
  cout << endl;

  // 動態繫結
  cout << "\t[Info] Show Foo By Ref:" << endl;
  showFooByRef(f1);
  showFooByRef(f2);
  cout << endl;


  // 靜態繫結
  cout << "\t[Info] Show Foo By Object:" << endl;
  f1Ptr->show();
  f2.show();
  cout << endl;

  printf("%d\n",MULTIPLE(1, 2));

  printf("%d\n", (2>1)?0:1);

}

void test_main_2() // for constructor & destructor test
{
  myClass obj1; //產生物件，應執行 constructor

  print(obj1);

  for(int i=0; i<10; i++)
      obj1.d[i]=i;

  myClass obj2=obj1; //產生物件，應執行 constructor
  print(obj2);

}

void test_main_3() // for constructor & destructor test
{
  myClass obj1;
  child_myClass obj2;
}

void test_main_5() // for virtual function test
{
  virtual_Class obj1;
  child_myClass obj2;

  obj1.test();
  obj2.test();

  obj1.overloading();
  obj2.overloading();


}

//up casting test
void test_main_6() // for virtual function test
{
//
}


/*==============================================*/
/*main body*/
void test_main()
{
  test_main_6();
}

#endif /* HEADER_CPP_BASIC_1_H_ */
