#include <easyqrpng/easyqrpngpp.h>

#include <iostream>

int main(int argc, char* argv[])
{
	easyqrpng p;
	p.setTargetWidth(500);

	if (p.encode("Encode me in a test")!=EASYQRPNGERR_OK)
	{
		std::cout << "ENCODE ERROR: " << p.errorMessage() << std::endl;
		return 0;
	}

	if (p.save("test.png")!=EASYQRPNGERR_OK)
	{
		std::cout << "SAVE ERROR: " << p.errorMessage() << std::endl;
		return 1;
	}

	std::cout << "OK" << std::endl;

	return 0;
}