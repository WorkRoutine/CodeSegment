Dynatic linker library
--------------------------------------------------------

* Platform: Ubuntu16.04/64bit

#### Usage

* Create Shared library
```
gcc SharedLibrary.c -fPIC -shared -o SharedLibrary.so
```

* Use shared library
```
gcc Dynatic_main.c ./SharedLibrary.so -o main

gcc Dynatic_sub.c ./SharedLibrary.so -o sub
```
