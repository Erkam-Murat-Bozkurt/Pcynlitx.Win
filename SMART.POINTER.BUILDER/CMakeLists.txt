



add_library(smart_ptr 

    ${CMAKE_CURRENT_SOURCE_DIR}/Builder_Initializer/Builder_Initializer.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Builder_Initializer/Builder_Initializer.h


    ${CMAKE_CURRENT_SOURCE_DIR}/Dynamic_Memory_Manager_Builder/Dynamic_Memory_Manager_Builder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Dynamic_Memory_Manager_Builder/Dynamic_Memory_Manager_Builder.h    


    ${CMAKE_CURRENT_SOURCE_DIR}/Dynamic_Memory_Manager_Header_Builder/Dynamic_Memory_Manager_Header_Builder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Dynamic_Memory_Manager_Header_Builder/Dynamic_Memory_Manager_Header_Builder.h    


    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_Builder/Multi_Thread_Pointer_Builder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_Builder/Multi_Thread_Pointer_Builder.h  
    
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_Client_Builder/Multi_Thread_Pointer_Client_Builder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_Client_Builder/Multi_Thread_Pointer_Client_Builder.h  
    
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_Client_Header_Builder/Multi_Thread_Pointer_Client_Header_Builder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_Client_Header_Builder/Multi_Thread_Pointer_Client_Header_Builder.h  



    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_Compile_Data_Collector/Multi_Thread_Pointer_Compile_Data_Collector.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_Compile_Data_Collector/Multi_Thread_Pointer_Compile_Data_Collector.h  



    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_Data_Collector/Multi_Thread_Pointer_Data_Collector.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_Data_Collector/Multi_Thread_Pointer_Data_Collector.h  


    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_File_Cleaner/Multi_Thread_Pointer_File_Cleaner.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_File_Cleaner/Multi_Thread_Pointer_File_Cleaner.h  


    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_File_Data_Collector/Multi_Thread_Pointer_File_Data_Collector.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_File_Data_Collector/Multi_Thread_Pointer_File_Data_Collector.h  


    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_Header_Builder/Multi_Thread_Pointer_Header_Builder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_Header_Builder/Multi_Thread_Pointer_Header_Builder.h  


    ${CMAKE_CURRENT_SOURCE_DIR}/ReportFileBuilder_Writer/ReportFileBuilder_Writer.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/ReportFileBuilder_Writer/ReportFileBuilder_Writer.h  


    ${CMAKE_CURRENT_SOURCE_DIR}/ReportFileBuilder_HeaderWriter/ReportFileBuilder_HeaderWriter.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/ReportFileBuilder_HeaderWriter/ReportFileBuilder_HeaderWriter.h  


    ${CMAKE_CURRENT_SOURCE_DIR}/Smart_Pointer_Data_Conveyor/Smart_Pointer_Data_Conveyor.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Smart_Pointer_Data_Conveyor/Smart_Pointer_Data_Conveyor.h  
)



target_include_directories(smart_ptr PUBLIC 

    ${CMAKE_CURRENT_SOURCE_DIR}/Builder_Initializer
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Dynamic_Memory_Manager_Builder

    ${CMAKE_CURRENT_SOURCE_DIR}/Dynamic_Memory_Manager_Header_Builder

    ${CMAKE_CURRENT_SOURCE_DIR}/Dynamic_Memory_Manager_Header_Builder

    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_Builder
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_Client_Builder

    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_Client_Header_Builder

    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_Compile_Data_Collector

    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_Compile_Data_Collector

    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_Data_Collector

    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_File_Cleaner

    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_File_Cleaner

    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_File_Data_Collector
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Multi_Thread_Pointer_Header_Builder
    
    ${CMAKE_CURRENT_SOURCE_DIR}/ReportFileBuilder_Writer
      
    ${CMAKE_CURRENT_SOURCE_DIR}/ReportFileBuilder_HeaderWriter
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Smart_Pointer_Data_Conveyor



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