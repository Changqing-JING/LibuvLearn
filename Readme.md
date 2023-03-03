# Get Libuv
```shell
git clone https://github.com/libuv/libuv.git

```

# Install Libuv

## On Ubuntu
```shell
cd libuv
mkdir build
cd build
cmake ..
make -j $(nproc)
sudo make install
```
## On Macos
```shell
cd libuv
mkdir build
cd build
cmake ..
make -j $(nproc)
make install
```
## On windows
```shell
cd libuv
mkdir build_win
cd build_win
cmake -DCMAKE_BUILD_TYPE=DEBUG -DCMAKE_INSTALL_PREFIX=D:\libuv_x86  -A x64 ..
cmake --build .
cmake --install . --config Debug
```
add environment vairalbe key: libuv_DIR, value: D:\libuv_x86

Note: For release build, the "Debug" need to be replaced by "Release"

## Cross Compile for QNX on Linux
```shell
cd libuv
mkdir build_qnx
cmake -DCMAKE_INSTALL_PREFIX=/home/username/libuv_qnx -DCMAKE_TOOLCHAIN_FILE=/path_to_current_project/qnx.cmake ..
#or
cmake -DCMAKE_INSTALL_PREFIX=/home/username/libuv_qnx -DCMAKE_SYSTEM_NAME=QNX -DCMAKE_CXX_FLAGS="-D_QNX_SOURCE=1" ..
make -j $(nproc)
make install
```

### Build app on qnx
With pre installed libuv
```shell
export libuv_DIR=/home/jcq/libuv_qnx
cmake -DUSE_PRE_INSTALLED_LIBUV=1 -DCMAKE_C_COMPILER=qcc -DCMAKE_CXX_COMPILER=q++ ..
make -j $(nproc)
```
Without pre installed libuv
```shell
cmake -DCMAKE_TOOLCHAIN_FILE=../qnx.cmake -DCMAKE_C_COMPILER=qcc -DCMAKE_CXX_COMPILER=q++ ..
make -j $(nproc)
```

## Read imported symbols
```shell
objdump -T ./build/LibuvLearn
```

## Analyze call graph
### Install radare2
```shell
git clone https://github.com/radareorg/radare2
radare2/sys/install.sh
```
### Create call graph
```shell
cd build
radare2 -A -c 'agCd > ./b.dot' -q ./LibuvLearn
```
### Review Call graph
Use xdot
```shell
xdot ./b.dot
```

Convert to SVG
```shell
dot -Tsvg b.dot -o b.svg
```
