file(GLOB hdrs "*.h*") #��������� � ���������� hdrs ��� ����� � ����������� .h
file(GLOB srcs "*.cpp")#��������� � ���������� srcs ��� ����� � ����������� .h

add_executable(${List} ${srcs} ${hdrs})
target_link_libraries(${List} ${ListLib})