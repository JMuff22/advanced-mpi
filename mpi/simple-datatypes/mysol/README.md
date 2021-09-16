## My Solution 

### Program A: Columned Data structure

This program should creates columns of the recieved data 

`mpicc -o mysol mysol.c`

`mpiexec -np 4 mysol`


```
Data in rank 0
 11 12 13 14 15 16 17 18
 21 22 23 24 25 26 27 28
 31 32 33 34 35 36 37 38
 41 42 43 44 45 46 47 48
 51 52 53 54 55 56 57 58
 61 62 63 64 65 66 67 68
 71 72 73 74 75 76 77 78
 81 82 83 84 85 86 87 88
Received data
  0 12  0  0  0  0  0  0
  0 22  0  0  0  0  0  0
  0 32  0  0  0  0  0  0
  0 42  0  0  0  0  0  0
  0 52  0  0  0  0  0  0
  0 62  0  0  0  0  0  0
  0 72  0  0  0  0  0  0
  0 82  0  0  0  0  0  0

 ```


### Program B: Partitioned data structure

Following the picture in `../README.md`, this program creates recieved data in incrementing rows. 

❯ mpicc -o mysol_b mysol_b.c
❯ mpiexec -np 4 mysol_b

```
Data in rank 0
 11 12 13 14 15 16 17 18
 21 22 23 24 25 26 27 28
 31 32 33 34 35 36 37 38
 41 42 43 44 45 46 47 48
 51 52 53 54 55 56 57 58
 61 62 63 64 65 66 67 68
 71 72 73 74 75 76 77 78
 81 82 83 84 85 86 87 88
Received data
 11  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0
  0 32 33  0  0  0  0  0
  0  0  0  0  0  0  0  0
  0  0 53 54 55  0  0  0
  0  0  0  0  0  0  0  0
  0  0  0 74 75 76 77  0
  0  0  0  0  0  0  0  0


```

### Program C: Block of received data


❯ mpicc -o mysol_c mysol_c.c
❯ mpiexec -np 4 mysol_c

- Interestingly using `&array[0][1]` in the MPI Send/Recv calls changes the order of the output :/ 

```
Data in rank 0
 11 12 13 14 15 16 17 18
 21 22 23 24 25 26 27 28
 31 32 33 34 35 36 37 38
 41 42 43 44 45 46 47 48
 51 52 53 54 55 56 57 58
 61 62 63 64 65 66 67 68
 71 72 73 74 75 76 77 78
 81 82 83 84 85 86 87 88
Received data
  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0
  0  0 33 34 35 36  0  0
  0  0 43 44 45 46  0  0
  0  0 53 54 55 56  0  0
  0  0 63 64 65 66  0  0
  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0

```