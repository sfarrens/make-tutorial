g++ -c ../make-part1/src/sphere_trig.cpp
g++ -c ../make-part1/src/print.cpp
ar rcs lib/libsphere.a sphere_trig.o print.o
rm sphere_trig.o print.o
ln -s $PWD/lib/libsphere.a ../cmake-part3/lib/libsphere.a
ln -s $PWD/lib/libsphere.a ../cmake-part5/lib/libsphere.a
