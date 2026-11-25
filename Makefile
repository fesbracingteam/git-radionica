# Ne mijenjaj ovu datoteku.
CFLAGS = -std=c99 -Wall -Wextra -I.
SRC = main.c registry.c $(wildcard topics/*.c)

quiz: $(SRC) quiz.h
	$(CC) $(CFLAGS) -o $@ $(SRC)

run: quiz
	./quiz

# Provjerava pitanja i da je svaka topics/pNN.c upisana u registry.c
check: quiz
	./quiz --check
	@for f in topics/p*.c; do \
		[ -e "$$f" ] || continue; \
		id=$$(basename "$$f" .c); \
		grep -q "&topic_$$id," registry.c || { echo "GREŠKA: $$id nije upisan u registry.c"; exit 1; }; \
	done
	@echo "Sve u redu."

scenario-oops:
	@sh scenarios/oops.sh "$(ID)"

clean:
	rm -f quiz quiz.exe

.PHONY: run check scenario-oops clean
