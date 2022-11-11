#include "ippsdfttg.h"

/**
 * Sets buffer and struct sizes for separated transform
 */
void FR(dft_get_size)(DFTSpec* s)
{
	IppStatus status = FR(ippsDFTGetSize_C)(s->length, s->flag, s->hint,
				&(s->sizeSpec), &(s->sizeInit), &(s->sizeBuf));
	IPPCHECKSTATUS(status);
}

/**
 * Sets parameters of separated transform
 */
void FR(dft_setup)(DFTSpec* s)
{
	IppStatus status = FR(ippsDFTInit_C)(s->length, s->flag, s->hint,
				(IppsDFTSpec_R*) s->pIppsDFTSpec, s->pMemInit);
	IPPCHECKSTATUS(status);
	ippsFree(s->pMemInit);
}

/**
 * Allocates and initializes fields of a separated DFTSpec
 */
void FR(dft_init)(DFTSpec** sp, int length, int flag)
{
	dft_struct_init(sp, length, flag);
	FR(dft_get_size)(*sp);
	dft_malloc(*sp);
	FR(dft_setup)(*sp);
}

/**
 * Executes forward transform on separated real and imaginary inputs
 */
void FR(dft_fwd)(const DFTSpec* s, const R* pSrcRe, const R* pSrcIm,
			R* pDstRe, R* pDstIm)
{
	IppStatus status = FR(ippsDFTFwd_CToC)(pSrcRe, pSrcIm, pDstRe, pDstIm,
				(IppsDFTSpec_R*) s->pIppsDFTSpec, s->pWorkBuf);
	IPPCHECKSTATUS(status);
}

/**
 * Executes inverse transform on separated real and imaginary inputs
 */
void FR(dft_inv)(const DFTSpec* s, const R* pSrcRe, const R* pSrcIm,
			R* pDstRe, R* pDstIm)
{
	IppStatus status = FR(ippsDFTInv_CToC)(pSrcRe, pSrcIm, pDstRe, pDstIm,
				(IppsDFTSpec_R*) s->pIppsDFTSpec, s->pWorkBuf);
	IPPCHECKSTATUS(status);
}

/**
 * Sets buffer and struct sizes for complex transform
 */
void FC(dft_get_size)(DFTSpec* s)
{
	IppStatus status = FC(ippsDFTGetSize_C)(s->length, s->flag, s->hint,
				&(s->sizeSpec), &(s->sizeInit), &(s->sizeBuf));
	IPPCHECKSTATUS(status);
}

/**
 * Sets parameters of complex transform
 */
void FC(dft_setup)(DFTSpec* s)
{
	IppStatus status = FC(ippsDFTInit_C)(s->length, s->flag, s->hint,
				(IppsDFTSpec_C*) s->pIppsDFTSpec, s->pMemInit);
	IPPCHECKSTATUS(status);
	ippsFree(s->pMemInit);
}

/**
 * Allocates and initializes fields of a real DFTSpec
 */
void FC(dft_init)(DFTSpec** sp, int length, int flag)
{
	dft_struct_init(sp, length, flag);
	FC(dft_get_size)(*sp);
	dft_malloc(*sp);
	FC(dft_setup)(*sp);
}

/**
 * Executes forward transform on complex input
 */
void FC(dft_fwd)(const DFTSpec* s, const C* pSrc, C* pDst)
{
	IppStatus status = FC(ippsDFTFwd_CToC)(pSrc, pDst,
				(IppsDFTSpec_C*) s->pIppsDFTSpec, s->pWorkBuf);
	IPPCHECKSTATUS(status);
}

/**
 * Executes inverse transform on complex input
 */
void FC(dft_inv)(const DFTSpec* s, const C* pSrc, C* pDst)
{
	IppStatus status = FC(ippsDFTInv_CToC)(pSrc, pDst,
				(IppsDFTSpec_C*) s->pIppsDFTSpec, s->pWorkBuf);
	IPPCHECKSTATUS(status);
}
