
g++ -o parsec_swaptions_std_thread CumNormalInv.cpp MaxFunction.cpp RanUnif.cpp nr_routines.c icdf.cpp \
	HJM_SimPath_Forward_Blocking.cpp HJM.cpp HJM_Swaption_Blocking.cpp \
	parsec_swaptions_std_thread.cpp -include parsec_swaptions_std_thread.h -include HJM_type.h \
  -include HJM.h -include resource.h -include nr_routines.h -lpthread
