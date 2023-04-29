


add_library(proc_init 

    ${CMAKE_CURRENT_SOURCE_DIR}/ClassNameReader/ClassNameReader.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/ClassNameReader/ClassNameReader.h


    ${CMAKE_CURRENT_SOURCE_DIR}/ClassSyntaxControl/ClassSyntaxControl.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/ClassSyntaxControl/ClassSyntaxControl.h    


    ${CMAKE_CURRENT_SOURCE_DIR}/FindSetPoints/FindSetPoints.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/FindSetPoints/FindSetPoints.h    


    ${CMAKE_CURRENT_SOURCE_DIR}/ListFileOrganizer/ListFileOrganizer.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/ListFileOrganizer/ListFileOrganizer.h  
    
    
    ${CMAKE_CURRENT_SOURCE_DIR}/MethodInitializer/MethodInitializer.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/MethodInitializer/MethodInitializer.h  
    
    
    ${CMAKE_CURRENT_SOURCE_DIR}/MethodProcessor/MethodProcessor.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/MethodProcessor/MethodProcessor.h  



    ${CMAKE_CURRENT_SOURCE_DIR}/SyntaxController/SyntaxController.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/SyntaxController/SyntaxController.h 
    

    ${CMAKE_CURRENT_SOURCE_DIR}/MethodReader/MethodReader.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/MethodReader/MethodReader.h 
)

target_link_libraries(proc_init PUBLIC tools)

target_link_directories(proc_init PUBLIC 

    ${CMAKE_CURRENT_SOURCE_DIR}/ClassNameReader

    ${CMAKE_CURRENT_SOURCE_DIR}/ClassSyntaxControl

    ${CMAKE_CURRENT_SOURCE_DIR}/FindSetPoints 

    ${CMAKE_CURRENT_SOURCE_DIR}/ListFileOrganizer

    ${CMAKE_CURRENT_SOURCE_DIR}/MethodInitializer

    ${CMAKE_CURRENT_SOURCE_DIR}/MethodProcessor    

    ${CMAKE_CURRENT_SOURCE_DIR}/MethodReader    

    ${CMAKE_CURRENT_SOURCE_DIR}/SyntaxController
    

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Cpp_FileOperations

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/CharOperator

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Compiler

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Compiler_Descriptor_File_Reader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Custom_System_Interface

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/DirectoryOperations

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/HeaderFileBuilder

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/IntToCharTranslater

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/StringOperator
)


target_include_directories(proc_init PUBLIC 


    ${CMAKE_CURRENT_SOURCE_DIR}/ClassNameReader

    ${CMAKE_CURRENT_SOURCE_DIR}/ClassSyntaxControl
    
    ${CMAKE_CURRENT_SOURCE_DIR}/FindSetPoints 

    ${CMAKE_CURRENT_SOURCE_DIR}/ListFileOrganizer
    
    ${CMAKE_CURRENT_SOURCE_DIR}/MethodInitializer
    
    ${CMAKE_CURRENT_SOURCE_DIR}/MethodProcessor    

    ${CMAKE_CURRENT_SOURCE_DIR}/MethodReader    

    ${CMAKE_CURRENT_SOURCE_DIR}/SyntaxController


    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Cpp_FileOperations

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/CharOperator

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Compiler

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Compiler_Descriptor_File_Reader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Custom_System_Interface

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/DirectoryOperations

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/HeaderFileBuilder

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/IntToCharTranslater

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/StringOperator


)