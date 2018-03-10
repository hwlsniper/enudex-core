
add_library( enudex_egenesis_none
   egenesis_none.cpp
   include/enudex/egenesis/egenesis.hpp
   )

target_link_libraries( enudex_egenesis_none enudex_chain fc )
target_include_directories( enudex_egenesis_none
   PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

add_executable( embed_genesis
   embed_genesis.cpp
   )

target_link_libraries( embed_genesis enudex_chain enudex_app enudex_egenesis_none fc )

set( embed_genesis_args
   -t "${CMAKE_CURRENT_SOURCE_DIR}/egenesis_brief.cpp.tmpl---${CMAKE_CURRENT_BINARY_DIR}/egenesis_brief.cpp"
   -t "${CMAKE_CURRENT_SOURCE_DIR}/egenesis_full.cpp.tmpl---${CMAKE_CURRENT_BINARY_DIR}/egenesis_full.cpp"
   )

MESSAGE( STATUS "egenesis: " ${ENUDEX_EGENESIS_JSON} )

if( ENUDEX_EGENESIS_JSON )
   list( APPEND embed_genesis_args --genesis-json "${ENUDEX_EGENESIS_JSON}" )
endif( ENUDEX_EGENESIS_JSON )

MESSAGE( STATUS "embed_genesis_args: " ${embed_genesis_args} )

add_custom_command(
   OUTPUT
      "${CMAKE_CURRENT_BINARY_DIR}/egenesis_brief.cpp"
      "${CMAKE_CURRENT_BINARY_DIR}/egenesis_full.cpp"
   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
   COMMAND embed_genesis ${embed_genesis_args}
   DEPENDS
      "${ENUDEX_EGENESIS_JSON}"
      "${CMAKE_CURRENT_SOURCE_DIR}/egenesis_brief.cpp.tmpl"
      "${CMAKE_CURRENT_SOURCE_DIR}/egenesis_full.cpp.tmpl"
      embed_genesis )

add_library( enudex_egenesis_brief "${CMAKE_CURRENT_BINARY_DIR}/egenesis_brief.cpp" include/enudex/egenesis/egenesis.hpp )
add_library( enudex_egenesis_full  "${CMAKE_CURRENT_BINARY_DIR}/egenesis_full.cpp" include/enudex/egenesis/egenesis.hpp )

target_link_libraries( enudex_egenesis_brief enudex_chain fc )
target_link_libraries( enudex_egenesis_full enudex_chain fc )

target_include_directories( enudex_egenesis_brief
   PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
target_include_directories( enudex_egenesis_full
   PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

INSTALL( TARGETS
   embed_genesis enudex_egenesis_none enudex_egenesis_brief enudex_egenesis_full

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
