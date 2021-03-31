CXX = g++
CC = g++

all:	seperate_pf_vec	erase_pf_vec erase_pf_vec_iter erase_pf_list_iter split_main pics_main

student_info.o:	student_info.cpp student_info.h

grade.o:	grade.cpp grade.h median.h student_info.h

common_main.o:	common_main.cpp grade.h median.h student_info.h

list_main.o:	list_main.cpp grade.h median.h student_info.h

median.o:	median.cpp median.h

seperate_pf_vec.o:	seperate_pf_vec.cpp

erase_pf_vec.o:	erase_pf_vec.cpp

erase_pf_vec_iter.o:	erase_pf_vec_iter.cpp

erase_pf_list_iter.o:	erase_pf_list_iter.cpp

seperate_pf_vec:	common_main.o grade.o median.o student_info.o seperate_pf_vec.o

erase_pf_vec:	common_main.o grade.o median.o student_info.o erase_pf_vec.o

erase_pf_vec_iter:	common_main.o grade.o median.o student_info.o erase_pf_vec_iter.o

erase_pf_list_iter:	list_main.o grade.o median.o student_info.o erase_pf_list_iter.o

split.o: split.cpp

split_main.o: split_main.cpp

split_main: split.o split_main.o

pics.o: pics.cpp

pics_main.o: pics_main.cpp

pics_main: pics.o pics_main.o


test:		all
	./seperate_pf_vec <../test_vectors/grades
	./erase_pf_vec <../test_vectors/grades
	./erase_pf_vec_iter <../test_vectors/grades
	./erase_pf_list_iter <../test_vectors/grades
	./split_main < split.cpp

clobber:
	rm -f *.o *.exe core seperate_pf_vec erase_pf_vec erase_pf_vec_iter erase_pf_list_iter split_main
