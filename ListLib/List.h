#pragma once

#include "../ExceptionLib/Exception.h"
#include "Elem.h"

using namespace std;

template <class T>
class TList { 
//����� ������������ ������
protected: //������ � ���� ��������� ������ �������, ����������� �� �������
  int count; //���������� ��������� ������������ ������
  TElem <T>* begin;

public: //������ ������ ����, ��� ����� ����������� ������� ������
  TList(); //����������� ������ �� ���������
  TList(TList<T> &list); //���������� �����������
  virtual ~TList(); //����������

  void Put(int _n, T element); //�����, ����������� ���������� �������� � �������� ������� ������
  void PutBegin(T element); //�����, ����������� ���������� �������� � ������ ������
  void PutEnd(T element); //�����, ����������� ���������� �������� � ������ ������
  
  T Get(int _n); // �����, ����������� ��������� �������� �� ��������� ������� ������
  T GetBegin(); // �����, ����������� ��������� �������� �� ������ ������
  T GetEnd(); // �����, ����������� ��������� �������� �� ����� ������

  void Print(); //������ ��������� ������

  bool IsFull(); //�������� ������ �� �������
  bool IsEmpty(); //�������� ������ �� �������
};

//����������� ������ �� ���������
template <class T>
TList<T>::TList() {
  begin = 0;
  count = 0;
}

//���������� �����������
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

//����������
template <class T>
TList<T>::~TList() {
  while (begin != 0)
  {
    TElem<T>* temp = begin; //��������� ��������� ���������� ��� �������� ������ ������
    begin = begin->GetNext(); //�������������� ������ ������ ��� ��������� �� ��� �������
    delete temp; //������� ��������� ���������� � ������� ������� ������
  }
}

//�������� ������ �� �������
template <class T>
bool TList<T>::IsEmpty() {
  if (begin == 0)
  {
    return true;
  } else {
    return false;
  }
}

//�������� ������ �� �������
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

//�����, ����������� ���������� �������� � �������� ������� ������
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

//�����, ����������� ���������� �������� � ������ ������
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

//�����, ����������� ���������� �������� � ����� ������
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

// �����, ����������� ��������� �������� �� ��������� ������� ������ c ��� ��������� �� ������
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

// �����, ����������� ��������� �������� �� ������ ������
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

// �����, ����������� ��������� �������� �� ����� ������
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

//������ ��������� ������
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