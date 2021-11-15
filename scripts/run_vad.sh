#!/bin/bash

# Be sure that this file has execution permissions:
# Use the nautilus explorer or chmod +x run_vad.sh
for num_init in 11; do
for num_ms in 12; do 
for num_mv in 5; do  
for alpha_uno in 2; do
for alpha_dos in 7.3; do
# Write here the name and path of your program and database
DIR_P2=$HOME/PAV/P2
DB=$DIR_P2/db.v4
CMD="$DIR_P2/bin/vad -N $num_init -s $num_ms -m $num_mv -a $alpha_uno -b $alpha_dos"

echo Parametros: Number init: $num_init, Number MS: $num_ms, Number MV: $num_mv, Alpha1: $alpha_uno, Alpha2: $alpha_dos

for filewav in $DB/*/*wav; do
#    echo
    echo "**************** $filewav ****************"
    if [[ ! -f $filewav ]]; then 
	    echo "Wav file not found: $filewav" >&2
	    exit 1
    fi

    filevad=${filewav/.wav/.vad}

    $CMD -i $filewav -o $filevad || exit 1

# Alternatively, uncomment to create output wave files
#    filewavOut=${filewav/.wav/.vad.wav}
#    $CMD $filewav $filevad $filewavOut || exit 1

done

scripts/vad_evaluation.pl $DB/*/*lab
done
done
done
done
done
exit 0
