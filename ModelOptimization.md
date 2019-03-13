## Low-Rank
## Pruning
## Quantization
## Knowledge Distillation
## Compact Network Design

# Low-Rank
## Previous low-rank based methods:

## SVD
### Zhang et al., “Accelerating Very Deep Convolutional Networks for Classification and Detection”. IEEE TPAMI 2016.


## CP decomposition
### Lebedev et al., “Speeding-up Convolutional Neural Networks Using Fine-tuned CP- Decomposition”. ICLR 2015.


## Tucker decomposition
### Kim et al., “Compression of Deep Convolutional Neural Networks for Fast and Low Power Mobile Applications”. ICLR 2016.


## Tensor Train Decomposition
### Novikov et al., “Tensorizing Neural Networks”. NIPS 2016.


## Block Term Decomposition
### Wang et al., “Accelerating Convolutional Neural Networks for Mobile Applications”. ACMMM 2016.

 

## Recent low-rank based methods:

## Tensor Ring (TR) factorizations
### Wang et al., “Wide Compression: Tensor Ring Nets”. CVPR2018


## Block Term Decomposition For RNN
### Ye et al., “Learning Compact Recurrent Neural Networks with Block-Term Tensor Decomposition ”. CVPR2018.


## Why low-rank is not popular anymore?

### Low-rank approximation is not efficient for those 1x1 convolutions
### 3x3 convolutions in bottleneck structure have less computation complexity
### Depthwise convolution or grouped 1x1 convolution is already quite fast.
