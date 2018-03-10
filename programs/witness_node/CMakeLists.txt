add_executable( witness_node main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling witness_node with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

# We have to link against enudex_debug_witness because deficiency in our API infrastructure doesn't allow plugins to be fully abstracted #246
target_link_libraries( witness_node

PRIVATE enudex_app enudex_delayed_node enudex_account_history enudex_elasticsearch enudex_market_history enudex_witness enudex_chain enudex_debug_witness enudex_egenesis_full enudex_snapshot fc ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )


install( TARGETS
   witness_node

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
