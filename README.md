# Benchmark of Binary Neural Network

## Repositories

### Training Deep Neural Networks with Weights and Activations Constrained to +1 or -1
MatthieuCourbariaux/BinaryNet 

https://github.com/MatthieuCourbariaux/BinaryNet

### Header-only C library for Binary Neural Network Feedforward Inference (targeting small devices)
Embedded Binarized Neural Networks

We study embedded Binarized Neural Networks (eBNNs) with the aim of allowing current binarized neural networks (BNNs) in the literature to perform feedforward inference efficiently on small embedded devices. We focus on minimizing the required memory footprint, given that these devices often have memory as small as tens of kilobytes (KB). Beyond minimizing the memory required to store weights, as in a BNN, we show that it is essential to minimize the memory used for temporaries which hold intermediate results between layers in feedforward inference. To accomplish this, eBNN reorders the computation of inference while preserving the original BNN structure, and uses just a single floating-point temporary for the entire neural network. All intermediate results from a layer are stored as binary values, as opposed to floating-points used in current BNN implementations, leading to a 32x reduction in required temporary space. We provide empirical evidence that our proposed eBNN approach allows efficient inference (10s of ms) on devices with severely limited memory (10s of KB). For example, eBNN achieves 95% accuracy on the MNIST dataset running on an Intel Curie with only 15 KB of usable memory with an inference runtime of under 50 ms per sample.

https://github.com/kunglab/ebnn

### ImageNet classification using binary Convolutional Neural Networks
This is the Torch 7.0 implementation of XNOR-Net: ImageNet Classification Using Binary Convolutional Neural Networks.

https://github.com/allenai/XNOR-Net

### Deep Networks on classification tasks using Torch
This is a complete training example for BinaryNets using Binary-Backpropagation algorithm as explained in "Binarized Neural Networks: Training Deep Neural Networks with Weights and Activations Constrained to +1 or -1, Matthieu Courbariaux, Itay Hubara, Daniel Soudry, Ran El-Yaniv, Yoshua Bengio' on following datasets: Cifar10/100, SVHN, MNIST

https://github.com/itayhubara/BinaryNet

### Binarized Neural Network (BNN) for pytorch

Binarized Neural Network (BNN) for pytorch This is the pytorch version for the BNN code, fro VGG and resnet models Link to the paper: https://papers.nips.cc/paper/6573-binarized-neural-networks

The code is based on https://github.com/eladhoffer/convNet.pytorch Please install torch and torchvision by following the instructions at: http://pytorch.org/ To run resnet18 for cifar10 dataset use: python main_binary.py --model resnet_binary --save resnet18_binary --dataset cifar10

https://github.com/itayhubara/BinaryNet.pytorch

### binary weight neural network implementation on tensorflow
[BinaryNet: Training Deep Neural Networks with Weights and Activations Constrained to +1 or -1"](http://arxiv.org/abs/1602.02830),
Matthieu Courbariaux, Yoshua Bengio

https://github.com/uranusx86/BinaryNet-on-tensorflow

### Local Binary Convolutional Neural Networks (LBCNN)
We propose local binary convolution (LBC), an efficient alternative to convolutional layers in standard convolutional neural networks (CNN). The design principles of LBC are motivated by local binary patterns (LBP). The LBC layer comprises of a set of fixed sparse pre-defined binary convolutional filters that are not updated during the training process, a non-linear activation function and a set of learnable linear weights. The linear weights combine the activated filter responses to approximate the corresponding activated filter responses of a standard convolutional layer. The LBC layer affords significant parameter savings, 9x to 169x in the number of learnable parameters compared to a standard convolutional layer. Furthermore, the sparse and binary nature of the weights also results in up to 9x to 169x savings in model size compared to a standard convolutional layer. We demonstrate both theoretically and experimentally that our local binary convolution layer is a good approximation of a standard convolutional layer. Empirically, CNNs with LBC layers, called local binary convolutional neural networks (LBCNN), achieves performance parity with regular CNNs on a range of visual datasets (MNIST, SVHN, CIFAR-10, and ImageNet) while enjoying significant computational savings.

https://github.com/juefeix/lbcnn.torch

### BMXNet v2: An Open-Source Binary Neural Network Implementation Based on MXNet
A fork of the deep learning framework mxnet to study and implement quantization and binarization in neural networks.

This project is based on the first version of BMXNet, but is different in that it reuses more of the original MXNet operators. This aim was to have only minimal changes to C++ code to get better maintainability with future versions of mxnet.

https://github.com/hpi-xnor/BMXNet-v2
