project(IO|Lab)
set(SOURCE_EXE main.cpp ring_buffer/ring_buffer.cpp queue/queue.cpp)
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)
add_executable(main ${SOURCE_EXE})