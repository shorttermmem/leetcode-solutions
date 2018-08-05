# Set name / sources / headers
get_current_folder_name(COMPONENT_NAME)

list(APPEND ${COMPONENT_NAME}_SRC
"${CMAKE_CURRENT_LIST_DIR}/arrays.cpp"
)

list(APPEND ${COMPONENT_NAME}_HDR
"${CMAKE_CURRENT_LIST_DIR}"
)
