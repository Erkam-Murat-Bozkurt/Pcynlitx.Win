

add_library(des_reader 

    ${CMAKE_CURRENT_SOURCE_DIR}/Descriptor_File_Data_Collector/Descriptor_File_Data_Collector.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Descriptor_File_Data_Collector/Descriptor_File_Data_Collector.h


    ${CMAKE_CURRENT_SOURCE_DIR}/Descriptor_File_Number_Processor/Descriptor_File_Number_Processor.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Descriptor_File_Number_Processor/Descriptor_File_Number_Processor.h    


    ${CMAKE_CURRENT_SOURCE_DIR}/Descriptor_File_Reader/Descriptor_File_Reader.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Descriptor_File_Reader/Descriptor_File_Reader.h    


    ${CMAKE_CURRENT_SOURCE_DIR}/Descriptor_File_Reader_Initializer/Descriptor_File_Reader_Initializer.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Descriptor_File_Reader_Initializer/Descriptor_File_Reader_Initializer.h  
    
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Descriptor_File_Reader_Syntax_Controller/Descriptor_File_Reader_Syntax_Controller.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Descriptor_File_Reader_Syntax_Controller/Descriptor_File_Reader_Syntax_Controller.h  
    
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Header_File_Descriptions_Reader/Header_File_Descriptions_Reader.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Header_File_Descriptions_Reader/Header_File_Descriptions_Reader.h  



    ${CMAKE_CURRENT_SOURCE_DIR}/Include_Directory_Description_Reader/Include_Directory_Description_Reader.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Include_Directory_Description_Reader/Include_Directory_Description_Reader.h  



    ${CMAKE_CURRENT_SOURCE_DIR}/Inter_Thread_Class_Description_Reader/Inter_Thread_Class_Description_Reader.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Inter_Thread_Class_Description_Reader/Inter_Thread_Class_Description_Reader.h  


    ${CMAKE_CURRENT_SOURCE_DIR}/Inter_Thread_Data_Type_Description_Reader/Inter_Thread_Data_Type_Description_Reader.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Inter_Thread_Data_Type_Description_Reader/Inter_Thread_Data_Type_Description_Reader.h  


    ${CMAKE_CURRENT_SOURCE_DIR}/Library_Descriptions_Reader/Library_Descriptions_Reader.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Library_Descriptions_Reader/Library_Descriptions_Reader.h  


    ${CMAKE_CURRENT_SOURCE_DIR}/Main_File_Descriptions_Reader/Main_File_Descriptions_Reader.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Main_File_Descriptions_Reader/Main_File_Descriptions_Reader.h  


    ${CMAKE_CURRENT_SOURCE_DIR}/Source_File_Descriptions_Reader/Source_File_Descriptions_Reader.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Source_File_Descriptions_Reader/Source_File_Descriptions_Reader.h  

)

target_link_libraries(des_reader PUBLIC class_reader proc_init tools)


target_link_directories(des_reader PUBLIC 

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





    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/DataBaseBuilder

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/MethodInterpreter

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/MethodListInterpreter

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/MethodListReader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/MethodReceiver

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/NameReader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/ParameterReader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/ParenthesReader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/ReturnTypeReader


)

target_include_directories(des_reader PUBLIC 

    ${CMAKE_CURRENT_SOURCE_DIR}/Descriptor_File_Data_Collector    

    ${CMAKE_CURRENT_SOURCE_DIR}/Descriptor_File_Number_Processor
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Descriptor_File_Reader    

    ${CMAKE_CURRENT_SOURCE_DIR}/Descriptor_File_Reader_Initializer
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Descriptor_File_Reader_Syntax_Controller
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Header_File_Descriptions_Reader
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Include_Directory_Description_Reader
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Inter_Thread_Class_Description_Reader
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Inter_Thread_Data_Type_Description_Reader
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Library_Descriptions_Reader
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Main_File_Descriptions_Reader

    ${CMAKE_CURRENT_SOURCE_DIR}/Source_File_Descriptions_Reader    



    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Cpp_FileOperations

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/CharOperator

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Compiler

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Compiler_Descriptor_File_Reader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Custom_System_Interface

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/DirectoryOperations

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/HeaderFileBuilder

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/IntToCharTranslater

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/StringOperator



    
    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/DataBaseManagement/MemberFunctionReader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/DataBaseManagement/MetaDataTranslater


    
    ${CMAKE_SOURCE_DIR}/CLIENT.CLASS.BUILDER/ClassRebuilder

    ${CMAKE_SOURCE_DIR}/CLIENT.CLASS.BUILDER/ClassRebuilder_Data_Collector
   
    ${CMAKE_SOURCE_DIR}/CLIENT.CLASS.BUILDER/ClassRebuilder_Initializer
   
    ${CMAKE_SOURCE_DIR}/CLIENT.CLASS.BUILDER/HeaderRebuilder


    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/ClassNameReader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/ClassSyntaxControl
    
    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/FindSetPoints 

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/ListFileOrganizer
    
    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/MethodInitializer
    
    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/MethodProcessor    

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/MethodReader    

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/SyntaxController





    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/DataBaseBuilder

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/MethodInterpreter

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/MethodListInterpreter

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/MethodListReader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/MethodReceiver

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/NameReader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/ParameterReader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/ParenthesReader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/ReturnTypeReader
)