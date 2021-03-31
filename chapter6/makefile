CXX = g++
CC = g++
CXXFLAGS = -I../chapter05

all:	split_main palindrome urls_main grade_analysis erase_pf_2pass erase_pf_1pass

median.o:	../chapter5/median.cpp
	$(CXX) $(CXXFLAGS) -c ../chapter5/median.cpp

student_info.o:	../chapter5/student_info.cpp ../chapter5/student_info.h
	$(CXX) $(CXXFLAGS) -c ../chapter5/student_info.cpp


split.o:	split.cpp

split_main.o:	../chapter5/split_main.cpp 
				$(CXX) $(CXXFLAGS) -c ../chapter5/split_main.cpp

palindrome.o:	palindrome.cpp

split_main:	split_main.o split.o

palindrome: palindrome.o

urls.o:	urls.cpp

urls_main.o:	urls_main.cpp

urls_main:	urls_main.o	urls.o

analysis.o: analysis.cpp analysis.h 

grade_analysis.o: grade_analysis.cpp analysis.h

grade_analysis: grade_analysis.o analysis.o grade.o median.o student_info.o

common_main.o:	../chapter5/common_main.cpp grade.h ../chapter5/student_info.h ../chapter5/median.h
	$(CXX) $(CXXFLAGS) -c ../chapter5/common_main.cpp

erase_pf_2pass.o: erase_pf_2pass.cpp

erase_pf_1pass.o: erase_pf_1pass.cpp

erase_pf_2pass: common_main.o erase_pf_2pass.o grade.o median.o student_info.o

erase_pf_1pass: common_main.o erase_pf_1pass.o grade.o median.o student_info.o

test: all
	./split_main < spli.cpp

clobber:
	rm -f *.o *.exe core split_main palindrome urls_main grade_analysis erase_pf_2pass erase_pf_1pass

