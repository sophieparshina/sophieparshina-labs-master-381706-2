#pragma once

#include <iostream>
#include <string>

using namespace std;

class TException {
private:
  string msg;
public:
  TException(string _msg) : msg(_msg) {}
  void Print() {
    setlocale(LC_ALL, "Russian");
    cout << "\n Ошибка! \nПроблема в: " << msg << endl;
  }
};