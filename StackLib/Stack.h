#pragma once
#include <iostream>
#include "../ExceptionLib/Exception.h"

template <class T>
class TStack {
public:
  TStack(int n = 0); //����������� � ����� ����������
  TStack(TStack<T> &st); //����������� �����������
  TStack& operator=(const TStack<T> &stack); // �������� ������������ ��� ������
  int operator!=(const TStack<T>& stack) const; // �������� ���� ������ �� ��������
  int operator==(const TStack<T>& stack) const; // �������� ���� ������ �� ���������
  virtual ~TStack();//����������

  bool IsEmpty(); //�������� ����� �� �������
  bool IsFull(); //�������� ����� �� �������

  void Put(T a); //�������� ������� � � ����
  T Get(); // ���������� �������� �� ������� ����� � ��� ��������� 
  int GetSize(); //��������� ������� �����
  int GetTop(); //��������� �������� ������� �����

  void Print(); //������ �����

protected:
  T* mas; //��������� �� ������� ������, � ������� �������� ����
  int size; //������������ ������ �����
  int top; //������� ������� �����
};

template <class T>
TStack <T> ::TStack(int n) {
  if (n < 0) {
    throw TException("This stack has negative size");
  }
  if (n == 0) {
    mas = NULL;
    size = 0;
    top = 0;
  }
  else {
    size = n;
    top = 0;
    mas = new T[size];
    for (int i = 0; i < size; i++) {
      mas[i] = 0;
    }
  }
}

template <class T>
TStack <T> ::TStack(TStack<T> &s) {
  top = s.top;
  size = s.size;
  if (size == 0) {
    mas = NULL;
  }
  else {
    mas = new T[size];
    for (int i = 0; i < size; i++) {
      mas[i] = s.mas[i];
    }
  }
}

template <class T>
TStack<T>& TStack<T>::operator=(const  TStack<T> &st) {
  if (this != &st) {
    delete[] mas;
    size = st.size;
    top = st.top;
    mas = new T[size];
    for (int i = 0; i < size; i++) {
      mas[i] = st.mas[i];
    }
  }
  return *this;
}

template <class T>
int TStack<T>::operator==(const TStack<T>& st) const {
  if (top != st.top) {
    return 0;
  }
  if (size != st.size) {
    return 0;
  }
  for (int i = 0; i < top; i++) {
    if (mas[i] != st.mas[i]) {
      return 0;
    }
  }
  return 1;
}

template <class T>
int TStack<T>::operator!=(const TStack<T>& st) const {
  return !(*this == st);
}

template <class T>
TStack <T> :: ~TStack() {
  size = 0;
  top = 0;
  delete[] mas;
}

template <class T>
bool TStack<T> :: IsEmpty() {
  if (top == 0) {
    return true;
  }
  else {
    return false;
  }
}

template <class T>
bool TStack<T> :: IsFull() {
  if (top >= size) {
    return true;
  }
  else {
    return false;
  }
}

template <class T>
void TStack<T> :: Put(T a) {
  if (IsFull()) {
    throw TException("Error! Stack is full. There is no place for another element!");
  }
  else {
    mas[top] = a;
    top++;
  }
}

template <class T>
T TStack<T> :: Get() {
  if (IsEmpty()) {
    throw TException("Error! Stack is empty!");
  }
  else {
    top--;
    return mas[top];
  }
}

template <class T>
int TStack<T> ::GetSize() {
  return size;
}

template <class T>
int TStack<T> ::GetTop() {
  return top;
}

template <class T>
void TStack<T> ::Print() {
  for (int i = top - 1; i >= 0; i--) {
    std::cout << " " << mas[i];
  }
}