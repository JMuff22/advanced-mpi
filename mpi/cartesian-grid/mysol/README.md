## Cartesian grid process topology

Explore a Cartesian grid process topology by writing a toy program, where

- the MPI processes are arranged into a 2D Cartesian grid
- every task prints out their linear rank together with its coordinates
  in the process grid
- every task prints out the linear rank of their nearest neighboring
  processes

Run the code with both periodic and non-periodic boundaries, and experiment
with the direction and displacement parameters of the `MPI_Cart_shift`
routine.

You can start from scratch or use one of the provided skeleton codes
([skeleton.c](skeleton.c) or [skeleton.f90](skeleton.f90)).


### Solution

```c
    /* Create the 2D Cartesian communicator */
    /* TO DO */
    int reorder = 1;
    MPI_Cart_create(MPI_COMM_WORLD, MAXDIMS, dims,periods, reorder, &new_comm);

    MPI_Comm_rank(new_comm, &my_id);
    MPI_Cart_coords(new_comm,my_id, MAXDIMS, coords);


    /* Find out and store the neighboring ranks */
    /* TO DO */

    MPI_Cart_shift(new_comm, 0, -1, &neighbors[0], &neighbors[1]);
    MPI_Cart_shift(new_comm, 1, -1, &neighbors[2], &neighbors[3]);

    /* Find out and store also the Cartesian coordinates of a rank */
    /* TO DO */
    MPI_Cart_coords(new_comm,my_id, MAXDIMS, coords);

```

- Also added `#define MAXDIMS 2` for ease. 

- Also added a makefile. Make skeleton.c with `make skeleton`, run with `mpiexec -np 4 skeleton` or `mpiexec -np 16 --oversubscribe skeleton`
