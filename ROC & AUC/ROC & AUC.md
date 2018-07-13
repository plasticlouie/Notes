# ROC (Receiver Operating Characteristic) Curve

## TPR(True positive rate) & FPR(False p)

<img src="http://7xqoji.com1.z0.glb.clouddn.com/mytest.jpg" width="500" hegiht="313" align=center />

<img src="./pics/precision_recall.png"/>

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

TPR(True positive rate):
  TPR = TP/P = TP/(TP+FN)

FPR(False positive rate):
  FPR = FP/N = FP/(FP+TN)

```

## ROC curve

Given several data samples, a classifiers predicts 
