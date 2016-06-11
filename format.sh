cp $1 $1.tmp
clang-format38 $1.tmp > $1
rm $1.tmp
