#include "easyqrpng/easyqrpngpp.h"

#include <qrencode.h>

#include "lodepng.h"

#define cimg_display 0
#define cimg_no_system_calls 1
#include "CImg.h"

#include <fstream>

using namespace cimg_library;

class easyqrpngImpl
{
public:
	easyqrpngImpl() : targetWidth(100), margin(0), qrcode(NULL), error(EASYQRPNGERR_OK) {}
	~easyqrpngImpl() { freeImpl(); }

	int targetWidth;
	int margin;
	QRcode* qrcode;
	easyqrpng_error_t error;

	void freeImpl()
	{
		if (qrcode != NULL)
		{
			QRcode_free(qrcode);
			qrcode = NULL;
		}
	}
};


easyqrpng::easyqrpng() : _impl(new easyqrpngImpl)
{

}

easyqrpng::~easyqrpng()
{
	delete _impl;
}

void easyqrpng::setTargetWidth(int width)
{
	_impl->targetWidth = width;
}

int easyqrpng::getTargetWidth() const
{
	return _impl->targetWidth;
}

void easyqrpng::setMargin(int margin)
{
	_impl->margin = margin;
}

int easyqrpng::getMargin() const
{
	return _impl->margin;
}

easyqrpng_error_t easyqrpng::encode(const char *data)
{
	_impl->freeImpl();
	_impl->qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);
	if (_impl->qrcode == NULL)
	{
		return setError(EASYQRPNGERR_ENCODE_ERROR);
	}
	return setError(EASYQRPNGERR_OK);
}

easyqrpng_error_t easyqrpng::encode(const std::string &data)
{
	return encode(data.c_str());
}

easyqrpng_error_t easyqrpng::save(const char *filename)
{
	std::fstream output(filename, std::ios_base::out|std::ios_base::binary|std::ios_base::trunc);
	return save(output);
}

easyqrpng_error_t easyqrpng::save(const std::string &filename)
{
	return save(filename.c_str());
}

easyqrpng_error_t easyqrpng::save(std::ostream &output)
{
	if (_impl->qrcode == NULL)
		return setError(EASYQRPNGERR_NOT_ENCODED);

	int width = _impl->qrcode->width;
	int margin = _impl->margin;
	int size = _impl->targetWidth / width;
	if (size < 1)
		size = 1;

	const unsigned char colWhite[] = { 255, 255, 255 };
	const unsigned char colBlack[] = { 0, 0, 0 };
	
	CImg<unsigned char> cimage(width*size + margin*2, width*size + margin*2, 1, 3);
	cimage.draw_rectangle(0, 0, cimage.width(), cimage.height(), colWhite);

	unsigned char *p = _impl->qrcode->data;
	for(int y=0; y<width; y++) {
		for(int x=0; x<width; x++) {
			const unsigned char *cl = (*p&1) ? &colBlack[0] : &colWhite[0];
			cimage.draw_rectangle(margin + x*size, margin + y*size, margin + x*size+size, margin + y*size+size, cl);
			p++;
		}
	}

	// must convert to lodepng format
	CImg<unsigned char> cimageinter = cimage.get_permute_axes("cxyz");

	unsigned char* out;
	size_t outsize;
	unsigned error = lodepng_encode24(&out, &outsize, cimageinter.data(), cimage.width(), cimage.height());
	if (error)
		return setError(EASYQRPNGERR_ENCODEPNG_ERROR);

	output.write(reinterpret_cast<const char*>(out), outsize);
	if (output.bad())
		return setError(EASYQRPNGERR_ENCODEPNG_ERROR);

	return setError(EASYQRPNGERR_OK);
}


easyqrpng_error_t easyqrpng::setError(easyqrpng_error_t e)
{
	_impl->error = e;
	return e;
}


easyqrpng_error_t easyqrpng::error()
{
	return _impl->error;
}

std::string easyqrpng::errorMessage()
{
	return easyqrpng_errormessage(_impl->error);
}
