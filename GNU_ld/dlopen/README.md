dlopen
-------------------------------------
* platform: Ubuntu16.04/x64

### Generate Shared library

  Use command to generate shared library:
  ```
gcc SharedSub.c -shared -fPIC -o libSharedSub.so
  ```

### Invoke shared library and compile project

  Use command to compile project
  ```
gcc main.c -L. -lSharedSub -ldl -o main
  ```
