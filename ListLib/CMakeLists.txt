file(GLOB hdrs "*.h*") #��������� � ���������� hdrs ��� ����� � ����������� .h
file(GLOB srcs "*.cpp")#��������� � ���������� srcs ��� ����� � ����������� .h

add_library(${ListLib} STATIC ${srcs} ${hdrs}) #������� ����������� ����������, � ��� ��������� ����� �� ���������� ${srcs} � ${hdrs}
