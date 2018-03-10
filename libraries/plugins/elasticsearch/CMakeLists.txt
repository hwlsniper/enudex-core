file(GLOB HEADERS "include/enudex/elasticsearch/*.hpp")

add_library( enudex_elasticsearch
        elasticsearch_plugin.cpp
           )

target_link_libraries( enudex_elasticsearch enudex_chain enudex_app curl )
target_include_directories( enudex_elasticsearch
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties(elasticsearch_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   enudex_elasticsearch

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
INSTALL( FILES ${HEADERS} DESTINATION "include/enudex/elasticsearch" )

