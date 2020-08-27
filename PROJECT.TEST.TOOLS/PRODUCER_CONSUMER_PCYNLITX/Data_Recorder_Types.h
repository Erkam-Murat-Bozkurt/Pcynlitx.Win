
#ifndef DATA_RECORDER_TYPES_H
#define DATA_RECORDER_TYPES_H

struct Record_Data {

    std::string string_line;

    bool record_status;

    int  position;
};

struct Writer_Thread_Record_Data {

    int record_number;

    int thread_number;
};

struct writers_acess_order_data
{
    int  * acess_data_holder;

    bool * empty_status;
};


#endif /* DATA_RECORDER_TYPES_H */
