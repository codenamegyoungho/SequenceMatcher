cmake_minimum_required(VERSION 3.10)
project(SequenceMatcher VERSION 1.0 LANGUAGES CXX)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 라이브러리 타겟 설정
add_library(SequenceMatcher STATIC 
    src/SequenceMatcher.cpp
)

# include 디렉토리 경로 추가
target_include_directories(SequenceMatcher PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
)

# 실행 파일 설정
add_executable(SequenceMatcherExample examples/main.cpp)

# 라이브러리 링크
target_link_libraries(SequenceMatcherExample PRIVATE SequenceMatcher)

