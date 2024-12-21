cmake_minimum_required (VERSION 3.11)

project(editor-texto
  LANGUAGES CXX
  VERSION 1.0.0
)

# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v5.0.0
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# --- Fetch GoogleTest ---------------------------------------------------------

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

# --- Ejecutable: editor-texto ---------------------------------------------

add_executable(editor-texto editor_main.cpp editor_texto.cpp resaltador.cpp ui.hpp)
target_include_directories(editor-texto PRIVATE .)

target_link_libraries(editor-texto
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component # Not needed for this example.
)

# --- Ejecutable: editor-tests -------------------------------------------------

add_executable(editor-tests editor_tests.cpp editor_texto.h editor_texto.cpp resaltador.cpp ui.hpp)

add_executable(resaltador-tests resaltador_tests.cpp resaltador.h resaltador.cpp)

target_link_libraries(
  editor-tests
  gtest_main
)

target_link_libraries(
  resaltador-tests
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(editor-tests)
gtest_discover_tests(resaltador-tests)

#if (EMSCRIPTEN) 
	#string(APPEND CMAKE_CXX_FLAGS " -s USE_PTHREADS") 
	#string(APPEND CMAKE_EXE_LINKER_FLAGS " -s ASYNCIFY") 
	#string(APPEND CMAKE_EXE_LINKER_FLAGS " -s PROXY_TO_PTHREAD") 

  #  foreach(file "index.html" "run_webassembly.py")
  #  configure_file("src/${file}" ${file})
  #endforeach(file)
  #endif() 
