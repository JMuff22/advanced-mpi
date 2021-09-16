## Changes

Make sure to 

```bash
export COMP=gnu
```

For gnu compilers or

```bash
export COMP=intel
```

If compiled correctly this should create the binary `heat_mpi` 

Example output:

```bash
❯ mpiexec -np 4 heat_mpi
Simulation parameters: rows: 2000 columns: 2000 time steps: 500
Number of MPI tasks: 4
Average temperature at start: 59.763305
Iteration took 3.093458 seconds.
Average temperature: 59.281239
Reference value with default arguments: 59.281239

```