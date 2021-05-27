cmake_minimum_required(VERSION 3.10)# <-  might need to change version if yours is lower
project(ProjectName)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -pedantic)

add_executable(ProjectName hw3_output.cpp parser.tab.cpp lex.yy.c yystype.cpp symbol_table.cpp parser_utils.cpp )

#add_custom_target(
#        flex
#        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#        COMMAND flex ${CMAKE_CURRENT_SOURCE_DIR}/scanner.lex
#        yystype.h yystype.cpp parser_utils.cpp parser_utils.h symbol_table.cpp symbol_table.h)
#
#add_custom_target(
#        bison
#        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#        COMMAND bison -d ${CMAKE_CURRENT_SOURCE_DIR}/parser.ypp
#)

#add_dependencies(ProjectName flex)
#
#add_dependencies(ProjectName bison)

# compile lex.yy.c as c++
set_source_files_properties(lex.yy.c PROPERTIES LANGUAGE CXX )

