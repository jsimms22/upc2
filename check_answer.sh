rm -f pgen_parallel_sorted.out
rm -f pgen_serial_sorted.out
cat pgen.out | sort > pgen_parrallel_sorted.out
cat serial.out | sort > pgen_serial_sorted.out
diff pgen_parallel_sorted.out pgen_serial_sorted.out | wc -l
