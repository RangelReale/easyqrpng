#ifndef H__EASYQRPNG__H
#define H__EASYQRPNG__H

#include <easyqrpng/errors.h>

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct easyqrpng_data easyqrpng_data;

easyqrpng_data* easyqrpng_new();
void easyqrpng_free(easyqrpng_data* data);

easyqrpng_error_t easyqrpng_encode(const char *data, int length);
easyqrpng_error_t easyqrpng_save(easyqrpng_data* data, const char *filename);
char *easyqrpng_get_data(easyqrpng_data* data);
int easyqrpng_get_length(easyqrpng_data* data);

easyqrpng_error_t easyqrpng_error(easyqrpng_data* data);
//char *easyqrpng_errormessage(easyqrpng_data* data);

#if defined(__cplusplus)
}
#endif


#endif // H__EASYQRPNG__H