all : dfs

dfs : obj/dfs.o
	g++ obj/dfs.o -o dfs

obj/dfs.o : src/dfs.cpp
	g++ -c src/dfs.cpp -o obj/dfs.o