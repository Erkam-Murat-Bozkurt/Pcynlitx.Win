
#ifndef DATA_READER_TYPES_H
#define DATA_READER_TYPES_H

struct Read_Data {

    char  * number_string;

    bool read_status;

    bool record_status;

    int  position;
};

struct readers_acess_order_data
{
    int  * acess_data_holder;

    bool * empty_status;
};


#endif /* DATA_READER_TYPES_H */
