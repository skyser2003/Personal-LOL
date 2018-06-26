#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gRPC::gpr" for configuration "Release"
set_property(TARGET gRPC::gpr APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::gpr PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/gpr.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::gpr )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::gpr "${_IMPORT_PREFIX}/lib/gpr.lib" )

# Import target "gRPC::grpc" for configuration "Release"
set_property(TARGET gRPC::grpc APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::grpc PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "wsock32;ws2_32;OpenSSL::SSL;OpenSSL::Crypto;ZLIB::ZLIB;c-ares::cares;gRPC::gpr"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/grpc.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::grpc )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::grpc "${_IMPORT_PREFIX}/lib/grpc.lib" )

# Import target "gRPC::grpc_cronet" for configuration "Release"
set_property(TARGET gRPC::grpc_cronet APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::grpc_cronet PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "wsock32;ws2_32;OpenSSL::SSL;OpenSSL::Crypto;ZLIB::ZLIB;c-ares::cares;gRPC::gpr"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/grpc_cronet.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::grpc_cronet )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::grpc_cronet "${_IMPORT_PREFIX}/lib/grpc_cronet.lib" )

# Import target "gRPC::grpc_unsecure" for configuration "Release"
set_property(TARGET gRPC::grpc_unsecure APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::grpc_unsecure PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "wsock32;ws2_32;ZLIB::ZLIB;c-ares::cares;gRPC::gpr"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/grpc_unsecure.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::grpc_unsecure )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::grpc_unsecure "${_IMPORT_PREFIX}/lib/grpc_unsecure.lib" )

# Import target "gRPC::grpc++" for configuration "Release"
set_property(TARGET gRPC::grpc++ APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::grpc++ PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "wsock32;ws2_32;OpenSSL::SSL;OpenSSL::Crypto;protobuf::libprotobuf;gRPC::grpc;gRPC::gpr"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/grpc++.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::grpc++ )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::grpc++ "${_IMPORT_PREFIX}/lib/grpc++.lib" )

# Import target "gRPC::grpc++_cronet" for configuration "Release"
set_property(TARGET gRPC::grpc++_cronet APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::grpc++_cronet PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "wsock32;ws2_32;OpenSSL::SSL;OpenSSL::Crypto;protobuf::libprotobuf;gRPC::gpr;gRPC::grpc_cronet;gRPC::grpc"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/grpc++_cronet.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::grpc++_cronet )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::grpc++_cronet "${_IMPORT_PREFIX}/lib/grpc++_cronet.lib" )

# Import target "gRPC::grpc++_error_details" for configuration "Release"
set_property(TARGET gRPC::grpc++_error_details APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::grpc++_error_details PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "wsock32;ws2_32;protobuf::libprotobuf;gRPC::grpc++"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/grpc++_error_details.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::grpc++_error_details )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::grpc++_error_details "${_IMPORT_PREFIX}/lib/grpc++_error_details.lib" )

# Import target "gRPC::grpc++_reflection" for configuration "Release"
set_property(TARGET gRPC::grpc++_reflection APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::grpc++_reflection PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "protobuf::libprotobuf;gRPC::grpc++;gRPC::grpc"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/grpc++_reflection.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::grpc++_reflection )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::grpc++_reflection "${_IMPORT_PREFIX}/lib/grpc++_reflection.lib" )

# Import target "gRPC::grpc++_unsecure" for configuration "Release"
set_property(TARGET gRPC::grpc++_unsecure APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::grpc++_unsecure PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "wsock32;ws2_32;protobuf::libprotobuf;gRPC::gpr;gRPC::grpc_unsecure"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/grpc++_unsecure.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::grpc++_unsecure )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::grpc++_unsecure "${_IMPORT_PREFIX}/lib/grpc++_unsecure.lib" )

# Import target "gRPC::grpc_plugin_support" for configuration "Release"
set_property(TARGET gRPC::grpc_plugin_support APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::grpc_plugin_support PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "protobuf::libprotoc;protobuf::libprotobuf"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/grpc_plugin_support.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::grpc_plugin_support )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::grpc_plugin_support "${_IMPORT_PREFIX}/lib/grpc_plugin_support.lib" )

# Import target "gRPC::check_epollexclusive" for configuration "Release"
set_property(TARGET gRPC::check_epollexclusive APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::check_epollexclusive PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/grpc/check_epollexclusive.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::check_epollexclusive )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::check_epollexclusive "${_IMPORT_PREFIX}/tools/grpc/check_epollexclusive.exe" )

# Import target "gRPC::grpc_create_jwt" for configuration "Release"
set_property(TARGET gRPC::grpc_create_jwt APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::grpc_create_jwt PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/grpc/grpc_create_jwt.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::grpc_create_jwt )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::grpc_create_jwt "${_IMPORT_PREFIX}/tools/grpc/grpc_create_jwt.exe" )

