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

TARGET_LINK_LIBRARIES ( easyqrpng ${QREncodeWin_LIBRARY} )

#if (WIN32)
#TARGET_LINK_LIBRARIES ( mileversion version )
#endif()
#IF("${CMAKE_SYSTEM}" MATCHES "Linux")
#TARGET_LINK_LIBRARIES ( mileversion ${LIBELF_LIBRARIES} )
#ENDIF()
