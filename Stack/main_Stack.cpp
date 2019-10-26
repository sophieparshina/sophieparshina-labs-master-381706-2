#include <iostream>
#include "Stack.h"
#include "pch.h"
#include "../../../Desktop/sophieparshina-labs-381706-2/StackLib/Stack.h"

using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");
  cout << "������ ������ �� ������." << endl
    << "������� �����. ������ 381706-2" << endl;
  try {
    //cout << "������� ������ �����" <<endl;
    //cin >> n;
    int n = 5;
    TStack <int> stack_example(n);
    cout << "\n ������� �������� �����:" << endl;
    for (int i = 0; i < n; i++) {
      //cin >> element;
      int element;
      element = i * 2 + 11;
      stack_example.Put(element);
    }
    stack_example.Print();

    cout <<endl << "\n ������ �����: " << stack_example.GetSize() << endl;

    cout << "\n �������� ������� ����� � ���������:" << endl;
    stack_example.Get();
    stack_example.Print();

    TStack <int> final_stack(stack_example);
    cout << endl << "\n ����������� �����������(����� ���������� ������ ����� : "
      << &stack_example << ", ������ ����� ������ ����� : " << &final_stack << ") : " << endl;
    final_stack.Print();
    cout << endl;

    for (int i = 0; i < n; i++) {
      stack_example.Get();
    }

    system("pause");
  }
  catch (TException exception) {
    exception.Print();
  }
  return 0;
} 

