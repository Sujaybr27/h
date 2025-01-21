#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int data = 100 + rank;
    int received_data;

    if (rank == 0) {
        MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Rank 0 sent data: %d\n", data);

        MPI_Recv(&received_data, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Rank 0 received data: %d\n", received_data);
    } else if (rank == 1) {
        MPI_Request request;
        MPI_Isend(&data, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &request);
        printf("Rank 1 started sending data: %d\n", data);

        MPI_Irecv(&received_data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &request);
        MPI_Wait(&request, MPI_STATUS_IGNORE);
        printf("Rank 1 received data: %d\n", received_data);
    }

    MPI_Finalize();
    return 0;
}
