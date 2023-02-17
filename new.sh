#! /bin/bash
root=`dirname $0`
cd $root
root=$PWD

if [ x$1 = x ]
then echo "Test number not given."
else
    mkdir -p $PWD/$1
    cp $PWD/main.cpp.template $PWD/$1/main.cpp
    ln -s $PWD/build.sh $PWD/debug_helper.h $PWD/$1/
fi
