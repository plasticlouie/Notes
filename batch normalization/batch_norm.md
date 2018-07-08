# Batch normalization

## Batch normalization in Fully Connected Neural Network
In fully connected neural network, ```x``` is the activations of the current layer, ```y``` is the activations of the next layer.

Without batch norm:
```
z = Wx + b
y = f(z)
```

With batch norm:

```
z = Wx + b
BN(z) = gamma * [(z-z_mean) / (z_var^2)] + beta
y = f(BN(z))
```

## Batch normalization in Convolutional Neural Network

In CNN, batch norm will be applied on all dimensions except the channel dimention.

For example. Given a feature map ```x``` with shape (batch, h, w, channel)
```
# x: previous layer, z: output of conv(x) before activation function
# z: a tensor with shape (batch, h, w, channel)
# z = slim.conv2d(x, channel, [3,3], activation_fn=None)
mean    = tf.reduce_mean(z, axis=[0,1,2])       # mean: (channel,)
std     = tf.reduce_std(z, axis=[0,1,2])        # std: (channel,)
z_hat   = (z-mean) / std                        # z_hat: (batch, h, w, channel)
z_norm  = gamma*z_hat + beta                    # z_norm: batch norm output
y       = tf.nn.relu(z)                         # ReLU activation
```
## A test code using tensorflow

```
import tensorflow as tf
slim = tf.contrib.slim
batch = 10
h = 64
w = 64
channel = 128
z = tf.placeholder(tf.float32, shape=(batch, h, w, channel))
y = slim.batch_norm(z, scale=True, activation_fn=tf.nn.relu)
variables = slim.get_variables_to_restore()
for v in variables:
    print v.name,v.get_shape()
```
outputs:
```
BatchNorm/gamma:0 (128,)
BatchNorm/beta:0 (128,)
BatchNorm/moving_mean:0 (128,)
BatchNorm/moving_variance:0 (128,)
```
The variables ```BatchNorm/moving_mean``` and ```BatchNorm/moving_variance``` are for test phase
