file(GLOB hdrs "*.h*") #��������� � ���������� hdrs ��� ����� � ����������� .h
file(GLOB srcs "*.cpp")#��������� � ���������� srcs ��� ����� � ����������� .h

add_library(${ExceptionLib} STATIC ${srcs} ${hdrs}) 