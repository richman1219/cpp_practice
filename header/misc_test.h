/*
 * linked_list.h
 *
 *  Created on: 2018年10月17日
 *      Author: 其懋
 */

#ifndef MISC_TEST_H_
#define MISC_TEST_H_

//used for different kind of function test
void main_misc_test()
{

  //initialization
  list_node_s *start  =  (list_node_s*)malloc(sizeof(list_node_s)); //in C language way
  list_node_s *end  = (list_node_s*)malloc(sizeof(list_node_s));

  start->value = 0;
  start->pre = NULL;
  start->next = end;

  end->value = 1;
  end->next = NULL;
  end->pre = start;

  //insert new node
  list_node_s *first_node  = (list_node_s*)malloc(sizeof(list_node_s));
  start->next = first_node;
  end->pre = first_node;

  first_node->value = 2;
  first_node->next = end;
  first_node->pre = start;

  //find length of list
  list_node_s *test_node = start;
  int len_cnt = 0;
  while(test_node != NULL)
  {
    len_cnt++;
    test_node = test_node->next;
  }


  //print out the result
  printf("%d\n",start->value);
  printf("%d\n",start->next->value);
  printf("%d\n",start->next->next->value);

  printf("%d\n",len_cnt);

  free(start);
  free(end);
  free(first_node);

}

/* This function has a big problem (or two) */
void mystrcpy(const char* s, char *result)
{
  //char result[1000];
  strcpy(result, s);

  //return result;
}

/* Example usage, for the record: */
void misc_test_1()
{
  char s[] = "Hello, world!\n";
  printf("%s", s);
  char result[1000];
  mystrcpy(s, result);
  printf("%s", result);
}

/* i++ or ++i test */
void misc_test_2()
{
  int i=0;
  char s[] = "Hello, world!\n";
  printf("%c\n", s[i++]);
  i=0;
  printf("%c\n", s[++i]);

}

void swap_func(int *a, int *b)
{
  int temp = 0;
  temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(int a[], int len)
{
  int temp=0;
  bool swap_flag;

  //swap, if left > right => (left, right) => (right, left)
  //ex: {8,7,6,5,4,3,2,1} => {1,2,3,4,5,6,7,8}
  //swap times, from idx0:len-1, idx1:len-2, len-3, ... , idx len-1: 1
  //8:7
  //7:6
  //2:1

  for(int i=0; i < len ;i++)
  {
    swap_flag=false;
    for(int j=0; j<len-i-1 ;j++)
    {
      if(a[j] < a[j+1])
      {
        swap_func(&a[j], &a[j+1]);
        swap_flag = true;
      }
    }
    if(swap_flag==false)
    {
      printf("break!!\n");
      break;
    }
  }

  for(int k=0; k<len ; k++)
  {
    printf("%d", a[k]);
  }

}


void reverse_arr(int a[], int len)
{
  for(int i=0; i< len/2; i++)
  {
    swap(a[i], a[len-i-1]);
  }

  printf("\n");

  for(int i=0; i< len; i++)
  {
    printf("%d", a[i]);
  }
}

int sum_arr(int a[], int len)
{
  int temp = 0;
  for(int i=0; i<len ; i++)
  {
    temp += a[i];
  }

  printf("\n%d", temp);

return temp;
}




void misc_test_3()
{
  int a[] =  {2, 3, 4, 5, 6, 7};
  int len = sizeof(a)/sizeof(int);

  bubble_sort(a, len);
  reverse_arr(a, len);
  sum_arr(a, len);

}

void misc_test_4() //malloc for array[i][j]
{
  int r=3, c=4, i, j, count;
  int *arr[r];

  for (i=0;;i++)
    arr[i] = (int *)malloc(c * sizeof(int));

  for(i=0;i<r;i++)
    for(j=0;j<c;j++)
      arr[i][j] = ++count; //[Note] *(*(arr+i)+j) = ++count
}

#endif /* MISC_TEST_H_ */
