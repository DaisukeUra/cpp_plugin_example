# 目的

gazeboのプラグインがどうやってロードされてるのか知りたかった．

# 使い方

```sh
mkdir build
cd build
cmake ..
make
./plugin_test plugin_a.dylib
./plugin_test plugin_b.dylib
./plugin_test plugin_evil.dylib
```

とか．
linuxなら `.dylib` -> `.so` かも
