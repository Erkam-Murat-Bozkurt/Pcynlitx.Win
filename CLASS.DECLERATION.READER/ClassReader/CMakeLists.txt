



add_library(class_reader 

    ${CMAKE_CURRENT_SOURCE_DIR}/DataBaseBuilder/DataBaseBuilder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/DataBaseBuilder/DataBaseBuilder.h


    ${CMAKE_CURRENT_SOURCE_DIR}/MethodInterpreter/MethodInterpreter.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/MethodInterpreter/MethodInterpreter.h    


    ${CMAKE_CURRENT_SOURCE_DIR}/MethodListInterpreter/MethodListInterpreter.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/MethodListInterpreter/MethodListInterpreter.h    


    ${CMAKE_CURRENT_SOURCE_DIR}/MethodListReader/MethodListReader.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/MethodListReader/MethodListReader.h  
    
    
    ${CMAKE_CURRENT_SOURCE_DIR}/MethodReceiver/MethodReceiver.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/MethodReceiver/MethodReceiver.h  
    
    
    ${CMAKE_CURRENT_SOURCE_DIR}/NameReader/NameReader.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/NameReader/NameReader.h  



    ${CMAKE_CURRENT_SOURCE_DIR}/ParameterReader/ParameterReader.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/ParameterReader/ParameterReader.h  



    ${CMAKE_CURRENT_SOURCE_DIR}/ParenthesReader/ParenthesReader.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/ParenthesReader/ParenthesReader.h  


    ${CMAKE_CURRENT_SOURCE_DIR}/ReturnTypeReader/ReturnTypeReader.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/ReturnTypeReader/ReturnTypeReader.h
)


target_link_libraries(class_reader PUBLIC proc_init tools)


target_link_directories(class_reader PUBLIC 


    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Cpp_FileOperations

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/CharOperator

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Compiler

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Compiler_Descriptor_File_Reader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Custom_System_Interface

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/DirectoryOperations

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/HeaderFileBuilder

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/IntToCharTranslater

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/StringOperator


    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/ClassNameReader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/ClassSyntaxControl

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/FindSetPoints 

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/ListFileOrganizer

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/MethodInitializer

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/MethodProcessor    

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/MethodReader    

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/SyntaxController

)

target_include_directories(class_reader PUBLIC 

    ${CMAKE_CURRENT_SOURCE_DIR}/DataBaseBuilder

    ${CMAKE_CURRENT_SOURCE_DIR}/MethodInterpreter

    ${CMAKE_CURRENT_SOURCE_DIR}/MethodListInterpreter

    ${CMAKE_CURRENT_SOURCE_DIR}/MethodListReader

    ${CMAKE_CURRENT_SOURCE_DIR}/MethodReceiver

    ${CMAKE_CURRENT_SOURCE_DIR}/NameReader

    ${CMAKE_CURRENT_SOURCE_DIR}/ParameterReader

    ${CMAKE_CURRENT_SOURCE_DIR}/ParenthesReader

    ${CMAKE_CURRENT_SOURCE_DIR}/ReturnTypeReader


    

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Cpp_FileOperations

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/CharOperator

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Compiler

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Compiler_Descriptor_File_Reader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Custom_System_Interface

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/DirectoryOperations

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/HeaderFileBuilder

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/IntToCharTranslater

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/StringOperator


    
    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/ClassNameReader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/ClassSyntaxControl
    
    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/FindSetPoints 

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/ListFileOrganizer
    
    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/MethodInitializer
    
    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/MethodProcessor    

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/MethodReader    

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/SyntaxController
)