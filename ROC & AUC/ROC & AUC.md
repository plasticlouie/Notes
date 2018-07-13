# ROC (Receiver Operating Characteristic) Curve

## TPR(True positive rate) & FPR(False p)

![precision_recall](./pics/precision_recall.png)
![precision_recall](https://github.com/plasticlouie/Notes/blob/master/ROC%20%26%20AUC/pics/precision_recall.png)


<img src="http://7xqoji.com1.z0.glb.clouddn.com/mytest.jpg" width="500" hegiht="313" align=center />

<img src="https://github.com/plasticlouie/Notes/blob/master/ROC%20%26%20AUC/pics/precision_recall.png"/>
<img src="https://github.com/plasticlouie/Notes/blob/master/ROC%20%26%20AUC/pics/precision_recall.png"/>

```
P: Positives
N: Negatives
TP: True Positives
FN: False Negatives
FP: False Positives
TN: True Negatives

           label
           P   N
--------------------
pred |P  | TP  FP      
     |N  | FN  TN
--------------------

TPR(True positive rate) or Recall:
  TPR = TP/P = TP/(TP+FN)

FPR(False positive rate):
  FPR = FP/N = FP/(FP+TN)

```

## ROC curve

A classifier predicts a score vector ```scores``` for given data samples. Each element of ```scores``` corresponds to a data sample.

For examples, given 4 data samples:
```
scores = [0.1, 0.5, 0.3, 0.8]
labels = [0, ,   1,   0,   1]
```
We choose each element in the score vector as the score threshold, then compute the ```FPR``` and ```TPR```
```
threshold   predictions   labels        FPR   TPR
   0.1     [1, 1, 1, 1]  [0, 1, 0, 1]    1.0   1.0
   0.3     [0, 1, 1, 1]  [0, 1, 0, 1]    0.5   1.0
   0.5     [0, 1, 0, 1]  [0, 1, 0, 1]    0.0   1.0
   0.8     [0, 0, 0, 1]  [0, 1, 0, 1]    0.0   0.5
```
Sort ```FPR``` in ascending order, then set ```FPR``` as x axis and ```TPR``` as y axis.






Given several data samples, a classifiers predicts
