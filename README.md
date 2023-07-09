# 01_homework


build:
```
bazel build --cxxopt=-std=c++14 //src:helloworld_cli --define VERSION=1
```


build deb package:
```
bazel build --cxxopt=-std=c++14 //src:helloworld_cli_deb --define VERSION=1
```


run version tests:
```
bazel test --cxxopt=-std=c++14 --test_output=all //src:version_test --define VERSION=1
```
