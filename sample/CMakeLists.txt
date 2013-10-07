include_directories(.)

SET(SRCS
   main.cpp
)
SET(INCS
)

ADD_EXECUTABLE( easyqrpng_sample ${SRCS} ${INCS} )

TARGET_LINK_LIBRARIES ( easyqrpng_sample easyqrpngstatic )

TARGET_LINK_LIBRARIES ( easyqrpng_sample ${QRENCODE_LIBRARY} )

