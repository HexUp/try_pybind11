# try_pybind11

第一步，下载pybind11的源代码到step 1目录的extern下面，可以用下面的命令
```
# 假设你在 path/try_pybind11/step 1/ 这个文件夹下面
git clone https://github.com/pybind/pybind11.git extern/pybind11
```

第二步，运行cmake和make
```
mkdir build
cd build
cmake ..
make
```

第三步，在python中测试使用，进入build文件夹
```
python
import example
example.add(1,1)
```
