/*
 * ring_buffer.h
 *
 *  Created on: 2018¦~10¤ë19¤é
 *      Author: Rich
 */

#ifndef HEADER_RING_BUFFER_H_
#define HEADER_RING_BUFFER_H_

/*Challenge
 *write a macro version!!
 *write a class version
 */

/*functionality
 * insert
 * get
 * get_size: check if size full/ empty
 * */

/*Boundary condition/ corner case
 *handle wrap case for ring buffer
 * */

/* Note
 * b_bottom = (int*)malloc(b_size*sizeof(int));
 * cur_size = ((char*)b_top - (char*)b_bottom)/sizeof(int);
 * */

//class version
class ring_buffer
{
public:
  int b_size, cur_size;
  int *b_bottom, *b_top, *b_base;

  //constructor for buffer size initialization
  ring_buffer(int buffer_size)
  {
    b_size = buffer_size;
    b_base = (int*)malloc(b_size*sizeof(int));
    b_bottom = b_base;
    b_top = b_bottom;
  }

  void insert(int input)
  {
    if(get_cur_size() < b_size) // check if full
    {
      *b_top = input;
      b_top = b_top + 1;
      if(b_top > (b_base + b_size))
        b_top = b_base;
    }
    else
    {
      printf("full\n");
    }
  }

  int get()
  {
    int val;
    if(get_cur_size() > 0)//check if empty
    {
      val = *b_bottom;
      b_bottom = b_bottom + 1;
      if(b_bottom > (b_base + b_size))
        b_bottom = b_base;

      return val;
    }
    else
    {
      printf("empty\n");
      return 0;
    }
  }

  int get_cur_size()
  {
    cur_size = ((char*)b_top - (char*)b_bottom)/sizeof(int);
    if(cur_size < 0)
    {
      cur_size = cur_size + b_size;
    }
    return cur_size;
  }


};

void ring_buffer_main(void)
{
  //initilaization
  ring_buffer test(3);

  //add element
  test.insert(3);
  test.insert(2);
  test.insert(4);
  test.insert(5);

  //get element
  printf("%d\n", test.get());
  printf("%d\n", test.get());
  //printf("%d\n", test.get());
  //printf("%d\n", test.get());
  //printf("%d\n", test.get());

  test.insert(6);
  test.insert(5);

  printf("%d\n", test.get());
  printf("%d\n", test.get());

}


#endif /* HEADER_RING_BUFFER_H_ */
