#include <stdio.h>
#include <iostream>
#include <locale.h>
#include "List.h"
#include "../../../Desktop/new_folder/sophieparshina-labs-381706-2/ListLib/List.h"

using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");
  cout << "Пример работы с односвязным линейным списком на указателях." << endl
    << "Паршина Софья. Группа 381706-2" << endl;
  TList <int> list;
//#ifdef __USE_EXAMPLE_IO__
//#endif 
//#ifndef __USE_EXAMPLE_IO__
  try {
    list.Print();
    cout << '\n' << "Введите элементы списка: ";
    cout << "Положить в начало списка 1895" << endl;
    list.PutBegin(1895);
    list.Print();

    cout << "Положить в конец списка 345" << endl;
    list.PutEnd(345);
    list.Print();

    cout << "Положить в начало списка 1" << endl;
    list.PutBegin(1);
    list.Print();

    cout << "Положить в конец списка 3" << endl;
    list.PutEnd(3);
    list.Print();

    cout << "Положить элемент 96 в позицию 4" << endl;
    list.Put(3,96);
    list.Print();

    cout << "Положить в элемент 4 в позицию 2" << endl;
    list.Put(1, 4);
    list.Print();

    cout << "Убрать элемент из 3 позиции" << endl;
    list.Get(2);
    list.Print();

    cout << "Убрать элемент из конца списка" << endl;
    list.GetEnd();
    list.Print();

    cout << "Убрать элемент из начала списка" << endl;
    list.GetBegin();
    list.Print();

    cout << "Положить в начало списка 455" << endl;
    list.PutBegin(455);
    list.Print();
  }
  catch (TException except) {
    except.Print();
  }
//#endif // !__USE_EXAMPLE_IO__
  TList <int> final_list(list);
  cout<<endl<<"Конструктор копирования(адрес предыдущей версии листа : " 
    << &list << ", адресс новой версии листа : " << &final_list << ") : " << endl; 
  final_list.Print();
  return 0;
} 


