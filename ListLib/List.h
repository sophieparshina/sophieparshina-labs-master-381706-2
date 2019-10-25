#pragma once

#include "../ExceptionLib/Exception.h"
#include "Elem.h"

using namespace std;

template <class T>
class TList { 
//Класс односвязного списка
protected: //Доступ к этим элементам открыт классам, производным от данного
  int count; //Количество элементов односвязного списка
  TElem <T>* begin;

public: //Доступ открыт всем, кто видит определение данного класса
  TList(); //Конструктор класса по умолчанию
  TList(TList<T> &list); //Констуктор копирования
  virtual ~TList(); //Деструктор

  void Put(int _n, T element); //Метод, реализующий размещение элемента в указаную позицию списка
  void PutBegin(T element); //Метод, реализующий размещение элемента в начало списка
  void PutEnd(T element); //Метод, реализующий размещение элемента в начало списка
  
  T Get(int _n); // Метод, реализующий забирание элемента по указанной позиции списка
  T GetBegin(); // Метод, реализующий забирание элемента из начала списка
  T GetEnd(); // Метод, реализующий забирание элемента из конца списка

  void Print(); //Печать элементов списка

  bool IsFull(); //Проверка списка на полноту
  bool IsEmpty(); //Проверка списка на пустоту
};

//Конструктор класса по умолчанию
template <class T>
TList<T>::TList() {
  begin = 0;
  count = 0;
}

//Констуктор копирования
template <class T>
TList<T>::TList(TList<T> &List) {
  count = List.count;
  TElem<T>* a = List.begin;
  TElem<T>* b;
  if (List.begin == 0)
  {
    begin = 0;
  } else {
    begin = new TElem<T>(*List.begin);
    b = begin;
    while (a->TElem<T>::GetNext() != 0)
    {
      b->TElem<T>::SetNext(new TElem<T>(*(a->TElem<T>::GetNext()))); 
      a = a->TElem<T>::GetNext();
      b = b->TElem<T>::GetNext();
    }
  }
}

//Деструктор
template <class T>
TList<T>::~TList() {
  while (begin != 0)
  {
    TElem<T>* temp = begin; //Назначаем временную переменную для хранения начала списка
    begin = begin->GetNext(); //Переобозначаем начало списка как следующий за ним элемент
    delete temp; //Удаляем временную переменную с текущим началом списка
  }
}

//Проверка списка на пустоту
template <class T>
bool TList<T>::IsEmpty() {
  if (begin == 0)
  {
    return true;
  } else {
    return false;
  }
}

//Проверка списка на полноту
template <class T>
bool TList<T>::IsFull() {
  try
  {
    TElem<T>* element = new TElem<T>();
    if (element = NULL)
    {
      return 1;
    } else {
      delete element;
      return 0;
    }
  }
  catch (...)
  {
    return 0;
  }
  return true;
}

//Метод, реализующий размещение элемента в указаную позицию списка
template <class T>
void TList<T>::Put(int _n, T element) {
  if (this->IsFull())
  {
    throw TException("Error! List is full!");
  }
  if (_n < 1 || _n > count - 1)
  {
    throw TException("Error! Wrong index!");
  } else {
    int i = 0;
    TElem<T>* elem = begin;
    while (i != _n - 1)
    {
      elem = elem->GetNext();
      i++;
    }
    TElem<T>* temp = new TElem<T>(element, elem->GetNext());
    elem->SetNext(temp);
    count++;
  }
}

//Метод, реализующий размещение элемента в начало списка
template <class T>
void TList<T>::PutBegin(T element) {
  if (this->IsFull())
    throw TException("Error! List  is full!");
  if (begin == 0)
  {
    TElem<T>* temp = new TElem<T>(element, 0);
    begin = temp;
  } else {
    TElem<T>* temp = new TElem <T>(element, begin);
    begin = temp;
  }
  count++;
}

//Метод, реализующий размещение элемента в конец списка
template <class T>
void TList<T>::PutEnd(T element) {
  if (this->IsFull())
    throw TException("Error! List is full!");
  if (begin != 0)
  {
    TElem<T> *bgn = begin;
    while (bgn->GetNext() != 0)
      bgn = bgn->GetNext();
    bgn->SetNext(new TElem <T>(element, 0));
  } else {
    begin = new TElem<T>(element, 0);
  }
  count++;
}

// Метод, реализующий забирание элемента по указанной позиции списка c его удалением из списка
template <class T>
T TList<T>::Get(int _n) {
  if (this->IsEmpty())
    throw TException("Error! List is empty!");
  if (_n < 1 || _n > count - 1)
    throw TException("Error! Wrong index!");
  else
  {
    int i = 0;
    count--;
    TElem<T>* a = begin;
    TElem<T>* b = begin->GetNext();
    while (i != _n - 1)
    {
      a = b;
      b = b->GetNext();
      i++;
    }
    T temp = b->GetData();
    TElem<T>* c = b->GetNext();
    a->SetNext(c);
    delete b;
    return temp;
  }
}

// Метод, реализующий забирание элемента из начала списка
template <class T>
T TList <T>::GetBegin() {
  if (IsEmpty())
  {
    throw TException("Error! List is empty");
  } else {
    TElem<T>* bgn = begin;
    T temp = begin->TElem<T>::GetData();
    begin = begin->TElem<T>::GetNext();
    delete bgn;
    count--;
    return temp;
  }
}

// Метод, реализующий забирание элемента из конца списка
template <class T>
T TList <T>::GetEnd() {
  if (IsEmpty())
  {
    throw TException("Error! List is empty");
  } else {
    if (begin->TElem<T>::GetNext() == 0)
    {
      T result = begin->TElem<T>::GetData();
      begin = begin->TElem<T>::GetNext();
      count--;
      return result;
    }
    else
    {
      TElem<T> *a = begin;
      while (a->GetNext()->GetNext() != 0)
        a = a->GetNext();
        TElem<T> *a1 = a->GetNext();
        T res = a1->GetData();
        delete a1;
        a->SetNext(0);
        count--;
        return res;
    }
  }
}

//Печать элементов списка
template <class T>
void TList <T>::Print() {
  if (IsEmpty())
  {
    cout << "List is empty" << '\n';
  } else {
    TElem<T>* a = begin;
    do
    {
      cout << a->TElem<T>::GetData() << " ";
      a = a->GetNext();
    } while (a != 0);
    cout << '\n' << '\n';
  }
} 