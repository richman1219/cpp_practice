/*
 * linked_list.h
 *
 *  Created on: 2018年10月17日
 *      Author: 其懋
 */

#ifndef HEADER_LINKED_LIST_H_
#define HEADER_LINKED_LIST_H_

typedef struct node{
  struct node *pre;
  struct node *next;
  int value;
}list_node_s;

void main_list_test()
{

  //initialization
  list_node_s *start  = new list_node_s;
  list_node_s *end  = new list_node_s;

  start->value = 0;
  start->pre = NULL;
  start->next = end;

  end->value = 1;
  end->next = NULL;
  end->pre = start;

  //insert new node
  list_node_s *first_node  = new list_node_s;
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

}


#endif /* HEADER_LINKED_LIST_H_ */
