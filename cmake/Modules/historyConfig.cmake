INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_HISTORY history)

FIND_PATH(
    HISTORY_INCLUDE_DIRS
    NAMES history/api.h
    HINTS $ENV{HISTORY_DIR}/include
        ${PC_HISTORY_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    HISTORY_LIBRARIES
    NAMES gnuradio-history
    HINTS $ENV{HISTORY_DIR}/lib
        ${PC_HISTORY_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(HISTORY DEFAULT_MSG HISTORY_LIBRARIES HISTORY_INCLUDE_DIRS)
MARK_AS_ADVANCED(HISTORY_LIBRARIES HISTORY_INCLUDE_DIRS)

