FIND_PATH(QREncodeWin_ROOT_DIR NAMES qrencode.h)

SET(QREncodeWin_FOUND 0)

IF(QREncodeWin_ROOT_DIR)
  IF(EXISTS "${QREncodeWin_ROOT_DIR}/qrencode.h")
        SET(QRENCODE_INCLUDE_DIR "${QREncodeWin_ROOT_DIR}")
        SET(QREncodeWin_FOUND 1)
  ELSE()
      MESSAGE(FATAL_ERROR "QREncodeWin was not found.")
  ENDIF()
  
  IF(QREncodeWin_FOUND)
        FIND_LIBRARY(QRENCODE_LIBRARY_DEBUG NAMES qrcodelib.lib)
        FIND_LIBRARY(QRENCODE_LIBRARY_RELEASE NAMES qrcodelib.lib)
        
        SET(QRENCODE_LIBRARY
          debug ${QRENCODE_LIBRARY_DEBUG}
          optimized ${QRENCODE_LIBRARY_RELEASE}
        )        
  ENDIF()
ENDIF()
