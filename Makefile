
# detect Operating System and choose compiler
ifeq ($(OS),Windows_NT)
    CC = g++
    ENDING = exe
else
    CC = g++
    ENDING = out
endif

CFLAGS = -g -Wall
OUT = Binaries

all:
	@echo ---------- MitarbeiterRegister ----------
	@echo TESTING:
	@echo     test_datum  
	@echo     test_mitarbeiter
	@echo MAIN:
	@echo     main

test_datum: $(OUT)/Datum.o $(OUT)/datum_test.o
	$(CC) $(CFLAGS) $^ -o ./$(OUT)/$@.$(ENDING)

test_mitarbeiter: $(OUT)/Datum.o $(OUT)/Mitarbeiter.o $(OUT)/mitarbeiter_test.o
	$(CC) $(CFLAGS) $^ -o ./$(OUT)/$@.$(ENDING)

./$(OUT)/Mitarbeiter.o: Mitarbeiter.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

./$(OUT)/Datum.o: Datum.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

./$(OUT)/datum_test.o: ./Testing/datum_test.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

./$(OUT)/mitarbeiter_test.o: ./Testing/mitarbeiter_test.cpp
	$(CC) $(CFLAGS) -c $^ -o $@


