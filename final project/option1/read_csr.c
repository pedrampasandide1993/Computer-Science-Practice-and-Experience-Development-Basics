#include <gsl/gsl_spmatrix.h>

gsl_spmatrix *ReadMMtoCSR(const char *filename)
{
     FILE *file = fopen(filename, "r");
    if (!file)
    {
        fprintf(stderr, "Failed to open file %s\n", filename);
        return NULL;
    }

    gsl_spmatrix *coo = gsl_spmatrix_fscanf(file);
    if (!coo)
    {
        fprintf(stderr, "Failed to read matrix from file %s\n", filename);
        fclose(file);
        return NULL;
    }

    // gsl_spmatrix *csr = gsl_spmatrix_alloc_nzmax(coo->size1, coo->size2, coo->nz, GSL_SPMATRIX_CSR);

    // // // converting from COO format to CSR
    gsl_spmatrix *csr = gsl_spmatrix_crs(coo);
    

    gsl_spmatrix_free(coo);
    fclose(file);
    return csr;
}