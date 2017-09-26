Usage:
readelf -a SharedLibrary.so
--------------------------------------------------------------

ELF Header:
  Magic:   7f 45 4c 46 01 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF32
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              DYN (Shared object file)
  Machine:                           Intel 80386
  Version:                           0x1
  Entry point address:               0x440
  Start of program headers:          52 (bytes into file)
  Start of section headers:          4404 (bytes into file)
  Flags:                             0x0
  Size of this header:               52 (bytes)
  Size of program headers:           32 (bytes)
  Number of program headers:         7
  Size of section headers:           40 (bytes)
  Number of section headers:         28
  Section header string table index: 25

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .note.gnu.build-i NOTE            00000114 000114 000024 00   A  0   0  4
  [ 2] .gnu.hash         GNU_HASH        00000138 000138 00003c 04   A  3   0  4
  [ 3] .dynsym           DYNSYM          00000174 000174 0000e0 10   A  4   1  4
  [ 4] .dynstr           STRTAB          00000254 000254 0000c1 00   A  0   0  1
  [ 5] .gnu.version      VERSYM          00000316 000316 00001c 02   A  3   0  2
  [ 6] .gnu.version_r    VERNEED         00000334 000334 000030 00   A  4   1  4
  [ 7] .rel.dyn          REL             00000364 000364 000040 08   A  3   0  4
  [ 8] .rel.plt          REL             000003a4 0003a4 000020 08   A  3  10  4
  [ 9] .init             PROGBITS        000003c4 0003c4 000023 00  AX  0   0  4
  [10] .plt              PROGBITS        000003f0 0003f0 000050 04  AX  0   0 16
  [11] .text             PROGBITS        00000440 000440 000164 00  AX  0   0 16
  [12] .fini             PROGBITS        000005a4 0005a4 000014 00  AX  0   0  4
  [13] .rodata           PROGBITS        000005b8 0005b8 000024 00   A  0   0  4
  [14] .eh_frame_hdr     PROGBITS        000005dc 0005dc 00001c 00   A  0   0  4
  [15] .eh_frame         PROGBITS        000005f8 0005f8 000064 00   A  0   0  4
  [16] .init_array       INIT_ARRAY      00001f00 000f00 000004 00  WA  0   0  4
  [17] .fini_array       FINI_ARRAY      00001f04 000f04 000004 00  WA  0   0  4
  [18] .jcr              PROGBITS        00001f08 000f08 000004 00  WA  0   0  4
  [19] .dynamic          DYNAMIC         00001f0c 000f0c 0000e0 08  WA  4   0  4
  [20] .got              PROGBITS        00001fec 000fec 000014 04  WA  0   0  4
  [21] .got.plt          PROGBITS        00002000 001000 00001c 04  WA  0   0  4
  [22] .data             PROGBITS        0000201c 00101c 000004 00  WA  0   0  4
  [23] .bss              NOBITS          00002020 001020 000004 00  WA  0   0  1
  [24] .comment          PROGBITS        00000000 001020 000024 01  MS  0   0  1
  [25] .shstrtab         STRTAB          00000000 001044 0000f0 00      0   0  1
  [26] .symtab           SYMTAB          00000000 001594 000390 10     27  44  4
  [27] .strtab           STRTAB          00000000 001924 0001f3 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings)
  I (info), L (link order), G (group), T (TLS), E (exclude), x (unknown)
  O (extra OS processing required) o (OS specific), p (processor specific)

There are no section groups in this file.

Program Headers:
  Type           Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align
  LOAD           0x000000 0x00000000 0x00000000 0x0065c 0x0065c R E 0x1000
  LOAD           0x000f00 0x00001f00 0x00001f00 0x00120 0x00124 RW  0x1000
  DYNAMIC        0x000f0c 0x00001f0c 0x00001f0c 0x000e0 0x000e0 RW  0x4
  NOTE           0x000114 0x00000114 0x00000114 0x00024 0x00024 R   0x4
  GNU_EH_FRAME   0x0005dc 0x000005dc 0x000005dc 0x0001c 0x0001c R   0x4
  GNU_STACK      0x000000 0x00000000 0x00000000 0x00000 0x00000 RW  0x10
  GNU_RELRO      0x000f00 0x00001f00 0x00001f00 0x00100 0x00100 R   0x1

 Section to Segment mapping:
  Segment Sections...
   00     .note.gnu.build-id .gnu.hash .dynsym .dynstr .gnu.version .gnu.version_r .rel.dyn .rel.plt .init .plt .text .fini .rodata .eh_frame_hdr .eh_frame 
   01     .init_array .fini_array .jcr .dynamic .got .got.plt .data .bss 
   02     .dynamic 
   03     .note.gnu.build-id 
   04     .eh_frame_hdr 
   05     
   06     .init_array .fini_array .jcr .dynamic .got 

