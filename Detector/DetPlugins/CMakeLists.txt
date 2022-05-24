#################################################################################
##Package : DetPlugins
#################################################################################

file(GLOB sources src/*.cpp)
add_dd4hep_plugin(DetPlugins SHARED ${sources})
target_link_libraries(DetPlugins DD4hep::DDCore DD4hep::DDRec)
target_include_directories(DetPlugins
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

install(TARGETS DetPlugins
  EXPORT ${PROJECT_NAME}Targets
  RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}" COMPONENT bin
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}" COMPONENT shlib
  PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/DetSegmentation"
  COMPONENT dev)
