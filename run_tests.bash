part=$1
test_=$2

./hw3 < hw3-tests/t$part.in 2>&1 > hw3-tests/t$part.res
echo "TEST $part$test_"
diff hw3-tests/t$part.res hw3-tests/t$part.out