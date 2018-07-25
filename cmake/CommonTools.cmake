
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
