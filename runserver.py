# Source: https://github.com/Xilinx/ml-suite/blob/master/examples/caffe/REST/app.py

from __future__ import print_function

import argparse

import flask

app = flask.Flask(__name__)


@app.route("/predict", methods=["POST"])
def predict():
    data = {"success": False}

    global prototxt
    global model
    global synset_words

    if flask.request.method == "POST":
        image = flask.request.files["image"]
        print(image)
        response = None  # InferImage(net, image, synset_words)
        data["success"] = True
        data["response"] = response
    return flask.jsonify(data)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='pyXFDNN')
    parser.add_argument('--caffemodel', default="/opt/models/caffe/bvlc_googlenet/bvlc_googlenet.caffemodel",
                        help='path to caffemodel file eg: /opt/models/caffe/bvlc_googlenet/bvlc_googlenet.caffemodel')
    parser.add_argument('--prototxt', default="xfdnn_auto_cut_deploy.prototxt",
                        help='path to  prototxt file eg: xfdnn_auto_cut_deploy.prototxt')
    parser.add_argument('--synset_words', default="$HOME/CK-TOOLS/dataset-imagenet-ilsvrc2012-aux/synset_words.txt",
                        help='path to synset_words eg: $HOME/CK-TOOLS/dataset-imagenet-ilsvrc2012-aux/synset_words.txt')
    parser.add_argument('--port', default=5000)

    args = vars(parser.parse_args())

    if args["caffemodel"]:
        model = args["caffemodel"]

    if args["prototxt"]:
        prototxt = args["prototxt"]

    if args["synset_words"]:
        synset_words = args["synset_words"]

    if args["port"]:
        port = args["port"]
    else:
        port = 9000

    print("Loading FPGA with image...")
    # net = LoadImage(prototxt, model, synset_words)

    print("Starting Flask Server...")
    app.run(port=port)
