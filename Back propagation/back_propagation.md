# Back propagation

## loss对权值的梯度

记<a href="https://www.codecogs.com/eqnedit.php?latex=$W_{ji}^l$" target="_blank"><img src="https://latex.codecogs.com/gif.latex?$W_{ji}^l$" title="$W_{ji}^l$" /></a>为连接```l```层```i```神经元和```l+1```层```j```神经元的权值

记<a href="https://www.codecogs.com/eqnedit.php?latex=$a_{i}^l$" target="_blank"><img src="https://latex.codecogs.com/gif.latex?$a_{i}^l$" title="$a_{i}^l$" /></a>为```l```层```i```神经元的激活值。<a href="https://www.codecogs.com/eqnedit.php?latex=$z_{i}^l$" target="_blank"><img src="https://latex.codecogs.com/gif.latex?$z_{i}^l$" title="$z_{i}^l$" /></a>为未激活的值，```a=f(z)```。记loss为```J```

```
aj
@ @ @ @  (layer l+1)
 \Wji
@ @ @ @  (layer l)
 ai
```

首先，第```l+1```层的第```j```个神经元：


loss对权值的偏导数为：

<a href="https://www.codecogs.com/eqnedit.php?latex=$$\frac{\partial&space;J}{\partial&space;W_{ji}^l}=\frac{\partial&space;J}{\partial&space;z^{l&plus;1}_j}\frac{\partial&space;z^{l&plus;1}_j}{\partial&space;W_{ji}^l}$$" target="_blank"><img src="https://latex.codecogs.com/gif.latex?$$\frac{\partial&space;J}{\partial&space;W_{ji}^l}=\frac{\partial&space;J}{\partial&space;z^{l&plus;1}_j}\frac{\partial&space;z^{l&plus;1}_j}{\partial&space;W_{ji}^l}$$" title="$$\frac{\partial J}{\partial W_{ji}^l}=\frac{\partial J}{\partial z^{l+1}_j}\frac{\partial z^{l+1}_j}{\partial W_{ji}^l}$$" /></a>

因为：

<a href="https://www.codecogs.com/eqnedit.php?latex=$$z_{j}^{l&plus;1}=\sum\limits_{i}(W_{ji}^la_i^l)$$" target="_blank"><img src="https://latex.codecogs.com/gif.latex?$$z_{j}^{l&plus;1}=\sum\limits_{i}(W_{ji}^la_i^l)$$" title="$$z_{j}^{l+1}=\sum\limits_{i}(W_{ji}^la_i^l)$$" /></a>

所以

<a href="https://www.codecogs.com/eqnedit.php?latex=$$\frac{\partial&space;J}{\partial&space;W_{ji}^l}=\frac{\partial&space;J}{\partial&space;z^{l&plus;1}_j}a_i^{l}=\delta_j^{l&plus;1}a^{l}_i$$" target="_blank"><img src="https://latex.codecogs.com/gif.latex?$$\frac{\partial&space;J}{\partial&space;W_{ji}^l}=\frac{\partial&space;J}{\partial&space;z^{l&plus;1}_j}a_i^{l}=\delta_j^{l&plus;1}a^{l}_i$$" title="$$\frac{\partial J}{\partial W_{ji}^l}=\frac{\partial J}{\partial z^{l+1}_j}a_i^{l}=\delta_j^{l+1}a^{l}_i$$" /></a>

上式中的```delta```称为残差：

<a href="https://www.codecogs.com/eqnedit.php?latex=$$\delta_j^{l&plus;1}=\frac{\partial&space;J}{\partial&space;z^{l&plus;1}_j}$$" target="_blank"><img src="https://latex.codecogs.com/gif.latex?$$\delta_j^{l&plus;1}=\frac{\partial&space;J}{\partial&space;z^{l&plus;1}_j}$$" title="$$\delta_j^{l+1}=\frac{\partial J}{\partial z^{l+1}_j}$$" /></a>

## 残差

```
dj
@  @  @  (layer l+1)
| / ...
@  @  @  (layer l)
di
```

残差有逐层递推公式：

<a href="https://www.codecogs.com/eqnedit.php?latex=$$\delta_i^l=\frac{\partial&space;J}{\partial&space;z_i^l}=\sum\limits_j(\frac{\partial&space;J}{\partial&space;z_j^{l&plus;1}}\frac{\partial&space;z_j^{l&plus;1}}{\partial&space;z_i^l})\\&space;\because&space;z_j^{l&plus;1}=\sum\limits_i[W_{ji}^lf(z_i^l)]\\&space;\therefore&space;\delta_i^l=\sum\limits_j[\frac{\partial&space;J}{\partial&space;z_j^{l&plus;1}}W_{ji}^lf'(z_i^l)]\\=f'(z_i^l)\sum\limits_j[\delta_j^{l&plus;1}W_{ji}^l]$$" target="_blank"><img src="https://latex.codecogs.com/gif.latex?$$\delta_i^l=\frac{\partial&space;J}{\partial&space;z_i^l}=\sum\limits_j(\frac{\partial&space;J}{\partial&space;z_j^{l&plus;1}}\frac{\partial&space;z_j^{l&plus;1}}{\partial&space;z_i^l})\\&space;\because&space;z_j^{l&plus;1}=\sum\limits_i[W_{ji}^lf(z_i^l)]\\&space;\therefore&space;\delta_i^l=\sum\limits_j[\frac{\partial&space;J}{\partial&space;z_j^{l&plus;1}}W_{ji}^lf'(z_i^l)]\\=f'(z_i^l)\sum\limits_j[\delta_j^{l&plus;1}W_{ji}^l]$$" title="$$\delta_i^l=\frac{\partial J}{\partial z_i^l}=\sum\limits_j(\frac{\partial J}{\partial z_j^{l+1}}\frac{\partial z_j^{l+1}}{\partial z_i^l})\\ \because z_j^{l+1}=\sum\limits_i[W_{ji}^lf(z_i^l)]\\ \therefore \delta_i^l=\sum\limits_j[\frac{\partial J}{\partial z_j^{l+1}}W_{ji}^lf'(z_i^l)]\\=f'(z_i^l)\sum\limits_j[\delta_j^{l+1}W_{ji}^l]$$" /></a>

<a href="https://www.codecogs.com/eqnedit.php?latex=$W_{ij}$" target="_blank"><img src="https://latex.codecogs.com/gif.latex?$W_{ij}$" title="$W_{ij}$" /></a>
