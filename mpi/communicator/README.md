## Communicators and collectives

In this exercise we combine collective communication with user defined
communicators. Write a program for four MPI processes, such that each
process has a data vector with the following data:

![](https://github.com/csc-training/summerschool/blob/master/mpi/collectives/img/sendbuffer.png)

In addition, each task has a receive buffer for eight elements and the
values in the buffer are initialized to -1.

Implement now a pattern with user defined communicators and collective
operation so that the receive buffers will have the following values:

![](https://raw.githubusercontent.com/csc-training/summerschool/master/mpi/communicator/img/comm-split-reduce.svg?sanitize=true)

You can start from scratch or use the skeleton code
[collective.cpp](collective.cpp), [collective.c](collective.c) or
[collective.F90](collective.F90).


