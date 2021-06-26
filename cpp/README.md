# To generate build files (and add LSP server support)

```bash
mkdir build
cd build
# skip compile commands if LSP support not needed
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -G "Unix Makefiles" ../accelerated-cpp
cmake --build .
# skip symlink if LSP support not needed
ln -s compile_commands.json ../accelerated-cpp/compile_commands.json
```
