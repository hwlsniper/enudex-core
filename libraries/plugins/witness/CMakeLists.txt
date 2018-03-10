file(GLOB HEADERS "include/enudex/witness/*.hpp")

add_library( enudex_witness 
             witness.cpp
           )

target_link_libraries( enudex_witness enudex_chain enudex_app )
target_include_directories( enudex_witness
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   enudex_witness

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
