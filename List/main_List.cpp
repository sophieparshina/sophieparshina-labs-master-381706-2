#include <stdio.h>
#include <iostream>
#include <locale.h>
#include "List.h"
#include "../../../Desktop/new_folder/sophieparshina-labs-381706-2/ListLib/List.h"

using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");
  cout << "������ ������ � ����������� �������� ������� �� ����������." << endl
    << "������� �����. ������ 381706-2" << endl;
  TList <int> list;
//#ifdef __USE_EXAMPLE_IO__
//#endif 
//#ifndef __USE_EXAMPLE_IO__
  try {
    list.Print();
    cout << '\n' << "������� �������� ������: ";
    cout << "�������� � ������ ������ 1895" << endl;
    list.PutBegin(1895);
    list.Print();

    cout << "�������� � ����� ������ 345" << endl;
    list.PutEnd(345);
    list.Print();

    cout << "�������� � ������ ������ 1" << endl;
    list.PutBegin(1);
    list.Print();

    cout << "�������� � ����� ������ 3" << endl;
    list.PutEnd(3);
    list.Print();

    cout << "�������� ������� 96 � ������� 4" << endl;
    list.Put(3,96);
    list.Print();

    cout << "�������� � ������� 4 � ������� 2" << endl;
    list.Put(1, 4);
    list.Print();

    cout << "������ ������� �� 3 �������" << endl;
    list.Get(2);
    list.Print();

    cout << "������ ������� �� ����� ������" << endl;
    list.GetEnd();
    list.Print();

    cout << "������ ������� �� ������ ������" << endl;
    list.GetBegin();
    list.Print();

    cout << "�������� � ������ ������ 455" << endl;
    list.PutBegin(455);
    list.Print();
  }
  catch (TException except) {
    except.Print();
  }
//#endif // !__USE_EXAMPLE_IO__
  TList <int> final_list(list);
  cout<<endl<<"����������� �����������(����� ���������� ������ ����� : " 
    << &list << ", ������ ����� ������ ����� : " << &final_list << ") : " << endl; 
  final_list.Print();
  return 0;
} 


