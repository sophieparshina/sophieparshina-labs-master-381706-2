#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

#include <gtest.h>
#include "List.h"

TEST(List, can_make_list) {
  ASSERT_NO_THROW(TList<int> list);
}

TEST(Elem, can_make_elem) {
  ASSERT_NO_THROW(TElem<int> elem);
}

TEST(List, right_work_of_copy_constructor) {
  TList<int> second_list;
  ASSERT_NO_THROW(TList<int> list(second_list));
}

TEST(List, right_copy_elements) {
  TElem<int> element1(10, 0);
  TElem<int> element2(element1);
  ASSERT_EQ(element1.GetData(), element2.GetData());
  ASSERT_EQ(element1.GetNext(), element2.GetNext());
}

TEST(List, get_elements_if_list_is_empty) {
  TList<int> list;
  ASSERT_ANY_THROW(list.Get(1));
}

TEST(List, get_elements_to_incorrect_index) {
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(2);
  list.PutBegin(3);
  ASSERT_ANY_THROW(list.Get(0));
  ASSERT_ANY_THROW(list.Get(3));
}

TEST(List, get_element_with_its_index) {
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(5);
  ASSERT_EQ(list.Get(1), 5);
}

TEST(List, put_elements_to_incorrect_index) {
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(1);
  list.PutBegin(1);
  ASSERT_ANY_THROW(list.Put(0, 1));
  ASSERT_ANY_THROW(list.Put(3, 1));
}

TEST(List, put_element_to_index) {
  TList<int> list;
  list.PutEnd(1);
  list.PutEnd(2);
  list.PutEnd(34);
  list.Put(1, 11);
  ASSERT_EQ(list.Get(1), 11);
  ASSERT_EQ(list.Get(1), 2);
}

TEST(Elem, can_get_next) {
  TElem<int>* el = 0;
  TElem<int> elem(1, el);
  ASSERT_EQ(elem.GetNext(), el);
}

TEST(Elem, can_set_data) {
  TElem<int> element;
  element.SetData(1);
  ASSERT_EQ(element.GetData(), 1);
}

TEST(Elem, set_next_if_it_is_last) {
  TElem<int>* el = 0;
  TElem<int> elem;
  elem.SetNext(el);
  ASSERT_EQ(elem.GetNext(), el);
}

TEST(List, check_if_list_is_empty) {
  TList<int> list;
  ASSERT_TRUE(list.IsEmpty());
}

TEST(List, check_if_list_is_not_empty) {
  TList<int> list;
  list.PutBegin(1);
  ASSERT_FALSE(list.IsEmpty());
}

TEST(List, put_begin) {
  TList<int> list;
  ASSERT_NO_THROW(list.PutBegin(1));
}

TEST(List, put_end) {
  TList<int> list;
  ASSERT_NO_THROW(list.PutEnd(1));
}

TEST(List, get_begin) {
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(2);
  ASSERT_EQ(2, list.GetBegin());
}

TEST(List, can_get_end) {
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(2);
  ASSERT_EQ(1, list.GetEnd());
}

