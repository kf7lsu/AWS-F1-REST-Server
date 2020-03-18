# C++ implementation of REST API client for Xilinx ML Suit

To run the server:

1. Add inbound rule for the port in AWS
2. Add port forwarding in the docker (add the `-p 5000:5000` in `docker_run.sh`)
3. Change `app.py` so that the application listen on `0.0.0.0` (change to `app.run('0.0.0.0', port=port)`

To run the client:

1. Install `libcurl`
2. Change the server address in `predict.c`
3. Run `compile.sh`
4. Run `a.out`
