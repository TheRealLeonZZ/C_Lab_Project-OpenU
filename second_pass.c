#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "symbol.h"
#include "parser.h"
#include "extern.h"
#include "binary.h"
#include "variables.h"

/*

In second pass I have a complete symbol list and syntax ready assembly file.
I continue to check if operands are correct, every .entry is in symbol list, every external symbol is decleared with .extern.
I also re-count memory,ic and dc. Encode each line to 12 bit binary and build binary table,
Build variable table of entry and extern to output later to files.

 */
void secondPass(const char *input_file, struct Symbol *symbol_table, struct Extern *extern_table, struct Binary *binary_code_table, struct Variable *variable_table, int *passed_second, int *ic, int *dc)
{

    /* Openes the input file for reading and checks for errors when opening the file */
    FILE *assembly_file = fopen(input_file, "r");
    if (assembly_file == NULL)
    {
        fprintf(stderr, "Error opening the assembly file.\n");
        *passed_second = 0;
        return;
    }

    /* Parse 2nd pass */
    parseSecondPass(assembly_file, symbol_table, extern_table, binary_code_table, variable_table, passed_second, ic, dc);
    fclose(assembly_file);
}