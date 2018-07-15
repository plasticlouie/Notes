# Batch normalization

## 特征归一化(feature normalization)

在数据的特征之间取值相差特别大的情况下，神经网络的收敛速度较慢。因为loss曲面的等高线比较扁平，梯度所指的方向不是loss最低的方向，loss下降的过程会曲曲折折。并且learning rate不能取很大，因为对于比较扁平的那一维来说很容易震荡。这就导致了在某个学习速率下，可能扁平的那一维震荡严重，但修长的那一维向最优点靠拢的速度又很慢。而特征归一化之后，loss曲面的等高线为一个圆形，可以取较大的学习速率，并且梯度的方向也是loss最低的方向。

（待补充）
比如通过变量房间数```x1```和变量面积```x2```预测房价```y```。面积的取值一般比房间数大，

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
BN(z) = gamma * [(z-z_mean) / sqrt(z_var^2)] + beta
y = f(BN(z))
```

Batch norm理论上会作用于每一个特征维度，比如一个fc层的输出值为```x (batch, 256)```
那么对于这个fc层
```
x_mean = tf.reduce_mean(x, axis=0) # x_mean: (256,)
x_std = tf.reduce_std(x, axis=0) # x_std: (256,)
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

## Training & Inferencing

Batch normalization在训练时，每次输入一个batch都可以计算出mean和std，测试时使用的mean和std可以通过两种方法计算：

方法1
```
# Moving average：
# x_mean为用于测试的mean，current_mean为当前batch计算出的mean
x_mean = 0.99*x_mean + 0.01*current_mean
x_std = 0.99*x_std + 0.01*current_std
```

方法2
```
# 用所有batch估计测试时的mean和var
x_mean = 1/m * sum(mean1, mean2,... ,meann)
x_var = 1/(m-1) * sum(var1, var2,..., varn)
```

## 补充

在CNN中，batch norm作用在三个维度(batch, h, w)而不是只作用在batch维上。原因是希望batch norm也遵从conv的原则，对每个location进行相同的操作。

另外，如果只作用在batch维上，会导致需要保存大量参数，比如mean和std的size都为(1, h, w, channel)
