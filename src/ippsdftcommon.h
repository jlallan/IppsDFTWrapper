#ifndef IPPSDFT_COMMON_H
#define IPPSDFT_COMMON_H

#include "ippsdftwrapper.h"
#include "ipp.h"
#include "ipps.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#ifdef DEBUG
#define IPPCHECKSTATUS(s) ipp_check_status(s)
#else
#define IPPCHECKSTATUS(s)
#endif /* DEBUG */

struct DFTSpec
{
    int length;
    int flag;
    IppHintAlgorithm hint;
    int sizeSpec;
    int sizeInit;
    int sizeBuf;
    void* pIppsDFTSpec;
    Ipp8u* pMemInit;
    Ipp8u* pWorkBuf;
};

void ipp_check_status(IppStatus status);
void dft_struct_init(DFTSpec** sp, int length, int flag);
void dft_malloc(DFTSpec* s);
void dft_free(DFTSpec* s);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* IPPSDFT_COMMON_H */
