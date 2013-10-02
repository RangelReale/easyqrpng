#include "easyqrpng/errors.h"

static char *MSG_EASYQRPNGERR_OK = "OK";
static char *MSG_EASYQRPNGERR_ENCODE_ERROR = "Encode error";
static char *MSG_EASYQRPNGERR_NOT_ENCODED = "Not encoded";
static char *MSG_EASYQRPNGERR_ENCODEPNG_ERROR = "PNG encoding error";

char *easyqrpng_errormessage(easyqrpng_error_t e)
{
	switch(e)
	{
	case EASYQRPNGERR_OK:
		return MSG_EASYQRPNGERR_OK;
	case EASYQRPNGERR_ENCODE_ERROR:
		return MSG_EASYQRPNGERR_ENCODE_ERROR;
	case EASYQRPNGERR_NOT_ENCODED:
		return MSG_EASYQRPNGERR_NOT_ENCODED;
	case EASYQRPNGERR_ENCODEPNG_ERROR:
		return MSG_EASYQRPNGERR_ENCODEPNG_ERROR;
	}
	return "UNKNOWN ERROR";
}
