# snippets

Example snippets of code, using various technologies / tools / patterns.

All the snippets use the tools `gcc` and `make`.

## queue

The [sys/queue.h](https://linux.die.net/man/3/queue) API is a little known
header coming along with a standard glibc distribution.
It provides macro-based and consistent implementations, for the main types of
queues and lists.

This set of snippets, provide simple (no unneeded mallocs...) yet exhaustive and
coherent examples of usage of each of the sub-API, allowing to see it in action
and to compare it against the other ones, easily.

The man page which can be found in the previous link, as well as the one
provided in linux distributions, are not complete as they don't mention all the
sub-APIs available.
These snippets hopefully fill that gap.

### usage

Go in the `queue/` directory and then do:

        make
        # doubly-linked list API demo
        ./list
        # singly-linked list API demo
        ./slist
        # singly-linked tail queue API demo
        ./stailq
        # singly-linked queue API demo
        ./simpleq
        # doubly-linked tail queue API demo
        ./tailq
        # circular queue API demo
        ./circleq

### content

* **{list,slist,stailq,simpleq,tailq,circleq}.c**: Source code of all the API
demos.
* **Makefile**: simple Makefile for the snippet.
Each C source file added in the directory will be built as an executable.

## gperf

[gperf](https://www.gnu.org/software/gperf/) is a tool for generating perfect hash functions.
It uses a configuration file format somewhat similar to those used by
[\[f\]lex](https://github.com/westes/flex) and
[(bison|yacc)](https://www.gnu.org/software/bison/).

### extra prerequisites

`gperf` is needed to build the snippet.

### usage

Go in the `gperf/` directory and then do:

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

### content

* **test.gperf**:
  Main file, contains the directives to generate `test.c`, containing the lookup function.
  Contains also the data set.
* **Makefile**:
  Simple Makefile for the snippet.
* **test.h**:
  Header containing the data structure definition and the prototypes of the functions exported from `test.c`.
* **main.c**:
  Simple test program using `test.c` as a library.

## generate_permutations

Generates all permutation of [0,n), that is, bijections of [0,n) into itself and
allow to iterate on the set of these permutations.
This iterator on permutation is used to call step functions in all the possible
orders.

### usage

Go in the `generate\_permutations` directory and then do:

        make
        ./main

The expected output is:

        $ ./main
        0: stepA
        1: stepB
        2: stepC
        0: stepA
        1: stepC
        2: stepB
        0: stepB
        1: stepA
        2: stepC
        0: stepB
        1: stepC
        2: stepA
        0: stepC
        1: stepA
        2: stepB
        0: stepC
        1: stepB
        2: stepA

### content

* **main.c**:
  Main file, contains the function allowing to iterate on the permutation and a
  test `main()`.
* **Makefile**:
  Simple Makefile for the snippet.

