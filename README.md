# CutefishOS KWin Plugins

## Dependencies

### OpenMandriva

```
sudo dnf install extra-cmake-modules lib64qt5core-devel lib64KF5Declarative-devel kconfig lib64kdecorations2-devel lib64qt5quickwidgets-devel kconfigwidgets kwin-devel kwindowsystem kwindowsystem-wayland kwindowsystem-x11
```

## Build

```
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr ..
make
sudo make install
```

## Install

```
sudo make install
```

## License

cutefish-kwin-plugins is licensed under GPLv3.
