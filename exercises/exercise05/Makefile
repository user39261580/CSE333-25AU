# Copyright ©2025 Hal Perkins.  All rights reserved.  Permission is
# hereby granted to students registered for University of Washington
# CSE 333 for use solely during Spring Quarter 2025 for purposes of
# the course.  No other use, copying, distribution, or modification
# is permitted without prior written consent. Copyrights for
# third-party components of this work must be honored.  Instructors
# interested in reusing these course materials should contact the
# author.

# default target
ex5: ex5.o NthPrime.o
	gcc -Wall -g -std=c17 -o ex5 ex5.o NthPrime.o -lm

# individual source files
NthPrime.o: NthPrime.c NthPrime.h
	gcc -Wall -g -std=c17 -c NthPrime.c

ex5.o: ex5.c NthPrime.h
	gcc -Wall -g -std=c17 -c ex5.c

# phony target - delete built files (including MacOS debug files -- not required)
clean:
	rm -rf ex5 *.o *~ ex5.dSYM
