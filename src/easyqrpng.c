#include "easyqrpng/easyqrpng.h"

#include <qrencode.h>

#include <stdlib.h>

typedef struct easyqrpng_data
{
	QRcode* qrcode;
	int error;
} easyqrpng_data;


easyqrpng_data* easyqrpng_new()
{
	easyqrpng_data* ret = (easyqrpng_data*)malloc(sizeof(easyqrpng_data));
	//memset(
	ret->error = 0;


	return ret;
}

void easyqrpng_free(easyqrpng_data* data)
{
	
}

easyqrpng_error_t easyqrpng_encode(const char *data, int length)
{
	//data->qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);
	return EASYQRPNGERR_OK;
}

easyqrpng_error_t easyqrpng_save(easyqrpng_data* data, const char *filename)
{
	return EASYQRPNGERR_OK;
}

char *easyqrpng_get_data(easyqrpng_data* data)
{
	return NULL;
}

int easyqrpng_get_length(easyqrpng_data* data)
{
	return 0;
}

easyqrpng_error_t easyqrpng_error(easyqrpng_data* data)
{
	return EASYQRPNGERR_OK;
}

/*
char *easyqrpng_errormessage(easyqrpng_data* data)
{
	return NULL;
}
*/
