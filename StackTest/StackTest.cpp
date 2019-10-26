#include "Stack.h"
#include "../../../Desktop/sophieparshina-labs-381706-2/StackLib/Stack.h"

#include <gtest.h>

TEST(Stack, lose_test_if_stack_size_is_negative) {
  ASSERT_NO_THROW(TStack <int> St(-100));
}

TEST(Stack, check_ok_if_not_empty) {
  TStack <int> St(10);
  St.Put(100);
  ASSERT_FALSE(St.IsEmpty());
}

TEST(Stack, check_ok_if_empty) {
  TStack <int> St(10);
  ASSERT_TRUE(St.IsEmpty());
}

TEST(Stack, check_ok_if_full) {
  TStack <int> St(1);
  St.Put(10);
  ASSERT_TRUE(St.IsFull());
}

TEST(Stack, check_ok_if_not_full) {
  TStack <int> St(10);
  ASSERT_FALSE(St.IsFull());
}

TEST(Stack, check_ok_if_can_get_and_get_elements) {
  TStack <int> St(2);
  St.Put(10);
  ASSERT_EQ(10, St.Get());
}

TEST(Stack, check_ok_if_stacks_are_equal) {
  TStack <int> St1(1), St2(1);
  St1.Put(10);
  St2.Put(10);
  ASSERT_TRUE(St1 == St2);
}

TEST(Stack, check_ok_if_stacks_are_different) {
  TStack <int> St1(1), St2(1);
  St1.Put(10);
  St2.Put(11);
  ASSERT_FALSE(St1 == St2);
}

TEST(stack, check_stack_overflow) {
  TStack <int> St(1);
  St.Put(10);
  ASSERT_ANY_THROW(St.Put(11));
}

TEST(Stack, check_get_if_stack_is_empty) {
  TStack <int> St(1);
  ASSERT_ANY_THROW(St.Get());
}

TEST(Stack, check_put_if_stack_is_empty) {
  TStack <int> St(1);
  St.Put(10);
  ASSERT_ANY_THROW(St.Put(11));
}

TEST(Stack, check_ok_if_operation_assignment) {
  TStack <int> St1(1), St2(2);
  St2.Put(10), St2.Put(11);
  St1 = St2;
  ASSERT_TRUE(St2 == St1);
}


TEST(Stack, check_right_order_of_putting_elements) {
  TStack <int> St(2);
  St.Put(10);
  St.Put(11);
  ASSERT_EQ(11,St.Get());
  ASSERT_EQ(10, St.Get());
}

TEST(Stack, check_ok_if_stacks_are_not_equal) {
  TStack <int> St1(1), St2(1);
  St1.Put(10);
  St2.Put(11);
  ASSERT_TRUE(St1 != St2);
}

TEST(Stack, check_ok_if_stacks_are_not_not_equal) {
  TStack <int> St1(1), St2(1);
  St1.Put(10);
  St2.Put(10);
  ASSERT_FALSE(St1 != St2);
}

TEST(Stack, check_ok_when_compare_with_different_size) {
  TStack <int> St1(10), St2(11);
  ASSERT_FALSE(St1 == St2);
}

TEST(Stack, check_if_compare_stacks_with_different_elements_and_top) {
  TStack <int> St1(3), St2(3);
  St1.Put(10);
  St2.Put(10), St2.Put(11);
  ASSERT_FALSE(St1 == St2);
}


TEST(Stack, check_ok_when_uncompare_with_different_size) {
  TStack <int> St1(10), St2(11);
  ASSERT_TRUE(St1 != St2);
}

TEST(Stack, check_if_uncompare_when_different_elements_and_tops) {
  TStack <int> St1(3), St2(3);
  St1.Put(10);
  St2.Put(10), St2.Put(11);
  ASSERT_TRUE(St1 != St2);
}



