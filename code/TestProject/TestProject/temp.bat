@echo off

for %%c in (*.h) do (
clang-format -i %%c
echo %%c
)

pause > nul