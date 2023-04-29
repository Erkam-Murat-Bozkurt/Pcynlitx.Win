


add_library(des_writer 

    ${CMAKE_CURRENT_SOURCE_DIR}/DataRecord_Tools/DataRecord_Tools.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/DataRecord_Tools/DataRecord_Tools.h


    ${CMAKE_CURRENT_SOURCE_DIR}/DataRecorder/DataRecorder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/DataRecorder/DataRecorder.h    


    ${CMAKE_CURRENT_SOURCE_DIR}/Description_Printer/Description_Printer.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Description_Printer/Description_Printer.h    


    ${CMAKE_CURRENT_SOURCE_DIR}/Empty_Process_Descriptor_File_Builder/Empty_Process_Descriptor_File_Builder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Empty_Process_Descriptor_File_Builder/Empty_Process_Descriptor_File_Builder.h  
    
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Process_Descriptions_Recorder/Process_Descriptions_Recorder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Process_Descriptions_Recorder/Process_Descriptions_Recorder.h      
)



target_include_directories(des_writer PUBLIC 


    ${CMAKE_CURRENT_SOURCE_DIR}/DataRecord_Tools
    
    ${CMAKE_CURRENT_SOURCE_DIR}/DataRecorder
    

    ${CMAKE_CURRENT_SOURCE_DIR}/Description_Printer

    ${CMAKE_CURRENT_SOURCE_DIR}/Empty_Process_Descriptor_File_Builder


    ${CMAKE_CURRENT_SOURCE_DIR}/Process_Descriptions_Recorder


    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Cpp_FileOperations

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/CharOperator

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Compiler

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Compiler_Descriptor_File_Reader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/Custom_System_Interface

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/DirectoryOperations

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/HeaderFileBuilder

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/IntToCharTranslater

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/Tools/StringOperator




    
    ${CMAKE_SOURCE_DIR}/DESCRIPTOR.FILE.READER/Descriptor_File_Data_Collector    

    ${CMAKE_SOURCE_DIR}/DESCRIPTOR.FILE.READER/Descriptor_File_Number_Processor
    
    ${CMAKE_SOURCE_DIR}/DESCRIPTOR.FILE.READER/Descriptor_File_Reader    

    ${CMAKE_SOURCE_DIR}/DESCRIPTOR.FILE.READER/Descriptor_File_Reader_Initializer
    
    ${CMAKE_SOURCE_DIR}/DESCRIPTOR.FILE.READER/Descriptor_File_Reader_Syntax_Controller
    
    ${CMAKE_SOURCE_DIR}/DESCRIPTOR.FILE.READER/Header_File_Descriptions_Reader
    
    ${CMAKE_SOURCE_DIR}/DESCRIPTOR.FILE.READER/Include_Directory_Description_Reader
    
    ${CMAKE_SOURCE_DIR}/DESCRIPTOR.FILE.READER/Inter_Thread_Class_Description_Reader
    
    ${CMAKE_SOURCE_DIR}/DESCRIPTOR.FILE.READER/Inter_Thread_Data_Type_Description_Reader
    
    ${CMAKE_SOURCE_DIR}/DESCRIPTOR.FILE.READER/Library_Descriptions_Reader
    
    ${CMAKE_SOURCE_DIR}/DESCRIPTOR.FILE.READER/Main_File_Descriptions_Reader

    ${CMAKE_SOURCE_DIR}/DESCRIPTOR.FILE.READER/Source_File_Descriptions_Reader    


    
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