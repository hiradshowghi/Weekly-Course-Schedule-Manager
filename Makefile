OPT = -Wall

schedule:	main.o School.o Schedule.o Course.o CourseArray.o Time.o View.o Control.o
	g++ $(OPT) -o schedule main.o School.o Schedule.o Course.o CourseArray.o Time.o View.o Control.o

main.o:	main.cc Control.h
	g++ $(OPT) -c main.cc

School.o: School.cc School.h CourseArray.h
	g++ $(OPT) -c School.cc

Schedule.o: Schedule.cc Schedule.h Course.h
	g++ $(OPT) -c Schedule.cc

Course.o: Course.cc Course.h
	g++ $(OPT) -c Course.cc

CourseArray.o: CourseArray.cc CourseArray.h
	g++ $(OPT) -c CourseArray.cc

Time.o:	Time.cc Time.h
	g++ $(OPT) -c Time.cc

View.o:	View.cc View.h
	g++ $(OPT) -c View.cc

Control.o: Control.cc Control.h School.h Schedule.h CourseArray.h View.h
	g++ $(OPT) -c Control.cc

clean:
	rm -f *.o schedule
