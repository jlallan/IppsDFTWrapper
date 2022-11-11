#ifndef IPPSDFT_WRAPPER_H
#define IPPSDFT_WRAPPER_H

#include "ipp.h"
#include "ipps.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

typedef struct DFTSpec DFTSpec;

void dft_free(DFTSpec* s);

#define IPPSDFT_DEFINE_API(R, C)                                        \
                                                                        \
void dft_init_##R(DFTSpec** sp, int length, int flag);                \
void dft_init_##C(DFTSpec** sp, int length, int flag);                \
void dft_fwd_##R(const DFTSpec* s, const Ipp##R* pSrcRe,               \
			const Ipp##R* pSrcIm, Ipp##R* pDstRe, Ipp##R* pDstIm);   \
void dft_fwd_##C(const DFTSpec* s, const Ipp##C* pSrc, Ipp##C* pDst); \
void dft_inv_##R(const DFTSpec* s, const Ipp##R* pSrcRe,               \
			const Ipp##R* pSrcIm, Ipp##R* pDstRe, Ipp##R* pDstIm);   \
void dft_inv_##C(const DFTSpec* s, const Ipp##C* pSrc, Ipp##C* pDst); \

IPPSDFT_DEFINE_API(32f, 32fc);
IPPSDFT_DEFINE_API(64f, 64fc);
#undef IPPSDFT_DEFINE_API

/* DFT Division Flags Shortnames */
#define DIV_FWD_BY_N IPP_FFT_DIV_FWD_BY_N
#define DIV_INV_BY_N IPP_FFT_DIV_INV_BY_N
#define DIV_BY_SQRTN IPP_FFT_DIV_BY_SQRTN
#define NODIV_BY_ANY IPP_FFT_NODIV_BY_ANY

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* IPPSDFT_WRAPPER_H */
