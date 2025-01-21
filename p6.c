#include<mpi.h>
#include<stdio.h>

int main(int argc, char** argv)
{
	int rank, size, mp, t;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	mp = rank + 1;
	MPI_Reduce(&mp,&t,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	if (rank ==0)
	printf("%d",t);
	MPI_Finalize();
}
