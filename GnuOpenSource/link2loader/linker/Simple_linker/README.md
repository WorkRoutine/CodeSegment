Simple Linker and Loader
---------------------------------------

### Usage

* Review object file

  ```
gcc m.c -c -o m.o
objdump -s -d m.o
  ```
  Output symbol table
  ```
objdump -t m.o
  ```
  Output descripts of all segments
  ```
objdump -h m.o
  ```
  Output specify segment
  ```
objdump -j .text -S m.o
objdump -j .data -S m.o
  ```
  Output assembly and C
  ```
objdump -S m.o
  ```
