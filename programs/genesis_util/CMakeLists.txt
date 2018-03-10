
add_executable( genesis_update genesis_update.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

target_link_libraries( genesis_update
                       PRIVATE enudex_app enudex_chain enudex_egenesis_none fc ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )

install( TARGETS
   genesis_update

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)

add_executable( get_dev_key get_dev_key.cpp )

target_link_libraries( get_dev_key
                       PRIVATE enudex_app enudex_chain enudex_egenesis_none enudex_utilities fc ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )

install( TARGETS
   get_dev_key

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)

add_executable( convert_address convert_address.cpp )

target_link_libraries( convert_address
                       PRIVATE enudex_chain fc ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )
