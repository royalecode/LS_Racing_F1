cmake_minimum_required(VERSION 3.15)
project(grupo-4 C)

set(CMAKE_C_STANDARD 11)
set(ALLEGRO_DIR "C:\\MinGW")
include_directories(${ALLEGRO_DIR}/include)
link_directories(${ALLEGRO_DIR}/lib)

add_executable(grupo-4 main.c LS_allegro.c LS_allegro.h menu.c menu.h funciones_Basicas.c funciones_Basicas.h conf_Coche.c conf_Coche.h pieza.c pieza.h premio.c premio.h corredores.c corredores.h carrera.c carrera.h base.c base.h tiempo.c tiempo.h)

target_link_libraries(grupo-4 -lmingw32 -lallegro-5.0.10-monolith-md-debug)