CXX = g++
CC = g++

all:		main1 main2 main3

student_info.o:	student_info.cpp student_info.h

grade.o:	grade.cpp grade.h median.h student_info.h

main3.o:	main3.cpp grade.h median.h student_info.h

median.o:	median.cpp median.h

main3:		main3.o grade.o median.o student_info.o

test:		all
	./main1 <../test_vectors/single_grade
	./main2 <../test_vectors/single_grade
	./main2 <../test_vectors/grades
	./main3 <../test_vectors/grades

clobber:
	rm -f *.o *.exe core main1 main2 main3
