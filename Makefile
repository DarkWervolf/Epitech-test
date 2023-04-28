build: src/main.c
	gcc -o "build/boggle" "src/main.c"

run: build
	./build/boggle