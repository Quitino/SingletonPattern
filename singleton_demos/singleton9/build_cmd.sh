g++ -c ./main.cpp
g++ -c ./src.cpp
g++ ./main.o ./src.o -o ./ms
g++ ./src.o ./main.o -o ./sm

# valgrind  --tool=callgrind ./a.out
# /usr/bin/time ./a.out