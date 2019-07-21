gcc -o main main.c dummy_func.c cui_showswlaparam.c -fmax-errors=10 -w -lpthread -DLINUX -fprofile-arcs -ftest-coverage
lcov --capture --directory ./ --output-file coverage.info
genhtml coverage.info --output-directory output_coverage