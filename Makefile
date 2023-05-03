build: src/main.c
	gcc -o "build/boggle" "src/main.c" "src/util.c" "src/word_finder.c"

run: build
	./build/boggle

clean:
	rm -rf build/*