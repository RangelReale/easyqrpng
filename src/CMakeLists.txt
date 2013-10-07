SET(SRCS
	easyqrpng.c errors.c easyqrpngpp.cpp
	
	lodepng.cpp
)

SET(INCS
	../include/easyqrpng/easyqrpng.h
	../include/easyqrpng/easyqrpngpp.h
	../include/easyqrpng/errors.h
	lodepng.h
	CImg.h
)

ADD_LIBRARY(easyqrpng SHARED ${SRCS} ${INCS} )
ADD_LIBRARY(easyqrpngstatic STATIC ${SRCS} ${INCS} )

TARGET_LINK_LIBRARIES ( easyqrpng ${QRENCODE_LIBRARY} )

