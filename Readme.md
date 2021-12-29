# Get Libuv
```shell
git clone https://github.com/libuv/libuv.git

```

# Install Libuv

## On linux
```shell
cd libuv
mkdir build
cd build
cmake ..
make -j $(nproc)
sudo make install
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
```shell
export libuv_DIR=/home/jcq/libuv_qnx
cmake -DCMAKE_C_COMPILER=/home/jcq/workspace/qnx710/host/linux/x86_64/usr/bin/qcc -DCMAKE_CXX_COMPILER=/home/jcq/workspace/qnx710/host/linux/x86_64/usr/bin/q++ ..
make -j $(nproc)
```
