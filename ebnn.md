# Evaluation

## Training under Py Env:
`python3 examples/simple.py`

## Compile:
`gcc simple_mnist.c`

and

`gcc simple_cifar10.c`

## Play
```
bash ./a.out

actual: 5 <> predicted: 3
actual: 0 == predicted: 0
actual: 4 == predicted: 4
actual: 1 == predicted: 1
actual: 9 == predicted: 9
actual: 2 == predicted: 2
actual: 1 == predicted: 1
actual: 3 == predicted: 3
actual: 1 == predicted: 1
actual: 4 == predicted: 4
actual: 3 == predicted: 3
actual: 5 == predicted: 5
actual: 3 == predicted: 3
actual: 6 == predicted: 6
actual: 1 == predicted: 1
actual: 7 <> predicted: 9
actual: 2 == predicted: 2
actual: 8 == predicted: 8
actual: 6 <> predicted: 5
actual: 9 == predicted: 9
```

## Evaluate Time:
`time for run in {1..1000}; do ./a.out; done`

## Results

1000 Times of running ./a.out (MNIST)

| Env  | 3.5 GHz Intel Core i7 | Core m3 | Raspberry Pi 3 Model b+ |
|------|-----------------------|---------|-------------------------|
| Time | 10.277s               | 22.904s | 32.168s                 |

1000 Times of running ./a.out (CIFAR-10)

| Env  | 3.5 GHz Intel Core i7 | Core m3 | Raspberry Pi 3 Model b+ |
|------|-----------------------|---------|-------------------------|
| Time | 29.097s               | 44.090s | 61.021s                 |

# Theory

We study embedded Binarized Neural Networks (eBNNs) with the aim of allowing current binarized neural networks (BNNs) in the literature to perform feedforward inference efficiently on small embedded devices. We focus on minimizing the required memory footprint, given that these devices often have memory as small as tens of kilobytes (KB). Beyond minimizing the memory required to store weights, as in a BNN, we show that it is essential to minimize the memory used for temporaries which hold intermediate results between layers in feedforward inference. To accomplish this, eBNN reorders the computation of inference while preserving the original BNN structure, and uses just a single floating-point temporary for the entire neural network. All intermediate results from a layer are stored as binary values, as opposed to floating-points used in current BNN implementations, leading to a 32x reduction in required temporary space. We provide empirical evidence that our proposed eBNN approach allows efficient inference (10s of ms) on devices with severely limited memory (10s of KB). For example, eBNN achieves 95\% accuracy on the MNIST dataset running on an Intel Curie with only 15 KB of usable memory with an inference runtime of under 50 ms per sample. To ease the development of applications in embedded contexts, we make our source code available that allows users to train and discover eBNN models for a learning task at hand, which fit within the memory constraint of the target device.
