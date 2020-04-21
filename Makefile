
# detect Operating System and choose compiler
ifeq ($(OS),Windows_NT)
    CC = g++
    ENDING = exe
else
    CC = g++
    ENDING = out
endif

CFLAGS = -std=c++14 -g -Wall
OUT = Binaries

# menue
all:
	@echo ---------- MitarbeiterRegister Makefile ----------
	@echo TESTING:
	@echo     test_datum  
	@echo     test_mitarbeiter
	@echo     test_register
	@echo     test_gui
	@echo MAIN:
	@echo     main
	@echo     main_E

# comands
test_datum: $(OUT)/Datum.o $(OUT)/datum_test.o
	$(CC) $(CFLAGS) $^ -o ./$(OUT)/$@.$(ENDING)

test_mitarbeiter: $(OUT)/Datum.o $(OUT)/Mitarbeiter.o $(OUT)/mitarbeiter_test.o
	$(CC) $(CFLAGS) $^ -o ./$(OUT)/$@.$(ENDING)

test_register: $(OUT)/Datum.o $(OUT)/Mitarbeiter.o $(OUT)/MitarbeiterRegister.o $(OUT)/register_test.o
	$(CC) $(CFLAGS) $^ -o ./$(OUT)/$@.$(ENDING)

test_gui: $(OUT)/Datum.o $(OUT)/Mitarbeiter.o $(OUT)/MitarbeiterRegister.o $(OUT)/GUI.o $(OUT)/gui_test.o
	$(CC) $(CFLAGS) $^ -o ./$(OUT)/$@.$(ENDING)

main: $(OUT)/Datum.o $(OUT)/Mitarbeiter.o $(OUT)/MitarbeiterRegister.o $(OUT)/GUI.o $(OUT)/main.o
	$(CC) $(CFLAGS) $^ -o ./$(OUT)/$@.$(ENDING)

main_E: Datum.cpp Mitarbeiter.cpp MitarbeiterRegister.cpp GUI.cpp main.cpp
	$(CC) $(CFLAGS) $^ -E > main.preprocessor

main_S: main.cpp
	$(CC) $(CFLAGS) $^ -S

# object files Project
./$(OUT)/Datum.o: Datum.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

./$(OUT)/Mitarbeiter.o: Mitarbeiter.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

./$(OUT)/MitarbeiterRegister.o: MitarbeiterRegister.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

./$(OUT)/GUI.o: GUI.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

./$(OUT)/main.o: main.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

# object files Testing
./$(OUT)/datum_test.o: ./Testing/datum_test.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

./$(OUT)/mitarbeiter_test.o: ./Testing/mitarbeiter_test.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

./$(OUT)/register_test.o: ./Testing/register_test.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

./$(OUT)/gui_test.o: ./Testing/gui_test.cpp
	$(CC) $(CFLAGS) -c $^ -o $@
