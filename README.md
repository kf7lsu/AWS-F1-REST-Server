# C++ implementation of REST API client for Xilinx ML Suit

To run the server:

1. Add inbound rule for the port in AWS
2. Add port forwarding in the docker (add the `-p 5000:5000` in `docker_run.sh`)
3. Change `app.py` so that the application listen on `0.0.0.0` (change to `app.run('0.0.0.0', port=port)`

To run the client:

1. Install `libcurl4-gnutls-dev`
2. Change the server address in `Config.cpp`
3. Run `make`
4. Run `main.out`

Example Output:

```
$ ./a.out
{"response":"---------- Prediction 1/1 for raw_input ----------\n0.9174 \"n02105855 Shetland sheepdog, Shetland sheep dog, Shetland\"\n0.0825 \"n02106030 collie\"\n0.0000 \"n02086910 papillon\"\n0.0000 \"n02112018 Pomeranian\"\n0.0000 \"n02106166 Border collie\"\n","success":true}
```
