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
