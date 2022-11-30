install(
    TARGETS visitor_pattern_exe
    RUNTIME COMPONENT visitor_pattern_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
