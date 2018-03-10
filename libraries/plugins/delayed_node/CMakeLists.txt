file(GLOB HEADERS "include/enudex/delayed_node/*.hpp")

add_library( enudex_delayed_node 
             delayed_node_plugin.cpp
           )

target_link_libraries( enudex_delayed_node enudex_chain enudex_app )
target_include_directories( enudex_delayed_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( delayed_node_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   enudex_delayed_node

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
