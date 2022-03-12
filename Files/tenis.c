#include "utils.h"
#include "list.h"
#include "structures.h"
#include "tasks.h"

int main(int argc, char **argv)
{
    FILE *query, *fin, *fout;  
    query=fopen(argv[1], "r");
    fin=fopen(argv[2], "r");
    fout=fopen(argv[3], "w");
    readQuery(query, fin, fout);
    return 0;
}

