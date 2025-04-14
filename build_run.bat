@echo off
echo Compilando...
gcc main.c lexer\lexer.c parser\parser.c assembler\assembler.c neander\neander.c -o main.exe

if %ERRORLEVEL% neq 0 (
    echo Houve um erro na compilação.
    pause
    exit /b
)

echo Executando...
main.exe

echo.

pause
