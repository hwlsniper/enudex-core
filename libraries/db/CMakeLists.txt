file(GLOB HEADERS "include/enudex/db/*.hpp")
add_library( enudex_db undo_database.cpp index.cpp object_database.cpp ${HEADERS} )
target_link_libraries( enudex_db fc )
target_include_directories( enudex_db PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   enudex_db

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/enudex/db" )
