file(GLOB HEADERS "include/enudex/debug_witness/*.hpp")

add_library( enudex_debug_witness
             debug_api.cpp
             debug_witness.cpp
           )

target_link_libraries( enudex_debug_witness enudex_chain enudex_app )
target_include_directories( enudex_debug_witness
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   enudex_debug_witness

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
