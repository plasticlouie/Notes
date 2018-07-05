#Install packages using pip offline#

deerx@deerx-server:~$ pip download tensorflow-gpu==1.3
Collecting tensorflow-gpu==1.3
  Using cached https://files.pythonhosted.org/packages/ca/c4/e39443dcdb80631a86c265fb07317e2c7ea5defe73cb531b7cd94692f8f5/tensorflow_gpu-1.3.0-cp27-cp27mu-manylinux1_x86_64.whl
  Saved ./tensorflow_gpu-1.3.0-cp27-cp27mu-manylinux1_x86_64.whl
Collecting six>=1.10.0 (from tensorflow-gpu==1.3)
  Downloading https://files.pythonhosted.org/packages/67/4b/141a581104b1f6397bfa78ac9d43d8ad29a7ca43ea90a2d863fe3056e86a/six-1.11.0-py2.py3-none-any.whl
  Saved ./six-1.11.0-py2.py3-none-any.whl
Collecting protobuf>=3.3.0 (from tensorflow-gpu==1.3)
  Downloading https://files.pythonhosted.org/packages/27/e7/bf96130ebe633b08a3913da4bb25e50dac5779f1f68e51c99485423f7443/protobuf-3.6.0-cp27-cp27mu-manylinux1_x86_64.whl (7.1MB)
    100% |████████████████████████████████| 7.1MB 4.0MB/s
  Saved ./protobuf-3.6.0-cp27-cp27mu-manylinux1_x86_64.whl
Collecting wheel (from tensorflow-gpu==1.3)
  Downloading https://files.pythonhosted.org/packages/81/30/e935244ca6165187ae8be876b6316ae201b71485538ffac1d718843025a9/wheel-0.31.1-py2.py3-none-any.whl (41kB)
    100% |████████████████████████████████| 51kB 8.2MB/s
  Saved ./wheel-0.31.1-py2.py3-none-any.whl
Collecting backports.weakref>=1.0rc1 (from tensorflow-gpu==1.3)
  Downloading https://files.pythonhosted.org/packages/88/ec/f598b633c3d5ffe267aaada57d961c94fdfa183c5c3ebda2b6d151943db6/backports.weakref-1.0.post1-py2.py3-none-any.whl
  Saved ./backports.weakref-1.0.post1-py2.py3-none-any.whl
Collecting numpy>=1.11.0 (from tensorflow-gpu==1.3)
  Downloading https://files.pythonhosted.org/packages/6a/a9/c01a2d5f7b045f508c8cefef3b079fe8c413d05498ca0ae877cffa230564/numpy-1.14.5-cp27-cp27mu-manylinux1_x86_64.whl (12.1MB)
    100% |████████████████████████████████| 12.1MB 3.3MB/s
  Saved ./numpy-1.14.5-cp27-cp27mu-manylinux1_x86_64.whl
Collecting tensorflow-tensorboard<0.2.0,>=0.1.0 (from tensorflow-gpu==1.3)
  Using cached https://files.pythonhosted.org/packages/fb/34/14c23665a725c73932891e09b8f017a53aad545c9d5019d2817102dc5d9b/tensorflow_tensorboard-0.1.8-py2-none-any.whl
  Saved ./tensorflow_tensorboard-0.1.8-py2-none-any.whl
Collecting mock>=2.0.0 (from tensorflow-gpu==1.3)
  Downloading https://files.pythonhosted.org/packages/e6/35/f187bdf23be87092bd0f1200d43d23076cee4d0dec109f195173fd3ebc79/mock-2.0.0-py2.py3-none-any.whl (56kB)
    100% |████████████████████████████████| 61kB 6.0MB/s
  Saved ./mock-2.0.0-py2.py3-none-any.whl
Collecting setuptools (from protobuf>=3.3.0->tensorflow-gpu==1.3)
  Downloading https://files.pythonhosted.org/packages/7f/e1/820d941153923aac1d49d7fc37e17b6e73bfbd2904959fffbad77900cf92/setuptools-39.2.0-py2.py3-none-any.whl (567kB)
    100% |████████████████████████████████| 573kB 3.5MB/s
  Saved ./setuptools-39.2.0-py2.py3-none-any.whl
Collecting werkzeug>=0.11.10 (from tensorflow-tensorboard<0.2.0,>=0.1.0->tensorflow-gpu==1.3)
  Downloading https://files.pythonhosted.org/packages/20/c4/12e3e56473e52375aa29c4764e70d1b8f3efa6682bef8d0aae04fe335243/Werkzeug-0.14.1-py2.py3-none-any.whl (322kB)
    100% |████████████████████████████████| 327kB 5.9MB/s
  Saved ./Werkzeug-0.14.1-py2.py3-none-any.whl
Collecting html5lib==0.9999999 (from tensorflow-tensorboard<0.2.0,>=0.1.0->tensorflow-gpu==1.3)
  Downloading https://files.pythonhosted.org/packages/ae/ae/bcb60402c60932b32dfaf19bb53870b29eda2cd17551ba5639219fb5ebf9/html5lib-0.9999999.tar.gz (889kB)
    100% |████████████████████████████████| 890kB 6.1MB/s
  Saved ./html5lib-0.9999999.tar.gz
Collecting markdown>=2.6.8 (from tensorflow-tensorboard<0.2.0,>=0.1.0->tensorflow-gpu==1.3)
  Downloading https://files.pythonhosted.org/packages/6d/7d/488b90f470b96531a3f5788cf12a93332f543dbab13c423a5e7ce96a0493/Markdown-2.6.11-py2.py3-none-any.whl (78kB)
    100% |████████████████████████████████| 81kB 5.8MB/s
  Saved ./Markdown-2.6.11-py2.py3-none-any.whl
Collecting bleach==1.5.0 (from tensorflow-tensorboard<0.2.0,>=0.1.0->tensorflow-gpu==1.3)
  Downloading https://files.pythonhosted.org/packages/33/70/86c5fec937ea4964184d4d6c4f0b9551564f821e1c3575907639036d9b90/bleach-1.5.0-py2.py3-none-any.whl
  Saved ./bleach-1.5.0-py2.py3-none-any.whl
Collecting funcsigs>=1; python_version < "3.3" (from mock>=2.0.0->tensorflow-gpu==1.3)
  Downloading https://files.pythonhosted.org/packages/69/cb/f5be453359271714c01b9bd06126eaf2e368f1fddfff30818754b5ac2328/funcsigs-1.0.2-py2.py3-none-any.whl
  Saved ./funcsigs-1.0.2-py2.py3-none-any.whl
Collecting pbr>=0.11 (from mock>=2.0.0->tensorflow-gpu==1.3)
  Downloading https://files.pythonhosted.org/packages/b3/5d/c196041ffdf3e34ba206db6d61d1f893a75e1f3435699ade9bd65e089a3d/pbr-4.0.4-py2.py3-none-any.whl (98kB)
    100% |████████████████████████████████| 102kB 6.0MB/s
  Saved ./pbr-4.0.4-py2.py3-none-any.whl
Successfully downloaded tensorflow-gpu six protobuf wheel backports.weakref numpy tensorflow-tensorboard mock setuptools werkzeug html5lib markdown bleach funcsigs pbr
