#pragma once

template <class T>

class TElem {
protected: //Доступ к этим элементам открыт классам, производным от данного
  TElem <T>* next; //Указатель на следующий элемент односвязного списка
  T data; // Значение элемента односвязного списка 
public: //Доступ открыт всем, кто видит определение данного класса
  TElem(T _data = 0, TElem <T>* n = 0); //Конструктор класса с параметрами
  TElem(TElem<T> &element); //Конструктор копирования
  virtual ~TElem(); //Деструктор
  T GetData(); // Получение значение элемента списка
  void SetData(T element); // Назначить значение элемента списка
  TElem* GetNext(); //Получить указатель на следующий элемент списка
  void SetNext(TElem <T>* n); //Назначить указатель на следующий элемент списка
};

template <class T>
TElem<T>::TElem(T _data, TElem<T>* _next) {
  data = _data;
  next = _next;
}

template <class T>
TElem<T>::TElem(TElem<T> &element) { 
  //Конструктор копирования вызывается в тех случаях,
  //когда объект создается путем копирования существующего
  data = element.data;
  next = element.next;
}

template <class T>
TElem<T>::~TElem() {} //Деструктор

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
