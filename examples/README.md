#Set up the environment
```bash setEnv.sh```

#Run hifsuite
```bash run_hifsuite.sh```

This will generate the "injected" directory.

To simulate, you need to:
- Copy the "complete" directory and substitue the relevant files with those in the "injected" directory.
- Modify the CMakeLists.txt file to include the new files.
- Modify the main.cpp file to include the new files and to implement the simulation logic
- Run the following commands to compile the code:

```mkdir build```
```cd build```
```cmake ..```
```make```
