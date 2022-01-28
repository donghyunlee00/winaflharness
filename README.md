# winaflharness

`newarc.ex/` works.

```sh
C:\Users\user\Desktop\tools\DynamoRIO-Windows-9.0.19012\bin32\drrun.exe -c "C:\Users\user\Desktop\tools\winafl\build32\bin\Release\winafl.dll" -debug -target_module WinRARHarness.exe -coverage_module UNACEV2.DLL -target_method fuzzme -fuzz_iterations 10 -nargs 1 -- "C:\Users\user\source\repos\WinRARHarness\Debug\WinRARHarness.exe" "C:\Users\user\Desktop\in\test.ace"
```

```sh
.\afl-fuzz.exe -i C:\Users\user\Desktop\in -o C:\Users\user\Desktop\out -t 10000 -D C:\Users\user\Desktop\tools\DynamoRIO-Windows-9.0.19012\bin32 -- -fuzz_iterations 5000 -coverage_module WinRARHarness.exe -coverage_module UNACEV2.DLL -target_module WinRARHarness.exe -target_method fuzzme -nargs 1 -- "C:\Users\user\source\repos\WinRARHarness\Debug\WinRARHarness.exe" "@@"
```
