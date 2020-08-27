
#include "Modification_Control_Script_Builder.h"

int main(int argc, char ** argv) {

    Modification_Control_Script_Builder Builder;

    Builder.Build_Script(argv[1],argv[2]);

    return 0;
}
