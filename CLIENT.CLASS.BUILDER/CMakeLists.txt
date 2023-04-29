

add_library(ClassRebuilder 

    ${CMAKE_CURRENT_SOURCE_DIR}/ClassRebuilder/ClassRebuilder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/ClassRebuilder/ClassRebuilder.h

    ${CMAKE_CURRENT_SOURCE_DIR}/ClassRebuilder_Data_Collector/ClassRebuilder_Data_Collector.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/ClassRebuilder_Data_Collector/ClassRebuilder_Data_Collector.h    

    ${CMAKE_CURRENT_SOURCE_DIR}/ClassRebuilder_Initializer/ClassRebuilder_Initializer.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/ClassRebuilder_Initializer/ClassRebuilder_Initializer.h    

    ${CMAKE_CURRENT_SOURCE_DIR}/HeaderRebuilder/HeaderRebuilder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/HeaderRebuilder/HeaderRebuilder.h    
)

target_link_libraries(ClassRebuilder DataBsMng class_reader proc_init)



target_link_directories(ClassRebuilder PUBLIC 

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



    ${CMAKE_SOURCE_DIR}/CLIENT.CLASS.BUILDER/ClassRebuilder

    ${CMAKE_SOURCE_DIR}/CLIENT.CLASS.BUILDER/ClassRebuilder_Data_Collector

    ${CMAKE_SOURCE_DIR}/CLIENT.CLASS.BUILDER/ClassRebuilder_Initializer

    ${CMAKE_SOURCE_DIR}/CLIENT.CLASS.BUILDER/HeaderRebuilder



    ${CMAKE_SOURCE_DIR}/PROJECT.MANAGEMENT.TOOLS/Auto_Class_Compiler

    ${CMAKE_SOURCE_DIR}/PROJECT.MANAGEMENT.TOOLS/Convert_Repo_To_Single_File

    ${CMAKE_SOURCE_DIR}/PROJECT.MANAGEMENT.TOOLS/Included_Header_File_Names_Reader

    ${CMAKE_SOURCE_DIR}/PROJECT.MANAGEMENT.TOOLS/Library_Updater

    ${CMAKE_SOURCE_DIR}/PROJECT.MANAGEMENT.TOOLS/Make_File_Builder

    ${CMAKE_SOURCE_DIR}/PROJECT.MANAGEMENT.TOOLS/Test_Program_Builder



    ${CMAKE_SOURCE_DIR}/SERVER.CLASS.BUILDER/Inter_Thread_Data_Structure_Builder

    ${CMAKE_SOURCE_DIR}/SERVER.CLASS.BUILDER/Main_File_Builder

    ${CMAKE_SOURCE_DIR}/SERVER.CLASS.BUILDER/Server_Builder

    ${CMAKE_SOURCE_DIR}/SERVER.CLASS.BUILDER/Server_Header_File_Builder

    ${CMAKE_SOURCE_DIR}/SERVER.CLASS.BUILDER/Thread_Data_Manager_Builder

    ${CMAKE_SOURCE_DIR}/SERVER.CLASS.BUILDER/Thread_Data_Manager_Header_Builder

    ${CMAKE_SOURCE_DIR}/SERVER.CLASS.BUILDER/Thread_Locker_Builder

    ${CMAKE_SOURCE_DIR}/SERVER.CLASS.BUILDER/Thread_Locker_Header_File_Builder

    ${CMAKE_SOURCE_DIR}/SERVER.CLASS.BUILDER/Thread_Manager_Builder

    ${CMAKE_SOURCE_DIR}/SERVER.CLASS.BUILDER/Thread_Manager_Header_File_Builder

    ${CMAKE_SOURCE_DIR}/SERVER.CLASS.BUILDER/TM_Client_Builder

    ${CMAKE_SOURCE_DIR}/SERVER.CLASS.BUILDER/TM_Client_Header_Builder


    ${CMAKE_SOURCE_DIR}/SMART.POINTER.BUILDER/Builder_Initializer

    ${CMAKE_SOURCE_DIR}/SMART.POINTER.BUILDER/Dynamic_Memory_Manager_Builder

    ${CMAKE_SOURCE_DIR}/SMART.POINTER.BUILDER/Dynamic_Memory_Manager_Header_Builder

    ${CMAKE_SOURCE_DIR}/SMART.POINTER.BUILDER/Dynamic_Memory_Manager_Header_Builder

    ${CMAKE_SOURCE_DIR}/SMART.POINTER.BUILDER/Multi_Thread_Pointer_Builder

    ${CMAKE_SOURCE_DIR}/SMART.POINTER.BUILDER/Multi_Thread_Pointer_Client_Builder

    ${CMAKE_SOURCE_DIR}/SMART.POINTER.BUILDER/Multi_Thread_Pointer_Client_Header_Builder

    ${CMAKE_SOURCE_DIR}/SMART.POINTER.BUILDER/Multi_Thread_Pointer_Compile_Data_Collector

    ${CMAKE_SOURCE_DIR}/SMART.POINTER.BUILDER/Multi_Thread_Pointer_Compile_Data_Collector

    ${CMAKE_SOURCE_DIR}/SMART.POINTER.BUILDER/Multi_Thread_Pointer_Data_Collector

    ${CMAKE_SOURCE_DIR}/SMART.POINTER.BUILDER/Multi_Thread_Pointer_File_Cleaner

    ${CMAKE_SOURCE_DIR}/SMART.POINTER.BUILDER/Multi_Thread_Pointer_File_Cleaner

    ${CMAKE_SOURCE_DIR}/SMART.POINTER.BUILDER/Multi_Thread_Pointer_File_Data_Collector

    ${CMAKE_SOURCE_DIR}/SMART.POINTER.BUILDER/Multi_Thread_Pointer_Header_Builder

    ${CMAKE_SOURCE_DIR}/SMART.POINTER.BUILDER/ReportFileBuilder_Writer
  
    ${CMAKE_SOURCE_DIR}/SMART.POINTER.BUILDER/ReportFileBuilder_HeaderWriter

    ${CMAKE_SOURCE_DIR}/SMART.POINTER.BUILDER/Smart_Pointer_Data_Conveyor
)

target_include_directories(ClassRebuilder PUBLIC 

    ${CMAKE_CURRENT_SOURCE_DIR}/ClassRebuilder

    ${CMAKE_CURRENT_SOURCE_DIR}/ClassRebuilder_Data_Collector
   
    ${CMAKE_CURRENT_SOURCE_DIR}/ClassRebuilder_Initializer
   
    ${CMAKE_CURRENT_SOURCE_DIR}/HeaderRebuilder

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



    ${CMAKE_SOURCE_DIR}/PROJECT.MANAGEMENT.TOOLS/Auto_Class_Compiler

    ${CMAKE_SOURCE_DIR}/PROJECT.MANAGEMENT.TOOLS/Convert_Repo_To_Single_File

    ${CMAKE_SOURCE_DIR}/PROJECT.MANAGEMENT.TOOLS/Included_Header_File_Names_Reader

    ${CMAKE_SOURCE_DIR}/PROJECT.MANAGEMENT.TOOLS/Library_Updater

    ${CMAKE_SOURCE_DIR}/PROJECT.MANAGEMENT.TOOLS/Make_File_Builder

    ${CMAKE_SOURCE_DIR}/PROJECT.MANAGEMENT.TOOLS/Test_Program_Builder

)