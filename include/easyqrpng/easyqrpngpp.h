#ifndef H__EASYQRPNGPP__H
#define H__EASYQRPNGPP__H

#include <easyqrpng/errors.h>

#include <string>
#include <iostream>

class easyqrpngImpl;

class easyqrpng
{
public:
	easyqrpng();
	virtual ~easyqrpng();

	void setTargetWidth(int width);
	int getTargetWidth() const;

	easyqrpng_error_t encode(const char *data);
	easyqrpng_error_t encode(const std::string &data);

	easyqrpng_error_t save(const char *filename);
	easyqrpng_error_t save(const std::string &filename);
	easyqrpng_error_t save(std::ostream &output);

	easyqrpng_error_t setError(easyqrpng_error_t e);

	easyqrpng_error_t error();
	std::string errorMessage();
private:
	easyqrpngImpl *_impl;
};



#endif // H__EASYQRPNG__H