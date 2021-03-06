CCACHE=ccache
MXX=/usr/bin/clang
CC=/usr/bin/gcc
CXX=/usr/bin/gcc
AS=/usr/bin/gcc
MM=/usr/bin/clang

SH=/usr/bin/g++
LD=/usr/bin/g++
AR=/usr/bin/ar

lc_CXX=-fvisibility=hidden -O3 -std=c++11 -g -Wall -m64 -I/usr/local/include -I/usr/include
lc_LD=-s -fvisibility=hidden -m64 -L/usr/local/lib -L/usr/lib

default:  lc

all:  lc

.PHONY: default all  lc

lc: build/linux/x86_64/release/lc
build/linux/x86_64/release/lc: build/.objs/lc/linux/x86_64/release/./tests-main.cpp.o build/.objs/lc/linux/x86_64/release/./lc.cpp.o
	@echo linking.release lc
	@mkdir -p build/linux/x86_64/release
	@$(LD) -o build/linux/x86_64/release/lc build/.objs/lc/linux/x86_64/release/./tests-main.cpp.o build/.objs/lc/linux/x86_64/release/./lc.cpp.o $(lc_LD) > build/.build.log 2>&1

build/.objs/lc/linux/x86_64/release/./tests-main.cpp.o: tests-main.cpp
	@echo ccache compiling.release tests-main.cpp
	@mkdir -p build/.objs/lc/linux/x86_64/release/.
	@/usr/bin/$(CCACHE) $(CXX) -c $(lc_CXX) -o build/.objs/lc/linux/x86_64/release/./tests-main.cpp.o tests-main.cpp > build/.build.log 2>&1

build/.objs/lc/linux/x86_64/release/./lc.cpp.o: lc.cpp
	@echo ccache compiling.release lc.cpp
	@mkdir -p build/.objs/lc/linux/x86_64/release/.
	@/usr/bin/$(CCACHE) $(CXX) -c $(lc_CXX) -o build/.objs/lc/linux/x86_64/release/./lc.cpp.o lc.cpp > build/.build.log 2>&1

clean:  clean_lc

clean_lc: 
	@rm -f build/linux/x86_64/release/lc
	@rm -f build/.objs/lc/linux/x86_64/release/./tests-main.cpp.o
	@rm -f build/.objs/lc/linux/x86_64/release/./lc.cpp.o

