file(GLOB HEADERS "include/enudex/app/*.hpp")
file(GLOB EGENESIS_HEADERS "../egenesis/include/enudex/app/*.hpp")

add_library( enudex_app 
             api.cpp
             application.cpp
             util.cpp
             database_api.cpp
             impacted.cpp
             plugin.cpp
             ${HEADERS}
             ${EGENESIS_HEADERS}
           )

# need to link enudex_debug_witness because plugins aren't sufficiently isolated #246
target_link_libraries( enudex_app enudex_market_history enudex_account_history enudex_chain fc enudex_db enudex_net enudex_utilities enudex_debug_witness )
target_include_directories( enudex_app
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
                            "${CMAKE_CURRENT_SOURCE_DIR}/../egenesis/include" )

if(MSVC)
  set_source_files_properties( application.cpp api.cpp database_api.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

INSTALL( TARGETS
   enudex_app

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
INSTALL( FILES ${HEADERS} DESTINATION "include/enudex/app" )