Dynamic section at offset 0xf0c contains 24 entries:
  Tag        Type                         Name/Value
 0x00000001 (NEEDED)                     Shared library: [libc.so.6]
 0x0000000c (INIT)                       0x3c4
 0x0000000d (FINI)                       0x5a4
 0x00000019 (INIT_ARRAY)                 0x1f00
 0x0000001b (INIT_ARRAYSZ)               4 (bytes)
 0x0000001a (FINI_ARRAY)                 0x1f04
 0x0000001c (FINI_ARRAYSZ)               4 (bytes)
 0x6ffffef5 (GNU_HASH)                   0x138
 0x00000005 (STRTAB)                     0x254
 0x00000006 (SYMTAB)                     0x174
 0x0000000a (STRSZ)                      193 (bytes)
 0x0000000b (SYMENT)                     16 (bytes)
 0x00000003 (PLTGOT)                     0x2000
 0x00000002 (PLTRELSZ)                   32 (bytes)
 0x00000014 (PLTREL)                     REL
 0x00000017 (JMPREL)                     0x3a4
 0x00000011 (REL)                        0x364
 0x00000012 (RELSZ)                      64 (bytes)
 0x00000013 (RELENT)                     8 (bytes)
 0x6ffffffe (VERNEED)                    0x334
 0x6fffffff (VERNEEDNUM)                 1
 0x6ffffff0 (VERSYM)                     0x316
 0x6ffffffa (RELCOUNT)                   3
 0x00000000 (NULL)                       0x0

Relocation section '.rel.dyn' at offset 0x364 contains 8 entries:
 Offset     Info    Type            Sym.Value  Sym. Name
00001f00  00000008 R_386_RELATIVE   
00001f04  00000008 R_386_RELATIVE   
0000201c  00000008 R_386_RELATIVE   
00001fec  00000106 R_386_GLOB_DAT    00000000   _ITM_deregisterTMClone
00001ff0  00000406 R_386_GLOB_DAT    00000000   __cxa_finalize
00001ff4  00000506 R_386_GLOB_DAT    00000000   __gmon_start__
00001ff8  00000606 R_386_GLOB_DAT    00000000   _Jv_RegisterClasses
00001ffc  00000706 R_386_GLOB_DAT    00000000   _ITM_registerTMCloneTa

Relocation section '.rel.plt' at offset 0x3a4 contains 4 entries:
 Offset     Info    Type            Sym.Value  Sym. Name
0000200c  00000207 R_386_JUMP_SLOT   00000000   printf
00002010  00000307 R_386_JUMP_SLOT   00000000   sleep
00002014  00000407 R_386_JUMP_SLOT   00000000   __cxa_finalize
00002018  00000507 R_386_JUMP_SLOT   00000000   __gmon_start__

The decoding of unwind sections for machine type Intel 80386 is not currently supported.

Symbol table '.dynsym' contains 14 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 00000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_deregisterTMCloneTab
     2: 00000000     0 FUNC    GLOBAL DEFAULT  UND printf@GLIBC_2.0 (2)
     3: 00000000     0 FUNC    GLOBAL DEFAULT  UND sleep@GLIBC_2.0 (2)
     4: 00000000     0 FUNC    WEAK   DEFAULT  UND __cxa_finalize@GLIBC_2.1.3 (3)
     5: 00000000     0 NOTYPE  WEAK   DEFAULT  UND __gmon_start__
     6: 00000000     0 NOTYPE  WEAK   DEFAULT  UND _Jv_RegisterClasses
     7: 00000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_registerTMCloneTable
     8: 00002020     0 NOTYPE  GLOBAL DEFAULT   22 _edata
     9: 00002024     0 NOTYPE  GLOBAL DEFAULT   23 _end
    10: 00002020     0 NOTYPE  GLOBAL DEFAULT   23 __bss_start
    11: 000003c4     0 FUNC    GLOBAL DEFAULT    9 _init
    12: 000005a4     0 FUNC    GLOBAL DEFAULT   12 _fini
    13: 0000056b    57 FUNC    GLOBAL DEFAULT   11 foobar

