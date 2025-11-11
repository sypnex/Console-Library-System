cmake_minimum_required(VERSION 3.10)

project(KutuphaneProjesi LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Derleyiciye header dosyalarını nerede bulacağını söyleriz.
# (Yani "include/" klasörünü)
include_directories(include)

# Çalıştırılabilir dosyamızın adını (kutuphane) ve
# bu dosyayı oluşturmak için hangi .cpp dosyalarının gerektiğini belirtiriz.
add_executable(kutuphane
    src/main.cpp
    src/Kitap.cpp
    src/Envanter.cpp
)
