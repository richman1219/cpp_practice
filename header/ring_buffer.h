/*
 * ring_buffer.h
 *
 *  Created on: 2018¦~10¤ë19¤é
 *      Author: Rich
 */

#ifndef HEADER_RING_BUFFER_H_
#define HEADER_RING_BUFFER_H_

/*Challenge
 *write a macro version
 *write a class version
 */

/*functionality
 * insert
 * get
 * get_size
 * check if size full
 * */

/*
 *handle wrap case for ring buffer
 * */

/* Note
 * b_bottom = (int*)malloc(b_size*sizeof(int));
 * */

//class version
class ring_buffer
{
public:
  int b_size, cur_size;
  int *b_bottom, *b_top;

  //constructor for buffer size initialization
  ring_buffer(int buffer_size)
  {
    b_size = buffer_size;
    b_bottom = (int*)malloc(b_size*sizeof(int));
    b_top = b_bottom;
  }

  void insert(int input)
  {
    if(get_cur_size() < b_size) // check if full
    {
      b_top = b_top + 1;
      *b_top = input;
    }
    else
    {
      printf("full");
    }
  }

  int get()
  {

    if(b_bottom != b_top)//check if it is not empty
    {
      b_bottom = b_bottom + 1;
      return *b_top;
    }
    else
    {
      printf("empty");
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
  printf("%d\n", test.get());
  printf("%d\n", test.get());
  printf("%d\n", test.get());

}


#endif /* HEADER_RING_BUFFER_H_ */
