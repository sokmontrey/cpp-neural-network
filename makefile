all:
	cls && cd build && cmake --build . && .\test\Debug\gamma_net_test.exe
