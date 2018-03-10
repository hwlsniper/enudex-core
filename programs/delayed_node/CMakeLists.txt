add_executable( delayed_node main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling delayed_node with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

target_link_libraries( delayed_node
                       PRIVATE enudex_app enudex_account_history enudex_market_history enudex_delayed_node enudex_chain enudex_egenesis_full fc ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )

install( TARGETS
   delayed_node

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
