#pragma once

template <class T>

class TElem {
protected: //������ � ���� ��������� ������ �������, ����������� �� �������
  TElem <T>* next; //��������� �� ��������� ������� ������������ ������
  T data; // �������� �������� ������������ ������ 
public: //������ ������ ����, ��� ����� ����������� ������� ������
  TElem(T _data = 0, TElem <T>* n = 0); //����������� ������ � �����������
  TElem(TElem<T> &element); //����������� �����������
  virtual ~TElem(); //����������
  T GetData(); // ��������� �������� �������� ������
  void SetData(T element); // ��������� �������� �������� ������
  TElem* GetNext(); //�������� ��������� �� ��������� ������� ������
  void SetNext(TElem <T>* n); //��������� ��������� �� ��������� ������� ������
};

template <class T>
TElem<T>::TElem(T _data, TElem<T>* _next) {
  data = _data;
  next = _next;
}

template <class T>
TElem<T>::TElem(TElem<T> &element) { 
  //����������� ����������� ���������� � ��� �������,
  //����� ������ ��������� ����� ����������� �������������
  data = element.data;
  next = element.next;
}

template <class T>
TElem<T>::~TElem() {} //����������

template <class T>
T TElem<T>::GetData() {
  return data;
}

template <class T>
void TElem<T>::SetData(T _data) {
  data = _data;
}

template <class T>
TElem<T>* TElem<T>::GetNext() {
  return next;
}

template <class T>
void TElem<T> ::SetNext(TElem<T>* _next) {
  next = _next;
} 
