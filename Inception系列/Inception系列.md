# Inception系列

## Inception v1
两类结构：
```
  -----------------concat-----------------
  |             |            |            |
1x1 conv     3x3 conv    5x5 conv     3x3 pool    (a)
  |             |            |            |
  -----------------------------------------
                      |
                      x
```

**结构(a)：**
通过不同大小的kernel以及pooling获取不同receptive field size的特征

```
  -----------------concat-----------------
  |             |            |            |
  |          3x3 conv    5x5 conv     1x1 conv    (b)
1x1 conv     1x1 conv    1x1 conv     3x3 pool
  |             |            |            |
  -----------------------------------------
                      |
                      x
```

**结构(b)：**
在结构(a)的基础上，加入```1x1conv```进行dimension reduction

ILSVRC 2014: 6.67% top-5 error (7.32% for VGG)

Inception v1和VGG参数对比：

VGG最后的conv层参数有7x7x512x4096(1e8)，两个fc层一个是4096x4096(1.6e7)另一个是4096x1000(4e6)

Inception v1把7x7x1024的feature map做了global average pooling，之后加fc，参数数量为1024x1000(1e6)

## Inception v2 (Batch normalization)

a) 提出了batch normalization (见batch normalization单独的笔记)

b) 用两个3x3 conv代替5x5 conv

inception v2 block结构如下（用b-conv表示加了batch norm的卷积层）：
```
    ----------------------concat------------------------
    |                |                |                |
    |                |           [3x3 b-conv]          |
    |           [3x3 b-conv]     [3x3 b-conv]     [3x3 b-conv]    
[1x1 b-conv]    [1x1 b-conv]     [1x1 b-conv]     [3x3 pool]           
    |                |                |                |
    ---------------------------------------------------
                            |
                            x
```
其中，```[kxk b-conv]```结构如下
```
     output
       |
     [ReLU]
   [Batch norm]
    [kxk conv] (without activation)
       |
     input
```
注：batch norm作用在conv之后（without activation），ReLU之前
