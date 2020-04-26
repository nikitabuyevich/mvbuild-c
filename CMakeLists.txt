cmake_minimum_required(VERSION 3.15)
project(mvbuild C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

include_directories(lib)

set(SRC_FILES src/main.c)
set(LIB_FILES lib/stb/stb.h lib/stb/stb_ds.h)
set(PKG_FILES src/wnd/wnd.c src/wnd/wnd.h src/cmd/cmd.c src/cmd/cmd.h src/cp/cp.c src/cp/cp.h)

add_executable(mvbuild ${SRC_FILES} ${LIB_FILES} ${PKG_FILES})