# Import target "gRPC::grpc_print_google_default_creds_token" for configuration "Release"
set_property(TARGET gRPC::grpc_print_google_default_creds_token APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::grpc_print_google_default_creds_token PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/grpc/grpc_print_google_default_creds_token.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::grpc_print_google_default_creds_token )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::grpc_print_google_default_creds_token "${_IMPORT_PREFIX}/tools/grpc/grpc_print_google_default_creds_token.exe" )

# Import target "gRPC::grpc_verify_jwt" for configuration "Release"
set_property(TARGET gRPC::grpc_verify_jwt APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::grpc_verify_jwt PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/grpc/grpc_verify_jwt.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::grpc_verify_jwt )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::grpc_verify_jwt "${_IMPORT_PREFIX}/tools/grpc/grpc_verify_jwt.exe" )

# Import target "gRPC::grpc_cpp_plugin" for configuration "Release"
set_property(TARGET gRPC::grpc_cpp_plugin APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::grpc_cpp_plugin PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/grpc/grpc_cpp_plugin.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::grpc_cpp_plugin )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::grpc_cpp_plugin "${_IMPORT_PREFIX}/tools/grpc/grpc_cpp_plugin.exe" )

# Import target "gRPC::grpc_csharp_plugin" for configuration "Release"
set_property(TARGET gRPC::grpc_csharp_plugin APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::grpc_csharp_plugin PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/grpc/grpc_csharp_plugin.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::grpc_csharp_plugin )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::grpc_csharp_plugin "${_IMPORT_PREFIX}/tools/grpc/grpc_csharp_plugin.exe" )

# Import target "gRPC::grpc_node_plugin" for configuration "Release"
set_property(TARGET gRPC::grpc_node_plugin APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::grpc_node_plugin PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/grpc/grpc_node_plugin.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::grpc_node_plugin )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::grpc_node_plugin "${_IMPORT_PREFIX}/tools/grpc/grpc_node_plugin.exe" )

# Import target "gRPC::grpc_objective_c_plugin" for configuration "Release"
set_property(TARGET gRPC::grpc_objective_c_plugin APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::grpc_objective_c_plugin PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/grpc/grpc_objective_c_plugin.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::grpc_objective_c_plugin )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::grpc_objective_c_plugin "${_IMPORT_PREFIX}/tools/grpc/grpc_objective_c_plugin.exe" )

# Import target "gRPC::grpc_php_plugin" for configuration "Release"
set_property(TARGET gRPC::grpc_php_plugin APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::grpc_php_plugin PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/grpc/grpc_php_plugin.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::grpc_php_plugin )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::grpc_php_plugin "${_IMPORT_PREFIX}/tools/grpc/grpc_php_plugin.exe" )

# Import target "gRPC::grpc_python_plugin" for configuration "Release"
set_property(TARGET gRPC::grpc_python_plugin APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::grpc_python_plugin PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/grpc/grpc_python_plugin.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::grpc_python_plugin )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::grpc_python_plugin "${_IMPORT_PREFIX}/tools/grpc/grpc_python_plugin.exe" )

# Import target "gRPC::grpc_ruby_plugin" for configuration "Release"
set_property(TARGET gRPC::grpc_ruby_plugin APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::grpc_ruby_plugin PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/grpc/grpc_ruby_plugin.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::grpc_ruby_plugin )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::grpc_ruby_plugin "${_IMPORT_PREFIX}/tools/grpc/grpc_ruby_plugin.exe" )

# Import target "gRPC::gen_hpack_tables" for configuration "Release"
set_property(TARGET gRPC::gen_hpack_tables APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::gen_hpack_tables PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/grpc/gen_hpack_tables.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::gen_hpack_tables )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::gen_hpack_tables "${_IMPORT_PREFIX}/tools/grpc/gen_hpack_tables.exe" )

# Import target "gRPC::gen_legal_metadata_characters" for configuration "Release"
set_property(TARGET gRPC::gen_legal_metadata_characters APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::gen_legal_metadata_characters PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/grpc/gen_legal_metadata_characters.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::gen_legal_metadata_characters )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::gen_legal_metadata_characters "${_IMPORT_PREFIX}/tools/grpc/gen_legal_metadata_characters.exe" )

# Import target "gRPC::gen_percent_encoding_tables" for configuration "Release"
set_property(TARGET gRPC::gen_percent_encoding_tables APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gRPC::gen_percent_encoding_tables PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/grpc/gen_percent_encoding_tables.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS gRPC::gen_percent_encoding_tables )
list(APPEND _IMPORT_CHECK_FILES_FOR_gRPC::gen_percent_encoding_tables "${_IMPORT_PREFIX}/tools/grpc/gen_percent_encoding_tables.exe" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
