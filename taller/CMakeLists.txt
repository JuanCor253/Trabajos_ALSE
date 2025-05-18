
# filepath: /home/permafrost/Alse_1/Practica_dickson/QT/QT_EJEMPLO/SQlite/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(taller_dick)

set(CMAKE_CXX_STANDARD 17)

# Agregar el ejecutable
add_executable(taller_dick main.cpp taller_dick.cpp)

# Enlazar la biblioteca SQLite
target_link_libraries(taller_dick sqlite3)