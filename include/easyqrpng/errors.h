#ifndef H__EASYQRPNG_ERRORS__H
#define H__EASYQRPNG_ERRORS__H

typedef int easyqrpng_error_t;

#define EASYQRPNGERR_OK							0
#define EASYQRPNGERR_ENCODE_ERROR				1
#define EASYQRPNGERR_NOT_ENCODED				2
#define EASYQRPNGERR_ENCODEPNG_ERROR			3

#if defined(__cplusplus)
extern "C" {
#endif


char *easyqrpng_errormessage(easyqrpng_error_t);

#if defined(__cplusplus)
}
#endif

#endif // H__EASYQRPNG_ERRORS__H