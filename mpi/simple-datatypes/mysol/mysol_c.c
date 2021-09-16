#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define size 8

int main(int argc, char **argv)
{
    int rank;
    int array[size][size];
    int err;
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

    int sizes[size/4] = {size, size};
    int subsizes[size/4] = {size/2, size/2};
    int blanks[size/4] = {size/4, size/4};

    //TODO: Create datatype
    MPI_Type_create_subarray(size/4, sizes, subsizes, blanks, MPI_ORDER_C, MPI_INT, &mydatatype);
    MPI_Type_commit(&mydatatype);

    //TODO: Send data
    if (rank == 0) {
        MPI_Send(&array[0][0], 1, mydatatype, 1, 1, MPI_COMM_WORLD);
    } else if (rank == 1) {
        MPI_Recv(&array[0][0], 1, mydatatype, 0, 1, MPI_COMM_WORLD,
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
