include_directories(.)

#IF("${CMAKE_SYSTEM}" MATCHES "Linux")
#FIND_PACKAGE(LibElf REQUIRED)
#INCLUDE_DIRECTORIES(${LIBELF_INCLUDE_DIRS})
#ENDIF()


SET(SRCS
   main.cpp
)
SET(INCS
)

ADD_EXECUTABLE( easyqrpng_sample ${SRCS} ${INCS} )

TARGET_LINK_LIBRARIES ( easyqrpng_sample easyqrpngstatic )

TARGET_LINK_LIBRARIES ( easyqrpng_sample ${QREncodeWin_LIBRARY} )

#if (WIN32)
#TARGET_LINK_LIBRARIES ( mileversion_sample version )
#endif()
#IF("${CMAKE_SYSTEM}" MATCHES "Linux")
#TARGET_LINK_LIBRARIES ( mileversion_sample ${LIBELF_LIBRARIES} )
#ENDIF()
