all: task_1 task_2 task_3 task_4 task_5



task_1:
	@echo "Compiling task1.c..."
	gcc -c task1/task1.c
	gcc task1.o -o task_exe
	./task_exe

task_2:
	@echo "Compiling task2.c..."
	gcc -c task2/task2.c
	gcc task2.o -o task_exe
	./task_exe
task_3:
	@echo "Compiling task3.c..."
	gcc -c task3/task3.c
	gcc task3.o -o task_exe
	./task_exe
task_4:
	@echo "Compiling task4.c..."
	gcc -c task4/task4.c
	gcc task4.o -o task_exe
	./task_exe
task_5:
	@echo "Compiling task5.c..."
	gcc -c task5/task5.c
	gcc task5.o -o task_exe
	./task_exe

clean:
	@echo "Cleaning up..."
	rm -rf $(OBJ_DIR)

help:
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  task1     - Compile and run task1"
	@echo "  task2     - Compile and run task2"
	@echo "  task3     - Compile and run task3"
	@echo "  task4     - Compile and run task4"
	@echo "  task5     - Compile and run task5"
	@echo "  clean   - Remove build files"
	@echo "  help    - Display this help message"
