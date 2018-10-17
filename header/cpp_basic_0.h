/*
 * cpp_basic_0.h
 *
 *  Created on: 2018年10月18日
 *      Author: 其懋
 */

#ifndef HEADER_CPP_BASIC_0_H_
#define HEADER_CPP_BASIC_0_H_

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

#define TEST_ADDR ((volatile int*) 0x12345678)

#define MULTIPLE(X, Y) ((X)*(Y))

//design my own size_of with O(1)
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)

static int a = 3;

//pragma pack
#pragma pack(1)
typedef struct {
  unsigned char      v1; //1
  unsigned int       v2; //4
  unsigned long long v3; //8
  float     v4;          //4
} myStrA;

union Data {
   int i;
   float f;
   char str[20];
} data;

#if 0
int majorityElement(std::vector<int> & num)
{
  int size = num.size();
  int count;
  for (int i = 0; i<size; i++) {    // Your answer...
    count = 1;
    for (int j = i + 1; j<size; j++)
    {
      if (num[i] == num[j])
      {
        count++;
        if (count > ceil(size / 2))
        {
          return num[i];
        }
      }
    }
  }
}
#else
/*complexity
 * time complexity O(1)
 * memory complexity O(1)
 * */

/*algorithm
 *sequential search
 * ++--+
 * +-++-+
 * 3 2 1
 * */

/*corner case/ boundary condition
 *
 * */

/*UT case
 *
 * */

int majorityElement(std::vector<int> & num)
{
  int size = num.size();
  int major_num = num[0], major_cnt = 1;

  for (int i = 1; i<size-1; i++)
  {
    if(major_num != num[i] && major_cnt > 0)
    {
      major_cnt--;
      if(major_cnt == 0)
        major_num = num[i];
    }
    else
    {
      major_cnt++;
    }
  }

  return major_num;
}
#endif

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
};

class child_myClass: public myClass
{
public:
  child_myClass() {
     cout << "child_myClass 建構函式!" << endl;
  }

   ~child_myClass() {
      cout << "child_myClass 解構函式!" << endl;
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

/*==============================================*/
/*main body*/
void test_main()
{
  test_main_3();
}

#endif /* HEADER_CPP_BASIC_0_H_ */
