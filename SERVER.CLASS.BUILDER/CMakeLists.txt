




add_library(server_builder 

    ${CMAKE_CURRENT_SOURCE_DIR}/Inter_Thread_Data_Structure_Builder/Inter_Thread_Data_Structure_Builder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Inter_Thread_Data_Structure_Builder/Inter_Thread_Data_Structure_Builder.h


    ${CMAKE_CURRENT_SOURCE_DIR}/Main_File_Builder/Main_File_Builder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Main_File_Builder/Main_File_Builder.h    


    ${CMAKE_CURRENT_SOURCE_DIR}/Server_Builder/Server_Builder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Server_Builder/Server_Builder.h    


    ${CMAKE_CURRENT_SOURCE_DIR}/Server_Header_File_Builder/Server_Header_File_Builder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Server_Header_File_Builder/Server_Header_File_Builder.h  
    
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Thread_Data_Manager_Builder/Thread_Data_Manager_Builder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Thread_Data_Manager_Builder/Thread_Data_Manager_Builder.h  
    
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Thread_Data_Manager_Header_Builder/Thread_Data_Manager_Header_Builder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Thread_Data_Manager_Header_Builder/Thread_Data_Manager_Header_Builder.h  



    ${CMAKE_CURRENT_SOURCE_DIR}/Thread_Locker_Builder/Thread_Locker_Builder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Thread_Locker_Builder/Thread_Locker_Builder.h  



    ${CMAKE_CURRENT_SOURCE_DIR}/Thread_Locker_Header_File_Builder/Thread_Locker_Header_File_Builder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Thread_Locker_Header_File_Builder/Thread_Locker_Header_File_Builder.h  


    ${CMAKE_CURRENT_SOURCE_DIR}/Thread_Manager_Builder/Thread_Manager_Builder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Thread_Manager_Builder/Thread_Manager_Builder.h  


    ${CMAKE_CURRENT_SOURCE_DIR}/Thread_Manager_Header_File_Builder/Thread_Manager_Header_File_Builder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Thread_Manager_Header_File_Builder/Thread_Manager_Header_File_Builder.h  


    ${CMAKE_CURRENT_SOURCE_DIR}/TM_Client_Builder/TM_Client_Builder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/TM_Client_Builder/TM_Client_Builder.h  


    ${CMAKE_CURRENT_SOURCE_DIR}/TM_Client_Header_Builder/TM_Client_Header_Builder.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/TM_Client_Header_Builder/TM_Client_Header_Builder.h  

)



target_include_directories(server_builder PUBLIC 

    ${CMAKE_CURRENT_SOURCE_DIR}/Inter_Thread_Data_Structure_Builder

    ${CMAKE_CURRENT_SOURCE_DIR}/Main_File_Builder

    ${CMAKE_CURRENT_SOURCE_DIR}/Server_Builder

    ${CMAKE_CURRENT_SOURCE_DIR}/Server_Header_File_Builder

    ${CMAKE_CURRENT_SOURCE_DIR}/Thread_Data_Manager_Builder

    ${CMAKE_CURRENT_SOURCE_DIR}/Thread_Data_Manager_Header_Builder

    ${CMAKE_CURRENT_SOURCE_DIR}/Thread_Locker_Builder

    ${CMAKE_CURRENT_SOURCE_DIR}/Thread_Locker_Header_File_Builder

    ${CMAKE_CURRENT_SOURCE_DIR}/Thread_Manager_Builder

    ${CMAKE_CURRENT_SOURCE_DIR}/Thread_Manager_Header_File_Builder

    ${CMAKE_CURRENT_SOURCE_DIR}/TM_Client_Builder

    ${CMAKE_CURRENT_SOURCE_DIR}/TM_Client_Header_Builder


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




    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/DataBaseBuilder

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/MethodInterpreter

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/MethodListInterpreter

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/MethodListReader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/MethodReceiver

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/NameReader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/ParameterReader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/ParenthesReader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ClassReader/ReturnTypeReader



    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/ClassNameReader

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/ClassSyntaxControl
    
    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/FindSetPoints 

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/ListFileOrganizer
    
    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/MethodInitializer
    
    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/MethodProcessor    

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/MethodReader    

    ${CMAKE_SOURCE_DIR}/CLASS.DECLERATION.READER/ProcessInitialization/SyntaxController

)