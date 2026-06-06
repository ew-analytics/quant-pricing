# quant-pricing

C++ and Python pricing library — rates, FX, equity derivatives.

## Stack
- C++20 · QuantLib 1.42.1 · Eigen · Boost
- Python 3.12 · QuantLib-Python · NumPy · SciPy · JAX
- GoogleTest · GitHub Actions CI/CD

## Build (macOS)
```bash
cmake -B build -G Ninja -DCMAKE_CXX_COMPILER=clang++
cmake --build build
cd build && ctest
```

## Build (Linux)
```bash
make build-linux
make test-linux
```
