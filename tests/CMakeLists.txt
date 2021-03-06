
macro(configure_gtest)
    if ("${GTEST_HOME}" STREQUAL "")
        message(FATAL_ERROR "GTEST_HOME not set")
    endif()
    set(GTEST_INCLUDE_DIRS ${GTEST_HOME}/include)
    set(GTEST_LIBRARY_DIRS ${GTEST_HOME}/build)
    set(GTEST_LIBRARIES gtest)
    if (NOT MSVC)
        set(GTEST_LIBRARIES ${GTEST_LIBRARIES} pthread)
    endif()
endmacro (configure_gtest)

###############################################################################

configure_gtest()

set (PROJECT_TYPE "Tests")

# Create parent target for tests

add_custom_target (RUN_ALL_TESTS)
set_target_properties (RUN_ALL_TESTS PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD TRUE EXCLUDE_FROM_ALL TRUE)
set_target_properties (RUN_ALL_TESTS PROPERTIES FOLDER ${PROJECT_TYPE})

# Appends test 
macro(AddTest testname target)
    # Copy executable to /bin for ease of use
    get_target_property (BIN_LOCATION ${target} LOCATION)
    add_custom_command (
        TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND}
        ARGS -E copy_if_different ${BIN_LOCATION} ${CMAKE_SOURCE_DIR}/bin
    )
    # Create a test runner
    add_custom_target (
        RUN_TEST_${testname}
        COMMAND ${target}
        DEPENDS ${target}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    )
    set_target_properties (RUN_TEST_${testname} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD TRUE EXCLUDE_FROM_ALL TRUE)
    set_target_properties (RUN_TEST_${testname} PROPERTIES FOLDER ${PROJECT_TYPE})
     
    # Add test runner to RUN_ALL_TESTS
    add_dependencies (RUN_ALL_TESTS RUN_TEST_${testname})
endmacro()

macro (CreateTest testname testsrcs)
    # Init target with provided name, eg. "Scene" > TestScene
    init_target(TundraTest${testname})
    remove_definitions (-DMODULE_EXPORTS)

    UseTundraCore()
    use_modules(TundraCore)
    use_package(GTEST)
    include_directories(${CMAKE_SOURCE_DIR}/tests)

    add_executable (${TARGET_NAME} ${testsrcs})

    link_modules(TundraCore)
    link_package(GTEST)
    link_package(URHO3D)
    link_package(KNET)
    link_package(MATHGEOLIB)

    set_target_properties (${TARGET_NAME} PROPERTIES FOLDER ${PROJECT_TYPE})

    # Let cmake/ctest know of the test executable
    AddTest (${testname} ${TARGET_NAME})
    message(" ")
endmacro()

# Add all subfolders as projects
GetSubDirectories(TEST_SUBDIRS)
foreach (TEST_SUBDIR ${TEST_SUBDIRS})
    add_subdirectory (${TEST_SUBDIR})
endforeach()