Symbol table '.symtab' contains 57 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 00000114     0 SECTION LOCAL  DEFAULT    1 
     2: 00000138     0 SECTION LOCAL  DEFAULT    2 
     3: 00000174     0 SECTION LOCAL  DEFAULT    3 
     4: 00000254     0 SECTION LOCAL  DEFAULT    4 
     5: 00000316     0 SECTION LOCAL  DEFAULT    5 
     6: 00000334     0 SECTION LOCAL  DEFAULT    6 
     7: 00000364     0 SECTION LOCAL  DEFAULT    7 
     8: 000003a4     0 SECTION LOCAL  DEFAULT    8 
     9: 000003c4     0 SECTION LOCAL  DEFAULT    9 
    10: 000003f0     0 SECTION LOCAL  DEFAULT   10 
    11: 00000440     0 SECTION LOCAL  DEFAULT   11 
    12: 000005a4     0 SECTION LOCAL  DEFAULT   12 
    13: 000005b8     0 SECTION LOCAL  DEFAULT   13 
    14: 000005dc     0 SECTION LOCAL  DEFAULT   14 
    15: 000005f8     0 SECTION LOCAL  DEFAULT   15 
    16: 00001f00     0 SECTION LOCAL  DEFAULT   16 
    17: 00001f04     0 SECTION LOCAL  DEFAULT   17 
    18: 00001f08     0 SECTION LOCAL  DEFAULT   18 
    19: 00001f0c     0 SECTION LOCAL  DEFAULT   19 
    20: 00001fec     0 SECTION LOCAL  DEFAULT   20 
    21: 00002000     0 SECTION LOCAL  DEFAULT   21 
    22: 0000201c     0 SECTION LOCAL  DEFAULT   22 
    23: 00002020     0 SECTION LOCAL  DEFAULT   23 
    24: 00000000     0 SECTION LOCAL  DEFAULT   24 
    25: 00000000     0 FILE    LOCAL  DEFAULT  ABS crtstuff.c
    26: 00001f08     0 OBJECT  LOCAL  DEFAULT   18 __JCR_LIST__
    27: 00000450     0 FUNC    LOCAL  DEFAULT   11 deregister_tm_clones
    28: 00000490     0 FUNC    LOCAL  DEFAULT   11 register_tm_clones
    29: 000004e0     0 FUNC    LOCAL  DEFAULT   11 __do_global_dtors_aux
    30: 00002020     1 OBJECT  LOCAL  DEFAULT   23 completed.6590
    31: 00001f04     0 OBJECT  LOCAL  DEFAULT   17 __do_global_dtors_aux_fin
    32: 00000530     0 FUNC    LOCAL  DEFAULT   11 frame_dummy
    33: 00001f00     0 OBJECT  LOCAL  DEFAULT   16 __frame_dummy_init_array_
    34: 00000000     0 FILE    LOCAL  DEFAULT  ABS SharedLibrary.c
    35: 00000000     0 FILE    LOCAL  DEFAULT  ABS crtstuff.c
    36: 00000658     0 OBJECT  LOCAL  DEFAULT   15 __FRAME_END__
    37: 00001f08     0 OBJECT  LOCAL  DEFAULT   18 __JCR_END__
    38: 00000000     0 FILE    LOCAL  DEFAULT  ABS 
    39: 00000440     4 FUNC    LOCAL  DEFAULT   11 __x86.get_pc_thunk.bx
    40: 0000201c     0 OBJECT  LOCAL  DEFAULT   22 __dso_handle
    41: 00001f0c     0 OBJECT  LOCAL  DEFAULT   19 _DYNAMIC
    42: 00002020     0 OBJECT  LOCAL  DEFAULT   22 __TMC_END__
    43: 00002000     0 OBJECT  LOCAL  DEFAULT   21 _GLOBAL_OFFSET_TABLE_
    44: 00000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_deregisterTMCloneTab
    45: 00000000     0 FUNC    GLOBAL DEFAULT  UND printf@@GLIBC_2.0
    46: 00002020     0 NOTYPE  GLOBAL DEFAULT   22 _edata
    47: 00000000     0 FUNC    GLOBAL DEFAULT  UND sleep@@GLIBC_2.0
    48: 000005a4     0 FUNC    GLOBAL DEFAULT   12 _fini
    49: 0000056b    57 FUNC    GLOBAL DEFAULT   11 foobar
    50: 00000000     0 FUNC    WEAK   DEFAULT  UND __cxa_finalize@@GLIBC_2.1
    51: 00000000     0 NOTYPE  WEAK   DEFAULT  UND __gmon_start__
    52: 00002024     0 NOTYPE  GLOBAL DEFAULT   23 _end
    53: 00002020     0 NOTYPE  GLOBAL DEFAULT   23 __bss_start
    54: 00000000     0 NOTYPE  WEAK   DEFAULT  UND _Jv_RegisterClasses
    55: 00000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_registerTMCloneTable
    56: 000003c4     0 FUNC    GLOBAL DEFAULT    9 _init

Histogram for `.gnu.hash' bucket list length (total of 3 buckets):
 Length  Number     % of total  Coverage
      0  0          (  0.0%)
      1  0          (  0.0%)      0.0%
      2  3          (100.0%)    100.0%

Version symbols section '.gnu.version' contains 14 entries:
 Addr: 0000000000000316  Offset: 0x000316  Link: 3 (.dynsym)
  000:   0 (*local*)       0 (*local*)       2 (GLIBC_2.0)     2 (GLIBC_2.0)  
  004:   3 (GLIBC_2.1.3)   0 (*local*)       0 (*local*)       0 (*local*)    
  008:   1 (*global*)      1 (*global*)      1 (*global*)      1 (*global*)   
  00c:   1 (*global*)      1 (*global*)   

Version needs section '.gnu.version_r' contains 1 entries:
 Addr: 0x0000000000000334  Offset: 0x000334  Link: 4 (.dynstr)
  000000: Version: 1  File: libc.so.6  Cnt: 2
  0x0010:   Name: GLIBC_2.1.3  Flags: none  Version: 3
  0x0020:   Name: GLIBC_2.0  Flags: none  Version: 2

Displaying notes found at file offset 0x00000114 with length 0x00000024:
  Owner                 Data size	Description
  GNU                  0x00000014	NT_GNU_BUILD_ID (unique build ID bitstring)
    Build ID: 6f8a46a1de6cd8ecbbf731c27dd8d2a4388c3819
