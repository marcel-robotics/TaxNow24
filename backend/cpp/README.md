# taxNow24 - C++

## Set up
Prepare environment on macOS.

Make sure you have CMake >= 3.21 installed.
### Install cmake
```bash
brew install cmake
```
### Install asio
```bash
brew install asio
```
### Build and install crow
cd outside this project and clone crow. 
```bash
git clone https://github.com/crowcpp/crow
cd crow
mkdir build && cd build
cmake ../
make all
make install
```
Crow headers are now installed to /usr/local/include/

## Build TaxNow24
```bash
mkdir build && cd build
cmake ../
make all
```
## Running tests
```bash
make test
```

## Running the service
To start the service locally at http://0.0.0.0:18080
```bash
./TaxNow24
```
