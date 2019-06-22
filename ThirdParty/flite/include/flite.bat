gcc -Wall -g -o flite_test flite_test.c -I$FLITEDIR/include -L$FLITEDIR/lib 
    -lflite_cmu_us_kal -lflite_usenglish -lflite_cmulex -lflite -lm