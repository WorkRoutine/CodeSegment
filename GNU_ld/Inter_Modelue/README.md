Call function or Data access on different modules or inter-modules
--------------------------------------------------------------------

Platform: Ubuntu14.04/32bit

Data: Information_objdump_32bit

### Create dynatic library

We should create a dynatic library, as follow:
```
gcc AssemblySub0.c -shared -fPIC -o AssemblySub0.so
```
We can also output useful information, as follow:
```
objdump -ht -d -s AssemblySub0.so
```

### Inter-module Data access

```
static int a = 3;

void sub1(void) 
{
	a += 4;	
}
```

As above, we define a int value and use this value on inter modules.
The value store in date section, we will get relative offset of data section for 
current text section from linker(ld or ldd).

```
0000059b <sub1>:
 59b:   55                      push   %ebp
 59c:   89 e5                   mov    %esp,%ebp
 59e:   e8 74 00 00 00          call   617 <__x86.get_pc_thunk.cx>
 5a3:   81 c1 5d 1a 00 00       add    $0x1a5d,%ecx 
 5a9:   8b 81 20 00 00 00       mov    0x20(%ecx),%eax
 5af:   83 c0 04                add    $0x4,%eax
 5b2:   89 81 20 00 00 00       mov    %eax,0x20(%ecx)
 5b8:   5d                      pop    %ebp
 5b9:   c3                      ret
```

We utilize a haker skill that call `__x86.get_pc_thunk.cx` to get current value of PC.
For this code segment, the current PC is `5a3`. And we can cacluate address of `got.plt` section.
As follow:
```
The address of gol.plt => 0x1a5d + 0x5a3 => 0x2000 
```
And, we store the address of `gol.plt` on `ecx`, we will caclute the address of `a`
```
mov 0x20(%ecx), %eax
```
According to this code segment, we can confirm that the address of `a` is 0x2020.
We attach this area:
```
Contents of section .got:
 1fe8 00000000 00000000 00000000 00000000  ................
 1ff8 00000000 00000000                    ........
Contents of section .got.plt:
 2000 081f0000 00000000 00000000 36040000  ............6...
 2010 46040000 56040000 66040000           F...V...f...
Contents of section .data:
 201c 1c200000 05000000                    . ......
```
So, `a` stores on `0x2020`

### Inter-modules call

```
void sub1(void)
{
	a += 4;
}

void sub3(void)
{
	sub1();
}
```

As above, we define two functions named sub1 and sub3, and sub3 invokes sub1 on same module.
We will get relative offset for all on compiling. So we can get assembly code, as follow:
```
000005dd <sub3>:
 5dd:   55                      push   %ebp
 5de:   89 e5                   mov    %esp,%ebp
 5e0:   53                      push   %ebx
 5e1:   83 ec 04                sub    $0x4,%esp
 5e4:   e8 87 fe ff ff          call   470 <__x86.get_pc_thunk.bx>
 5e9:   81 c3 17 1a 00 00       add    $0x1a17,%ebx
 5ef:   e8 6c fe ff ff          call   460 <sub1@plt>
 5f4:   83 c4 04                add    $0x4,%esp
 5f7:   5b                      pop    %ebx
 5f8:   5d                      pop    %ebp
 5f9:   c3                      ret

```
At first, we should get current PC value via calling `__x86.get_pc_thunk.bx`, the PC is `5e9`.
Then, we should caclute the address of `got.plt`, as follow:
```
The address of got.plt => 0x5e9 + 0x1a17 => 0x2000
```
The last, we use `E8` that short jump on the inter-modules call, the jump address we should caclute 
before jumping, we can caclute as follow:
```
The jump address => 0x5f4 - 0x460 => 194
```
Now, we should use complment code for jump address,
the complment code of `0x194` is `0xFFFF FE6C`, so the jump code is:
```
E8 6C FE FF FF FF
```

According above, we get code entry of `sub1@plt`:
```
00000460 <sub1@plt>:
 460:   ff a3 18 00 00 00       jmp    *0x18(%ebx)
 466:   68 18 00 00 00          push   $0x18
 46b:   e9 b0 ff ff ff          jmp    420 <_init+0x28>
```

The value of `ebx` is address of `got.plt`. And the address of 'sub1' is
```
The address of sub => 0x2000 + 0x18 = 0x2018
```
We output the area of `got.plt`
```
Contents of section .got:
 1fe8 00000000 00000000 00000000 00000000  ................
 1ff8 00000000 00000000                    ........
Contents of section .got.plt:
 2000 081f0000 00000000 00000000 36040000  ............6...
 2010 46040000 56040000 66040000           F...V...f...
Contents of section .data:
 201c 1c200000 05000000                    . ......
```
So, the address of `sub1` is `0x2018`

