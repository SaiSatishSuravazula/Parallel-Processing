/*Circuit Satisfiability, Version 2
*/

#include <mpi.h>
#include <stdio.h>
#include "check_circuit.h"


int main(int argc, char *argv[]) {
    int id;                 // Process rank
    int p;                  // Number of processes
    int solutions = 0;      // Solutions found by this process
    int global_solutions;   // Total number of solutions across all processes

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    // Loop over the range of values handled by this process
    for (int i = id; i < 65536; i += p) {
        solutions += check_circuit(id, i);
    }

    // Reduce results from all processes to process 0
    MPI_Reduce(&solutions, &global_solutions, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    printf("Process %d is done\n", id);
    fflush(stdout);

    // Print the results from process 0
    if (id == 0) {
        printf("There are %d different solutions\n", global_solutions);
    }

    MPI_Finalize();
    return 0;
}