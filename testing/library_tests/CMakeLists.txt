add_executable(ConwayLibraryTests
        game_class_tests.cpp
        game_grid_class_tests.cpp
        utilities_tests.cpp)
target_link_libraries(ConwayLibraryTests Conway)