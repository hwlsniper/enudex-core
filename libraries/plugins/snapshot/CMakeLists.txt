file(GLOB HEADERS "include/enudex/snapshot/*.hpp")

add_library( enudex_snapshot
             snapshot.cpp
           )

target_link_libraries( enudex_snapshot enudex_chain enudex_app )
target_include_directories( enudex_snapshot
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   enudex_snapshot

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
