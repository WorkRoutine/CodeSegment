How to compile 32-bit program on 64-bit machine
-------------------------------------------------

1. Install 32-bit library,as follow:
   sudo apt-get install libc6-dev-i386

2. Add option "-m32" when you compile program,as:
   gcc Simple.s -m32 -o out

### How to debug in gdb

  1. Add "-g" options when you compile your program:

  ```
gcc file.x -g -o out
  ```

  2. Utilize gdb to debug program:

  ```
gdb a
  ```

  3. Set brakpointer on your program, such as:

  ```
b main
  ```

  4. Run program.

  ```
r
  ```

  5. Dump all regiters and single register.

  ```
  info registers

  info register eax
  ```

  when you use this command, system will dump register, as follow:
  ```
  (gdb) info registers
  eax            0xc	12
  ecx            0x3	3
  edx            0xf7fb3870	-134530960
  ebx            0x0	0
  esp            0xffffcf0c	0xffffcf0c
  ebp            0x0	0x0
  esi            0xf7fb2000	-134537216
  edi            0xf7fb2000	-134537216
  eip            0x8048429	0x8048429 <loop1+20>
  eflags         0x292	[ AF SF IF ]
  cs             0x23	35
  ss             0x2b	43
  ds             0x2b	43
  es             0x2b	43
  fs             0x0	0
  gs             0x63	99
  ```

  6. Demp memory with specific address:

  ```
x/30uh specific-address
  ```

  For this command, `30` is number of data which start with specific address,
  `u` is display in hex, `h` will be show double data. as follow:

  ```
  (gdb) x/40uh 0xffffcf0c
  0xffffcf0c:	34359	63457	1	0	53156	65535	53164	65535
  0xffffcf1c:	0	0	0	0	0	0	8192	63483
  0xffffcf2c:	56324	63487	53248	63487	0	0	8192	63483
  0xffffcf3c:	8192	63483	0	0	21067	63519	40027	50314
  0xffffcf4c:	0	0	0	0	0	0	1	0
  ```

  7. Break from function that doesn't debug, you can use `step`, as follow:

  ```
  (gdb) n
  17		call printf
  (gdb) n
  0x080482e0 in printf@plt ()
  (gdb) step
  Single stepping until exit from function printf@plt,
  which has no line number information.
  0xf7e49670 in printf () from /lib/i386-linux-gnu/libc.so.6
  (gdb) n
  Single stepping until exit from function printf,
  which has no line number information.
  The total is: 14
  loop1 () at test.s:18
  18		add $8, %esp
  (gdb)
  ```

  8. Load symbol table

  You will be can't get symbol from gdb, you can reload symbol as follow:

  ```
file your-binary-file-name
  ```

  9. exit debug

  When you finish to debug, you can use `q` to quit gdb

  ```
q/quit
  ```
