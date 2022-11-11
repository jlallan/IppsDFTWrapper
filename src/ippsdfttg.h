#ifndef IPPSDFT_TG_H
#define IPPSDFT_TG_H

#include "ippsdftwrapper.h"
#include "ippsdftcommon.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#define FCONCAT(A, B) A ## _ ## B

#if defined (DFT_SINGLE) /* Compile for single precision */
typedef Ipp32f R;
typedef Ipp32fc C;
typedef IppsDFTSpec_C_32f IppsDFTSpec_R;
typedef IppsDFTSpec_C_32fc IppsDFTSpec_C;
#define FR(A) FCONCAT(A, 32f)
#define FC(A) FCONCAT(A, 32fc)

#else /* Compile for double precision by default */
typedef Ipp64f R;
typedef Ipp64fc C;
typedef IppsDFTSpec_C_64f IppsDFTSpec_R;
typedef IppsDFTSpec_C_64fc IppsDFTSpec_C;
#define FR(A) FCONCAT(A, 64f)
#define FC(A) FCONCAT(A, 64fc)

#endif /* Precision setting */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* IPPSDFT_TG_H */
