
# PRINT_CMAKE_VARIABLES
# ------------------------
#
# A helper function to print CMAKE configure time variables

function(PRINT_CMAKE_VARIABLES)
    get_cmake_property(_variableNames VARIABLES)
    list (SORT _variableNames)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
endfunction()


# GET_CURRENT_FOLDER_NAME
# ------------------------
#
# A helper function to get current directory name

function(GET_CURRENT_FOLDER_NAME folderName)
    get_filename_component(localStr ${CMAKE_CURRENT_LIST_DIR} NAME)
    string(REPLACE " " "_" localStr ${localStr})
    string(TOLOWER ${localStr} localStr)
    set(${folderName} ${localStr} PARENT_SCOPE)
endfunction()


# TARGET_LINK_EXT_LIBRARIES
# ------------------------
#
# A helper function to suppress 3rd compile and linking warnings

function(TARGET_LINK_EXT_LIBRARIES target)
    set(libs ${ARGN})
    foreach(lib ${libs})
        get_target_property(lib_include_dirs ${lib} INTERFACE_INCLUDE_DIRECTORIES)
        target_include_directories(${target} SYSTEM PUBLIC ${lib_include_dirs})
        target_link_libraries(${target} PUBLIC ${lib})
    endforeach(lib)
endfunction(TARGET_LINK_EXT_LIBRARIES)