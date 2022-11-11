#include "ippsdftcommon.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Checks for runtime errors from Intel IPP functions
 *
 * Implemented through CHECKIPPSTATUS macro, conditioned on DEBUG flag
 */
void ipp_check_status(IppStatus status)
{
	if (status != ippStsNoErr)
	{
		fprintf(stderr, "%s\n", ippGetStatusString(status));
		exit(EXIT_FAILURE);
	}
}

/**
 * Checks that input size for IppsDFT is valid
 */
void dft_check_size(int length)
{
	if (length < 1)
	{
		fprintf(stderr, "Transform size is less than one.\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * Allocates DFTSpec structure and initialize fields
 */
void dft_struct_init(DFTSpec** sp, int length, int flag)
{
	DFTSpec* s = malloc(sizeof(struct DFTSpec));
	dft_check_size(length);
	s->length = length;
	s->flag   = flag;
	s->hint   = ippAlgHintNone;
	*sp = s;
}

/**
 * Allocates DFTSpec internal buffers
 */
void dft_malloc(DFTSpec* s)
{
	s->pIppsDFTSpec = ippsMalloc_8u(s->sizeSpec);
    s->pMemInit = ippsMalloc_8u(s->sizeInit);
    s->pWorkBuf = ippsMalloc_8u(s->sizeBuf);
}

/**
 * Destroys DFTSpec struct and internal buffers
 */
void dft_free(DFTSpec* s)
{
	ippsFree(s->pIppsDFTSpec);
	ippsFree(s->pWorkBuf);
	free(s);
}
