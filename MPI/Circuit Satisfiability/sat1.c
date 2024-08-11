/*Circuit Satisfiability, Version 1
*/

#include <mpi.h>
#include <stdio.h>
#include "check_circuit.h"

int main (int argc, char *argv[]) {
    int i;         /* Process rank */
    int id;
    int p;          /* Number of processes*/

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    for (i = id; i< 65536; i+=p)
        check_circuit (id, i);


    printf("Process %d is done\n", id) ;
    fflush(stdout);
    MPI_Finalize ();
    return 0;
}