We can also utilize `objdump` to review it:
```
objdump -R AssemblySub0.so

output:

00002018 R_386_JUMP_SLOT sub1
```

### Different module data access

```
extern int b;

void sub2(void)
{
	b += 2;
}

```

The same as above, we should get PC and caclute address of `got.plt`, as follow:
```
000005ba <sub2>:
 5ba:   55                      push   %ebp
 5bb:   89 e5                   mov    %esp,%ebp
 5bd:   e8 55 00 00 00          call   617 <__x86.get_pc_thunk.cx>
 5c2:   81 c1 3e 1a 00 00       add    $0x1a3e,%ecx
 5c8:   8b 81 ec ff ff ff       mov    -0x14(%ecx),%eax
 5ce:   8b 00                   mov    (%eax),%eax
 5d0:   8d 50 02                lea    0x2(%eax),%edx
 5d3:   8b 81 ec ff ff ff       mov    -0x14(%ecx),%eax
 5d9:   89 10                   mov    %edx,(%eax)
 5db:   5d                      pop    %ebp
 5dc:   c3                      ret
```
The address of `got.plt` cacluted as follow:
```
Address = 0x1a3e + 5c2 = 0x2000
```
Then, according relative offset of `got.plt`, we can get the address of `b`.
```
Address = 0x2000 -0x14 = 0x1FEC
```
Print this area:
```
Contents of section .got:
 1fe8 00000000 00000000 00000000 00000000  ................
 1ff8 00000000 00000000                    ........
Contents of section .got.plt:
 2000 081f0000 00000000 00000000 36040000  ............6...
 2010 46040000 56040000 66040000           F...V...f...
Contents of section .data:
 201c 1c200000 05000000                    . ......
```

We can use this address to invoke `b` when program execute.
We can use `objdump` to reviem this address.
```
objdump -R AssemblySub0.so

output:
00001fec R_386_JUMP_SLOT b
```

### Different modules invoke 

```
extern void sub0(void);

void sub4(void)
{
	sub0();
}

```
The same as accessing date between different modules, we can get assembly:
```
000005fa <sub4>:
 5fa:   55                      push   %ebp
 5fb:   89 e5                   mov    %esp,%ebp
 5fd:   53                      push   %ebx
 5fe:   83 ec 04                sub    $0x4,%esp
 601:   e8 6a fe ff ff          call   470 <__x86.get_pc_thunk.bx>
 606:   81 c3 fa 19 00 00       add    $0x19fa,%ebx
 60c:   e8 1f fe ff ff          call   430 <sub0@plt>
 611:   83 c4 04                add    $0x4,%esp
 614:   5b                      pop    %ebx
 615:   5d                      pop    %ebp
 616:   c3                      ret
```
The first, we get current PC value and caclute the address of `got.plt`:
```
Address = 0x606 + 0x19fa = 0x2000
```
So, the addrees of `got.plt` is 0x2000, we store value on `ebx`.
But, we should invoke `sub0@plt` first, the invoke address is:
```
Address = 0x611 - 0x430 = 0x1E1
Complmement Code = 0xFFFFFE1F
```
So, jump command is:
```
E8 1F FE FF FF
```
The sub0@plt is:
```
00000430 <sub0@plt>:
 430:   ff a3 0c 00 00 00       jmp    *0xc(%ebx)
 436:   68 00 00 00 00          push   $0x0
 43b:   e9 e0 ff ff ff          jmp    420 <_init+0x28>
```
According above, we can caclute the address of `sbu0`:
```
Address = 0x2000 + 0xc = 0x200c
```
The `got.plt` contain this address:
```
Contents of section .got:
 1fe8 00000000 00000000 00000000 00000000  ................
 1ff8 00000000 00000000                    ........
Contents of section .got.plt:
 2000 081f0000 00000000 00000000 36040000  ............6...
 2010 46040000 56040000 66040000           F...V...f...
Contents of section .data:
 201c 1c200000 05000000                    . ......
```
We can utilize `objdump` to review this value:
```
objbump -R AssemblySub0.so

output:
0000200c R_386_JUMP_SLOT sub0
```

* Read .dynamic section
```
readelf -d AssemblySub0.so
```

* Check depends of shared library or main ELF
```
ldd AssemblySub0.so
```
