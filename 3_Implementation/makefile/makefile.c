SRC = phonebook.c\
src/phonebook.c
INC = inc
phonebook.exe : $(SRC) 
    gcc $^ -I$(INC) -o $@

run : phonebook.exe
    ./phonebook.exe

clean:
    del phonebook.exe
