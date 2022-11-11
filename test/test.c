#include "ippsdftwrapper.h"
#include "ipp.h"
#include "ipps.h"
#include <stdio.h>

void printvec(Ipp64fc* pBuf, int N)
{
	for (int i = 0; i < N; ++i)
	{
		printf("%f, %f\n", pBuf[i].re, pBuf[i].im);
	}
}

void printvec2(Ipp64f* pBufRe, Ipp64f* pBufIm, int N)
{
	for (int i = 0; i < N; ++i)
	{
		printf("%f, %f\n", pBufRe[i], pBufIm[i]);
	}
}

int main()
{
	int N = 1020;
	Ipp64fc* pSrc = ippsMalloc_64fc(N);
	Ipp64fc* pDst = ippsMalloc_64fc(N);

	for (int i = 0; i < N; ++i)
	{
		pSrc[i].re = 1;
		pSrc[i].im = 0;
	}
	printvec(pSrc, 2);

	DFTSpec* spec;
	dft_init_64fc(&spec, N, DIV_FWD_BY_N);
	dft_fwd_64fc(spec, pSrc, pDst);
	printvec(pDst, 2);
	dft_free(spec);
	ippsFree(pSrc);
	ippsFree(pDst);
	printf("\n\n\n\n");

	Ipp64f* pSrcRe = ippsMalloc_64f(N);
	Ipp64f* pSrcIm = ippsMalloc_64f(N);
	Ipp64f* pDstRe = ippsMalloc_64f(N);
	Ipp64f* pDstIm = ippsMalloc_64f(N);
	for (int i = 0; i < N; ++i)
	{
		pSrcRe[i] = 1;
		pSrcIm[i] = 0;
	}
	printvec2(pSrcRe, pSrcIm, 2);
	DFTSpec* spec2;
	dft_init_64f(&spec2, N, DIV_FWD_BY_N);
	dft_fwd_64f(spec2, pSrcRe, pSrcIm, pDstRe, pDstIm);
	printvec2(pDstRe, pDstIm, 2);
	dft_free(spec2);
	ippsFree(pSrcRe);
	ippsFree(pSrcIm);
	ippsFree(pDstRe);
	ippsFree(pDstIm);

	return 0;
}
