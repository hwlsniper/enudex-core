file(GLOB HEADERS "include/enudex/market_history/*.hpp")

add_library( enudex_market_history 
             market_history_plugin.cpp
           )

target_link_libraries( enudex_market_history enudex_chain enudex_app )
target_include_directories( enudex_market_history
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( market_history_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   enudex_market_history

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
INSTALL( FILES ${HEADERS} DESTINATION "include/enudex/market_history" )

