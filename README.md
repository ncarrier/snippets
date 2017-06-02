# snippets
Example snippets of code, using various technologies / tools / patterns.

## gperf

[gperf](https://www.gnu.org/software/gperf/) is a tool for generating perfect hash functions.
It uses a configuration file format somewhat similar to those used by [f]lex and (bison|yacc).

### prerequisites

The tools used are `gcc`, `gperf` and `make`.

### usage

Go in the gperf directory and then do:

        make
        ./main

The expected output is:

        $ ./main
        pim is in set and pim.u = 42
        pam is in set and pam.u = 0
        poum is in set and poum.u = 888
        toto is in set and toto.u = 123
        wizz isn't in set
         isn't in set

# content

* **test.gperf**:
  Main file, contains the directives to generate `test.c`, containing the lookup function.
  Contains also the data set.
* **Makefile**:
  Simple Makefile for the snippet.
* **test.h**:
  Header containing the data structure definition and the prototypes of the functions exported from `test.c`.
* **main.c**:
  Simple test program using `test.c` as a library.
