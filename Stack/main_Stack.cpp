#include <iostream>
#include "Stack.h"
#include "pch.h"
#include "../../../Desktop/sophieparshina-labs-381706-2/StackLib/Stack.h"

using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");
  cout << "Пример работы со стеком." << endl
    << "Паршина Софья. Группа 381706-2" << endl;
  try {
    //cout << "Введите размер стека" <<endl;
    //cin >> n;
    int n = 5;
    TStack <int> stack_example(n);
    cout << "\n Введите элементы стека:" << endl;
    for (int i = 0; i < n; i++) {
      //cin >> element;
      int element;
      element = i * 2 + 11;
      stack_example.Put(element);
    }
    stack_example.Print();

    cout <<endl << "\n Размер стека: " << stack_example.GetSize() << endl;

    cout << "\n Получить элемент стека с удалением:" << endl;
    stack_example.Get();
    stack_example.Print();

    TStack <int> final_stack(stack_example);
    cout << endl << "\n Конструктор копирования(адрес предыдущей версии стека : "
      << &stack_example << ", адресс новой версии листа : " << &final_stack << ") : " << endl;
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

