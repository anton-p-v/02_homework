# 02_homework


build:
```
bazel build --cxxopt=-std=c++14 //src:ip_filter --define VERSION=1
```

run:
```
cat src/test-data.tsv | bazel-bin/src/ip_filter
```

build deb package:
```
bazel build --cxxopt=-std=c++14 //src:ip_filter_deb --define VERSION=1
```
