## HDF5 example

Study and test the HDF5 examples ([hdf5.c](hdf5.c) or [hdf5.f90](hdf5.f90))
where the [Simple MPI-IO exercise](../mpi-io) has been re-written with HDF5
using collective parallel write.

On Puhti, you will need to load the module `hdf5/1.10.4-mpi` before you can
compile the code:

```
 module load hdf5/1.10.4-mpi
```

Compile and run the program. You can use the `h5dump` command to check the
values in a HDF5 file.

### Installing HDF5

Installing hdf5 with OpenMPI. (On Debian).

```bash
apt-get install libhdf5-openmpi-dev
```

Install HDF5 Tools:

```bash
apt-get install hdf5-tools
```

Normal installation:

```bash
apt-get install hdf5-helpers
```

### Compilation 

```
h5pcc.openmpi -o output hdf5.c
```


```
h5pfc.openmpi -o output_f hdf5.f90
```


### Running 

```
mpirun -np 4 output
```

```
h5dump data.h5
```

```
 h5ls data.h5
```

### Example output

```bash
❯ h5dump data.h5
HDF5 "data.h5" {
GROUP "/" {
   DATASET "data" {
      DATATYPE  H5T_STD_I32LE
      DATASPACE  SIMPLE { ( 64 ) / ( 64 ) }
      DATA {
      (0): 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
      (19): 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
      (35): 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
      (51): 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64
      }
   }
}
}
```

```bash
❯ h5ls data.h5
data                     Dataset {64}
```

### Useful tools

h5dump
h5ls
h5mkrgrp
h5diff
h5stat
h5repack
h5repart
h5redeploy
h5unjam
h5clear
h5copy
h5debug
g5debug


----- Compilers ---

h5c++ - C++ compiler
h5cc - C compiler


