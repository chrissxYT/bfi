all:
	@gcc bfi.c -Ofast -s -o bfi

test:
	@gcc bfi.c -Og -fsanitize=address -o bfi
	@./bfi helloworld.bf

install:all
	@cp -f bfi /usr/bin/bfi

uninstall:
	@rm -f /usr/bin/bfi

clean:
	@rm -f bfi
