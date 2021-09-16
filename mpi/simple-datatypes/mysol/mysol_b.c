#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define size 8

int main(int argc, char **argv)
{
    int rank;
    int array[size][size];
    int err;
    int displacements[size/2];
    int counts[size/2];
    //TODO: Declare a variable storing the MPI datatype
    MPI_Datatype mydatatype;

    int i, j;
    err = MPI_Init(&argc, &argv); /* Initialize MPI */
    if (err != MPI_SUCCESS) {
        printf("MPI initialization failed!\n");
        exit(1);
    }
    // MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Initialize arrays
    if (rank == 0) {
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                array[i][j] = (i + 1) * 10 + j + 1;
            }
        }
    } else {
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                array[i][j] = 0;
            }
        }
    }

    if (rank == 0) {
        printf("Data in rank 0\n");
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                printf("%3d", array[i][j]);
            }
            printf("\n");
        }
    }

    //TODO: Create datatype

    for(int i=0; i < 4; i++){
        displacements[i] = i + (2*i*8);
        counts[i] = i +1;

    }

    // MPI_Type_vector(size, 1, size, MPI_INT, &mydatatype);
    MPI_Type_indexed(size/2, counts, displacements, MPI_INT, &mydatatype);
    MPI_Type_commit(&mydatatype);

    //TODO: Send data
    // Here we send the entire array and not the indexes of the array because we have already indexed.
    if (rank == 0) {
        MPI_Send(array, 1, mydatatype, 1, 1, MPI_COMM_WORLD);
    } else if (rank == 1) {
        MPI_Recv(array, 1, mydatatype, 0, 1, MPI_COMM_WORLD,
                 MPI_STATUS_IGNORE);
    }

    //TODO: Free datatype

    // Print out the result on rank 1
    if (rank == 1) {
        printf("Received data\n");
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                printf("%3d", array[i][j]);
            }
            printf("\n");
        }
    }

    MPI_Type_free(&mydatatype);
    MPI_Finalize();

    return 0;
}
