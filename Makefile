# This just builds the sample driver
#
DEPS := LinkedList.h
OBJS := LinkedList.o SampleDriver.o
EXEC := a.out

$(EXEC): $(OBJS)
	gcc $^ -o $@

%.o: %.c $(DEPS)
	gcc -c $< -o $@
