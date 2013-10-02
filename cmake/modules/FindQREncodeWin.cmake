FIND_PATH(QREncodeWin_ROOT_DIR NAMES qrencode.h)

SET(QREncodeWin_FOUND 0)

IF(QREncodeWin_ROOT_DIR)
  IF(EXISTS "${QREncodeWin_ROOT_DIR}/qrencode.h")
        SET(QREncodeWin_INCLUDE_DIR "${QREncodeWin_ROOT_DIR}")
        SET(QREncodeWin_FOUND 1)
  ELSE()
      MESSAGE(FATAL_ERROR "QREncodeWin was not found.")
  ENDIF()
  
  IF(QREncodeWin_FOUND)
        FIND_LIBRARY(QREncodeWin_LIBRARY_DEBUG NAMES qrcodelib.lib)
        FIND_LIBRARY(QREncodeWin_LIBRARY_RELEASE NAMES qrcodelib.lib)
        
        SET(QREncodeWin_LIBRARY
          debug ${QREncodeWin_LIBRARY_DEBUG}
          optimized ${QREncodeWin_LIBRARY_RELEASE}
        )        
  ENDIF()
ENDIF()
