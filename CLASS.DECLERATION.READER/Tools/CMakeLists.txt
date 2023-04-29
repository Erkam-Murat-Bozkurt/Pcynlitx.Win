



add_library(tools 

    ${CMAKE_CURRENT_SOURCE_DIR}/CharOperator/CharOperator.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/CharOperator/CharOperator.h


    ${CMAKE_CURRENT_SOURCE_DIR}/Compiler/Compiler.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Compiler/Compiler.h    


    ${CMAKE_CURRENT_SOURCE_DIR}/Compiler_Descriptor_File_Reader/Compiler_Descriptor_File_Reader.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Compiler_Descriptor_File_Reader/Compiler_Descriptor_File_Reader.h    


    ${CMAKE_CURRENT_SOURCE_DIR}/Cpp_FileOperations/Cpp_FileOperations.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Cpp_FileOperations/Cpp_FileOperations.h  
    
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Custom_System_Interface/Custom_System_Interface.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Custom_System_Interface/Custom_System_Interface.h  
    
    
    ${CMAKE_CURRENT_SOURCE_DIR}/DirectoryOperations/DirectoryOperations.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/DirectoryOperations/DirectoryOperations.h  



    ${CMAKE_CURRENT_SOURCE_DIR}/HeaderFileBuilder/HeaderFileBuilder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/HeaderFileBuilder/HeaderFileBuilder.h  



    ${CMAKE_CURRENT_SOURCE_DIR}/IntToCharTranslater/IntToCharTranslater.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/IntToCharTranslater/IntToCharTranslater.h  


    ${CMAKE_CURRENT_SOURCE_DIR}/StringOperator/StringOperator.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/StringOperator/StringOperator.h  
)



target_include_directories(tools PUBLIC 

    ${CMAKE_CURRENT_SOURCE_DIR}/CharOperator

    ${CMAKE_CURRENT_SOURCE_DIR}/Compiler

    ${CMAKE_CURRENT_SOURCE_DIR}/Compiler_Descriptor_File_Reader

    ${CMAKE_CURRENT_SOURCE_DIR}/Cpp_FileOperations

    ${CMAKE_CURRENT_SOURCE_DIR}/Custom_System_Interface

    ${CMAKE_CURRENT_SOURCE_DIR}/DirectoryOperations

    ${CMAKE_CURRENT_SOURCE_DIR}/HeaderFileBuilder

    ${CMAKE_CURRENT_SOURCE_DIR}/IntToCharTranslater

    ${CMAKE_CURRENT_SOURCE_DIR}/StringOperator

    ${CMAKE_CURRENT_SOURCE_DIR}/Document_Builder
)